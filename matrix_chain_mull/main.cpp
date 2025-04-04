#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void print(int **S, int i, int j) {
  // cout<<"i = "<<i<<", j = "<<j<<"\n";
  // if(j<i){
  //   return;
  // }
  if (i == j) {
    cout << "A" << i+1;
  } else {
    cout << "(";
    print(S, i, S[i][j]-1);
    print(S, S[i][j], j);
    cout << ")";
  }
}

void MCM(int *p, int n, int **m, int **S) {
  n = n - 1;
  for (int i = 0; i < n; i++) {
    m[i][i] = 0;
  }
  long j, q;
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      j = i + l - 1;
      m[i - 1][j - 1] = INT_MAX;
      for (int k = i; k < j; k++) {
        q = m[i - 1][k - 1] + m[k + 1 - 1][j - 1] + (p[i - 1] * p[k] * p[j]);
        if (q < m[i - 1][j - 1]) {
          m[i - 1][j - 1] = q;
          S[i - 1][j - 1] = k;
        }
      }
    }
  }
}

int main() {
  srand(time(NULL));
  int n = 6;
  int *p = new int[n];
  int class_matrix[6] = {5, 8, 10, 20, 30, 10};
  for (int i = 0; i < n; i++) {
    p[i] = rand() % 99 + 1;
    // p[i] = class_matrix[i];
    // cout << p[i] << ",";
  }

  int **m = new int *[n - 1], **S = new int *[n - 1];
  for (int i = 0; i < n - 1; i++) {
    m[i] = new int[n - 1];
    S[i] = new int[n - 1];
  }

  MCM(p, n, m, S);

  print(S, 0, 4);

  return 0;
}
