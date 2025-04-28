#include <climits>
#include <iomanip>
#include <iostream>
using namespace std;

void all_pair_shortest_path(int **cost, int n) {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (cost[i][k] != INT_MAX && cost[k][j] != INT_MAX &&
            cost[i][j] > cost[i][k] + cost[k][j]) {
          cost[i][j] = cost[i][k] + cost[k][j];
        }
      }
    }
  }
}

int main() {
  int n = 6;
  int **cost = new int *[n];
  int **ans = new int *[n];
  int matrix[6][6] = {
      {0, 10, 2, INT_MAX, INT_MAX, 2},      {10, 0, INT_MAX, INT_MAX, 9, 8},
      {2, INT_MAX, 0, 5, INT_MAX, 1},       {INT_MAX, INT_MAX, 5, 0, 7, 6},
      {INT_MAX, 9, INT_MAX, 7, 0, INT_MAX}, {2, 8, 1, 6, INT_MAX, 0},
  };

  for (int i = 0; i < n; i++) {
    cost[i] = new int[n];
    ans[i] = new int[n];
    for (int j = 0; j < n; j++) {
      cost[i][j] = matrix[i][j];
      ans[i][j] = cost[i][j];
    }
  }

  all_pair_shortest_path(ans, n);

  cout<<"Vertex 1    2    3    4    5    6\n";
  for (int i = 0; i < n; i++) {
    cout << i + 1 << ": ";
    for (int j = 0; j < n; j++) {
      if (ans[i][j] == INT_MAX)
        cout << setw(5) << "INF ";
      else
        cout << setw(5) << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
