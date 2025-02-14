#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int det(int x1, int y1, int x2, int y2, int x3, int y3) {
  return x1 * (y2 - y3) - x2 * (y1 - y3) + x3 * (y1 - y2);
}

float area(int *p1, int *p2, int *p3) {
  return abs(0.5 * det(p1[0], p1[1], p2[0], p2[1], p3[0], p3[1]));
}

int *min_max(int **a, int l, int h) {
  if (h - l <= 1) {
    int *r = (int *)malloc(2 * sizeof(int));
    if (a[l][0] < a[h][0]) {
      r[0] = l;
      r[1] = h;
    } else {
      r[0] = h;
      r[1] = l;
    }
    return r;
  }
  int *r1 = new int[2];
  int *r2 = new int[2];
  r1 = min_max(a, l, (l + h) / 2);
  r2 = min_max(a, (l + h) / 2 + 1, h);
  int *r = (int *)malloc(2 * sizeof(int));
  if (a[r1[0]][0] < a[r2[0]][0]) {
    r[0] = r1[0];
  } else {
    r[0] = r2[0];
  }
  if (a[r1[1]][0] > a[r2[1]][0]) {
    r[1] = r1[1];
  } else {
    r[1] = r2[1];
  }
  return r;
}

void fin(int **a, int *p1, int *p2, int n, int **o, int &on) {
  if (n <= 1) {
    return;
  }
  float max_area = 0;
  int max_point;
  for (int i = 0; i < n; i++) {
    if (area(p1, p2, a[i]) > max_area) {
      max_area = area(p1, p2, a[i]);
      max_point = i;
    }
  }

  o[on++] = a[max_point];

  int **X1 = new int *[n];
  int **X2 = new int *[n];
  for (int i = 0; i < n; i++) {
    X1[i] = new int[2];
    X2[i] = new int[2];
  }
  int c1 = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    if (det(p1[0], p1[1], a[max_point][0], a[max_point][1], a[i][0], a[i][1]) >
        0) {
      X1[c1++] = a[i];
    } else if (det(p2[0], p2[1], a[max_point][0], a[max_point][1], a[i][0],
                   a[i][1]) < 0) {
      X2[c2++] = a[i];
    }
  }
  fin(X1, p1, a[max_point], c1, o, on);
  fin(X2, p2, a[max_point], c2, o, on);
}

void quickhull(int **a, int **o, int &on, int n) {
  int **X1 = new int *[n];
  int **X2 = new int *[n];
  for (int i = 0; i < n; i++) {
    X1[i] = new int[2];
    X2[i] = new int[2];
  }
  int *m = new int[2];
  m = min_max(a, 0, n - 1);
  int c1 = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    if (det(a[m[0]][0], a[m[0]][1], a[m[1]][0], a[m[1]][1], a[i][0], a[i][1]) >
        0) {
      X1[c1++] = a[i];
    } else {
      X2[c2++] = a[i];
    }
  }
  o[on++] = a[m[0]];
  o[on++] = a[m[1]];
  fin(X1, a[m[0]], a[m[1]], c1, o, on);
  fin(X2, a[m[0]], a[m[1]], c2, o, on);
}

int main() {
  int n = 100;
  int **a = new int *[n];
  int **out = new int *[n];
  int out_n = 0;

  for (int i = 0; i < n; i++) {
    a[i] = new int[2];
    out[i] = new int[2];
  }
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      a[i][j] = rand() % 100;
    }
  }

  quickhull(a, out, out_n, n);

  cout << "input size = " << n << endl;
  for (int i = 0; i < n; i++) {
    // cout << "x = " << out[i][0] << ", y = " << out[i][1] << "\n";
    cout << a[i][0] << "," << a[i][1] << "\n";
  }
  cout << "output size = " << out_n << endl;
  for (int i = 0; i < out_n; i++) {
    // cout << "x = " << out[i][0] << ", y = " << out[i][1] << "\n";
    cout << out[i][0] << "," << out[i][1] << "\n";
  }

  return 0;
}
