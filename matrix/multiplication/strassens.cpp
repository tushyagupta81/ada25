#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int **sub(int **a, int **b, int n) {
  int **res = new int *[n];
  for (int i = 0; i < n; i++) {
    res[i] = new int[n];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = a[i][j] - b[i][j];
    }
  }
  return res;
}
int **add(int **a, int **b, int n) {
  int **res = new int *[n];
  for (int i = 0; i < n; i++) {
    res[i] = new int[n];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = a[i][j] + b[i][j];
    }
  }
  return res;
}

int **mult(int **a, int **b, int n) {
  int **res = new int *[n];
  for (int i = 0; i < n; i++) {
    res[i] = new int[n];
    for (int j = 0; j < n; j++) {
      res[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return res;
}

int **strassens(int **a, int **b, int n) {

  if (n <= 2) {
    return mult(a, b, n);
  }

  int mid = n / 2;
  int **a11 = new int *[mid];
  int **a12 = new int *[mid];
  int **a21 = new int *[mid];
  int **a22 = new int *[mid];
  int **b11 = new int *[mid];
  int **b12 = new int *[mid];
  int **b21 = new int *[mid];
  int **b22 = new int *[mid];
  for (int i = 0; i < mid; i++) {
    a11[i] = new int[mid];
    a12[i] = new int[mid];
    a21[i] = new int[mid];
    a22[i] = new int[mid];
    b11[i] = new int[mid];
    b12[i] = new int[mid];
    b21[i] = new int[mid];
    b22[i] = new int[mid];
  }

  for (int i = 0; i < mid; i++) {
    for (int j = 0; j < mid; j++) {
      a11[i][j] = a[i][j];
      a12[i][j] = a[i][mid + j];
      a21[i][j] = a[mid + i][j];
      a22[i][j] = a[mid + i][mid + j];
      b11[i][j] = b[i][j];
      b12[i][j] = b[i][mid + j];
      b21[i][j] = b[mid + i][j];
      b22[i][j] = b[mid + i][mid + j];
    }
  }

  int **p = strassens(add(a11, a22, mid), add(b11, b22, mid), mid);
  int **q = strassens(add(a21, a22, mid), b11, mid);
  int **r = strassens(a11, sub(b12, b22, mid), mid);
  int **s = strassens(a22, sub(b21, b11, mid), mid);
  int **t = strassens(add(a11, a12, mid), b22, mid);
  int **u = strassens(sub(a21, a11, mid), add(b11, b12, mid), mid);
  int **v = strassens(sub(a12, a22, mid), add(b21, b22, mid), mid);

  int **c11 = add(add(p, s, mid), sub(v, t, mid), mid);
  int **c12 = add(r, t, mid);
  int **c21 = add(q, s, mid);
  int **c22 = add(add(p, r, mid), sub(u, q, mid), mid);

  int **res = new int *[n];
  for (int i = 0; i < n; i++) {
    res[i] = new int[n];
  }

  for (int i = 0; i < mid; i++) {
    for (int j = 0; j < mid; j++) {
      res[i][j] = c11[i][j];
      res[i][j + mid] = c12[i][j];
      res[i + mid][j] = c21[i][j];
      res[i + mid][j + mid] = c22[i][j];
    }
  }

  return res;
}

int main() {
  int n = 4;
  int **a = new int *[n];
  int **b = new int *[n];

  for (int i = 0; i < n; i++) {
    a[i] = new int[n];
    b[i] = new int[n];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = rand() % 19 + 1;
      b[i][j] = rand() % 19 + 1;
    }
  }

  int **c = strassens(a, b, n);
  int **d = mult(a, b, n);

  cout<<"Stressens method - \n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout<< setw(4) <<c[i][j]<<", ";
    }
    cout<<"\n";
  }
  cout<<"\nRegular method - \n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout<< setw(4) <<d[i][j]<<", ";
    }
    cout<<"\n";
  }

  return 0;
}
