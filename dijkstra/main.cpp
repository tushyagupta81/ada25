#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

int find_min(int *a, bool *flag, int n) {
  int min = INT_MAX;
  int min_i;
  for (int i = 0; i < n; i++) {
    if (flag[i] == true) {
      continue;
    }
    if (min > a[i]) {
      min = a[i];
      min_i = i;
    }
  }
  return min_i;
}

void sssp(int v, int *dist, int **cost, int n) {
  bool *flag = new bool[n];
  for (int i = 0; i < n; i++) {
    dist[i] = cost[v][i];
    flag[i] = false;
  }

  flag[v] = true;

  for (int j = 0; j < n; j++) {
    v = find_min(cost[v], flag, n);
    flag[v] = true;
    for (int k = 0; k < n; k++) {
      if (flag[k] == true) {
        continue;
      }
      if (dist[v] != INT_MAX && cost[v][k] != INT_MAX &&
          dist[k] > dist[v] + cost[v][k]) {
        dist[k] = dist[v] + cost[v][k];
      }
    }
  }
}

int main() {
  int n = 9;
  int **adjency_matrix = new int *[n];
  int *dist = new int[n];
  for (int i = 0; i < n; i++) {
    adjency_matrix[i] = new int[n];
    dist[i] = INT_MAX;
  }
  srand(time(NULL));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        adjency_matrix[i][j] = 0;
      } else {
        if (rand() % 2 == 0) {
          adjency_matrix[i][j] = rand() % 99 + 1;
        } else {
          adjency_matrix[i][j] = INT_MAX;
        }
      }
    }
  }

  int v;
  cout << "Enter source: ";
  cin >> v;

  if (v >= n) {
    return 1;
  }

  sssp(v, dist, adjency_matrix, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << setw(10) << adjency_matrix[i][j] << " ";
    }
    cout << "\n";
  }

  for (int i = 0; i < n; i++) {
    cout << i << " = " << dist[i] << "\n";
  }

  return 0;
}
