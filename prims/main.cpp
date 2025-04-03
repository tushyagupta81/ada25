#include <climits>
#include <iostream>
using namespace std;

int min_cost_edge(int **E, int n) {
  int min = INT_MAX, min_index;
  for (int i = 0; i < n * n; i++) {
    if (E[i][2] < min && E[i][2] != 0) {
      min = E[i][2];
      min_index = i;
    }
  }
  return min_index;
}

int get_near(int **cost, int n, int *near) {
  int min = INT_MAX;
  int min_index;
  for (int j = 0; j < n; j++) {
    if (near[j] == 0) {
      continue;
    }
    if (cost[j][near[j]] < min && cost[j][near[j]] != 0) {
      min = cost[j][near[j]];
      min_index = j;
    }
  }
  if (min == INT_MAX) {
    return -1;
  }
  return min_index;
}

int prims(int **E, int **cost, int n, int **t, int *near) {
  int min_edge = min_cost_edge(E, n);
  int k = E[min_edge][0];
  int l = E[min_edge][1];
  int mincost = 0;

  for (int i = 0; i < n; i++) {
    if (cost[i][k] > cost[i][l] || cost[i][k] == 0) {
      near[i] = l;
    } else {
      near[i] = k;
    }
  }
  near[l] = near[k] = 0;

  mincost += cost[k][l];

  t[0][0] = k;
  t[0][1] = l;

  int c = 1;
  int u;
  for (int i = 1; i < n - 1; i++) {
    u = get_near(cost, n, near);
    t[c][0] = u;
    t[c][1] = near[u];
    c++;
    if (c == n-1) {
      break;
    }
    mincost += cost[u][near[u]];
    near[u] = 0;

    for (int j = 0; j < n; j++) {
      if (near[j] == 0 || cost[u][j] == 0) {
        continue;
      }
      if (cost[j][near[j]] > cost[u][j] || cost[j][near[j]] == 0) {
        near[j] = u;
      }
    }
  }
  return mincost;
}

int main() {
  int n = 6;
  int **cost = new int *[n];
  for (int i = 0; i < n; i++) {
    cost[i] = new int[n];
  }

  int **E = new int *[n * n];
  for (int i = 0; i < n * n; i++) {
    E[i] = new int[3];
  }

  int matrix[6][6] = {
      {0, 10, 2, 0, 0, 2}, {10, 0, 0, 0, 9, 8}, {2, 0, 0, 5, 0, 1},
      {0, 0, 5, 0, 7, 6},  {0, 9, 0, 7, 0, 0},  {2, 8, 1, 6, 0, 0},
  };

  int c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cost[i][j] = matrix[i][j];
      E[c][0] = i;
      E[c][1] = j;
      E[c][2] = cost[i][j];
      c++;
    }
  }

  // int c = 0;
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     if (i == j) {
  //       cost[i][j] = 0;
  //     } else {
  //       if (rand() % 2 == 0 && c < n) {
  //         cost[i][j] = rand() % 100;
  //         E[c][0] = i;
  //         E[c][1] = j;
  //         E[c][2] = cost[i][j];
  //         c++;
  //       }
  //     }
  //   }
  // }

  int *near = new int[n];
  for (int i = 0; i < n; i++) {
    near[i] = 0;
  }

  int **t = new int *[n-1];
  for (int i = 0; i < n-1; i++) {
    t[i] = new int[2];
  }
  cout<<"Minimum cost = "<<prims(E, cost, n, t, near)<<"\n";

  for (int i = 0; i < n-1; i++) {
    cout << t[i][0] + 1 << " -> " << t[i][1] + 1 << "\n";
  }

  return 0;
}
