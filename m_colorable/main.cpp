#include <ctime>
#include <iostream>
#include <pthread.h>
using namespace std;

bool color(int n, int i, int *x, int **adj) {
  for (int j = 0; j < n; j++) {
    if (adj[n][j] != 0) {
      if (x[j] == i) {
        return false;
      }
    }
  }
  return true;
}

void write(int *a, int n) {
  for (int i = 0; i < n; i++) {
    cout << i+1 << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n" << endl;
}

void mcg(int k, int n, int M, int *x, int **adj) {
  for (int i = 0; i < M; i++) {
    if (color(k, i, x, adj)) {
      x[k] = i;
      if (k == n - 1) {
        write(x, n);
      } else {
        mcg(k + 1, n, M, x, adj);
      }
    }
  }
}

int main() {
  // srandom(time(NULL));
  // int n = random() % 20 + 1;
  int n = 6;

  int **adj = new int *[n];

  int matrix[6][6] = {
      {0, 10, 2, 0, 0, 2}, {10, 0, 0, 0, 9, 8}, {2, 0, 0, 5, 0, 1},
      {0, 0, 5, 0, 7, 6},  {0, 9, 0, 7, 0, 0},  {2, 8, 1, 6, 0, 0},
  };

  for (int i = 0; i < n; i++) {
    adj[i] = new int[n];
    for (int j = 0; j < n; j++) {
      adj[i][j] = matrix[i][j];
    }
  }

  int *x = new int[n];
  int M = 3;
  cout << "M = " << M << endl;
  mcg(0, n, M, x, adj);
  return 0;
}
