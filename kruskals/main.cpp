#include <iostream>
using namespace std;

int find(int *P, int i) {
  if (P[i] == -1) {
    return i;
  }
  return P[i];
}

void heapify(int **arr, int i, int n) {
  int left = 2 * (i + 1) - 1;
  int right = 2 * (i + 1);
  int small = i;
  if (!(left >= n)) {
    if (arr[i][2] > arr[left][2]) {
      small = left;
    } else {
      small = i;
    }
  }

  if (!(right >= n)) {
    if (arr[small][2] > arr[right][2]) {
      small = right;
    }
  }

  if (i != small) {
    swap(arr[i], arr[small]);
    heapify(arr, small, n);
  }
}

void make_heap(int **arr, int n) {
  int a, b;
  for (int i = n / 2; i >= 0; i--) {
    heapify(arr, i, n);
  }
}

void union_(int *P, int u, int v) {
  P[u] = v;
  P[v] = u;
}

void kruskals(int **cost, int **E, int *P, int n, int c, int **t) {
  make_heap(E, c);
  int mincost = 0;
  int c_copy = c;
  int u, v, j, k, count = 0;
  for (int i = 0; i < c_copy - 1; i++) {
    u = E[0][0];
    v = E[0][1];
    swap(E[0], E[c - 1]);
    c--;
    heapify(E, 0, c);

    j = find(P, u);
    k = find(P, v);
    if (j != k) {
      mincost += cost[u][v];
      t[count][0] = u;
      t[count][1] = v;
      count++;
      if (count == 2 * (n - 1)) {
        return;
      }
      union_(P, u, v);
      for (int i = 0; i < n; i++) {
      }
    }
  }
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
      if (cost[i][j] != 0) {
        E[c][0] = i;
        E[c][1] = j;
        E[c][2] = cost[i][j];
        c++;
      }
    }
  }

  int *P = new int[n];
  for (int i = 0; i < n; i++) {
    P[i] = -1;
  }

  int **t = new int *[2 * (n - 1)];
  for (int i = 0; i < 2 * (n - 1); i++) {
    t[i] = new int[2];
  }

  kruskals(cost, E, P, n, c, t);

  for (int i = 0; i < 2 * (n - 1); i++) {
    cout << t[i][0] + 1 << " -> " << t[i][1] + 1 << "\n";
  }
  return 0;
}
