#include <chrono>
#include <ctime>
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

int **stressens(int **a, int **b, int n) {

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

  int **p = stressens(add(a11, a22, mid), add(b11, b22, mid), mid);
  int **q = stressens(add(a21, a22, mid), b11, mid);
  int **r = stressens(a11, sub(b12, b22, mid), mid);
  int **s = stressens(a22, sub(b21, b11, mid), mid);
  int **t = stressens(add(a11, a12, mid), b22, mid);
  int **u = stressens(sub(a21, a11, mid), add(b11, b12, mid), mid);
  int **v = stressens(sub(a12, a22, mid), add(b21, b22, mid), mid);

  for (int i = 0; i < mid; i++) {
    delete[] a11[i];
    delete[] a12[i];
    delete[] a21[i];
    delete[] a22[i];
    delete[] b11[i];
    delete[] b12[i];
    delete[] b21[i];
    delete[] b22[i];
  }
  delete[] a11;
  delete[] a12;
  delete[] a21;
  delete[] a22;
  delete[] b11;
  delete[] b12;
  delete[] b21;
  delete[] b22;

  int **c11 = add(add(p, s, mid), sub(v, t, mid), mid);
  int **c12 = add(r, t, mid);
  int **c21 = add(q, s, mid);
  int **c22 = add(add(p, r, mid), sub(u, q, mid), mid);

  for (int i = 0; i < mid; i++) {
    delete[] p[i];
    delete[] q[i];
    delete[] r[i];
    delete[] s[i];
    delete[] t[i];
    delete[] u[i];
    delete[] v[i];
  }
  delete[] p;
  delete[] q;
  delete[] r;
  delete[] s;
  delete[] t;
  delete[] u;
  delete[] v;

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

  for (int i = 0; i < mid; i++) {
    delete[] c11[i];
    delete[] c12[i];
    delete[] c21[i];
    delete[] c22[i];
  }
  delete[] c11;
  delete[] c12;
  delete[] c21;
  delete[] c22;

  return res;
}

void reg_matrix(int **a, int **b, int **c, int ax_offset, int ay_offset,
                int bx_offset, int by_offset) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        c[i + ay_offset][j + bx_offset] +=
            a[i + ay_offset][k + ax_offset] * b[k + by_offset][j + bx_offset];
      }
    }
  }
}

void recurr_cut(int **a, int **b, int **c, int axl, int axh, int ayl, int ayh,
                int bxl, int bxh, int byl, int byh) {
  if (axl >= axh || bxl >= bxh || ayl >= ayh || byl >= byh) {
    return;
  }
  if ((axh - axl == 1 && ayh - ayl == 1) ||
      (bxh - bxl == 1 && byh - byl == 1)) {
    reg_matrix(a, b, c, axl, ayl, bxl, byl);
  }
  recurr_cut(a, b, c, axl, (axl + axh) / 2, ayl, (ayl + ayh) / 2, bxl,
             (bxl + bxh) / 2, byl, (byl + byh) / 2);
  recurr_cut(a, b, c, (axl + axh) / 2 + 1, axh, ayl, (ayl + ayh) / 2, bxl,
             (bxl + bxh) / 2, (byl + byh) / 2 + 1, byh);
  recurr_cut(a, b, c, axl, (axl + axh) / 2, ayl, (ayl + ayh) / 2,
             (bxl + bxh) / 2 + 1, bxh, byl, (byl + byh) / 2);
  recurr_cut(a, b, c, (axl + axh) / 2 + 1, axh, ayl, (ayl + ayh) / 2,
             (bxl + bxh) / 2 + 1, bxh, (byl + byh) / 2 + 1, byh);
  recurr_cut(a, b, c, axl, (axl + axh) / 2, (ayl + ayh) / 2 + 1, ayh, bxl,
             (bxl + bxh) / 2, byl, (byl + byh) / 2);
  recurr_cut(a, b, c, (axl + axh) / 2 + 1, axh, (ayl + ayh) / 2 + 1, ayh, bxl,
             (bxl + bxh) / 2, (byl + byh) / 2 + 1, byh);
  recurr_cut(a, b, c, axl, (axl + axh) / 2, (ayl + ayh) / 2 + 1, ayh,
             (bxl + bxh) / 2 + 1, bxh, byl, (byl + byh) / 2);
  recurr_cut(a, b, c, (axl + axh) / 2 + 1, axh, (ayl + ayh) / 2 + 1, ayh,
             (bxl + bxh) / 2 + 1, bxh, (byl + byh) / 2 + 1, byh);
}
int main() {
  srand(time(NULL));
  cout << "size,conventional,stressens,divide and conquer\n";
  for (int n = 1024; n <= 1024; n *= 2) {
    int **a = new int *[n];
    int **b = new int *[n];
    int **c = new int *[n];

    for (int i = 0; i < n; i++) {
      a[i] = new int[n];
      b[i] = new int[n];
      c[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = rand() % 19 + 1;
        b[i][j] = rand() % 19 + 1;
      }
    }
    cout << n;

    auto start = std::chrono::high_resolution_clock::now();
    mult(a, b, n);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << ", " << duration.count();
    auto start2 = std::chrono::high_resolution_clock::now();
    stressens(a, b, n);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);
    cout << ", " << duration2.count();
    auto start3 = std::chrono::high_resolution_clock::now();
    recurr_cut(a, b, c, 0, n - 1, 0, n - 1, 0, n - 1, 0, n - 1);
    auto end3 = std::chrono::high_resolution_clock::now();
    auto duration3 =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - start3);

    cout << ", " << duration3.count() << "\n";
  }
  return 0;
}
