#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

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
  int n = 16;
  int **a = new int *[n];
  int **b = new int *[n];
  int **c = new int *[n];
  for(int i=0;i<n;i++){
    a[i] = new int[n];
    b[i] = new int[n];
    c[i] = new int[n];
  }
  srand(time(NULL));

  int max_range = 1000 - 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = rand() % max_range + 1;
      b[i][j] = rand() % max_range + 1;
    }
  }

  recurr_cut(a, b, c, 0, n - 1, 0, n - 1, 0, n - 1, 0, n - 1);

  cout << "Divide and conquer\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << setw(7) << c[i][j] << " ";
    }
    cout << "\n";
  }

  cout << "\n\n";

  bool pass_test = true;
  cout << "Normal 3 loop solution\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int v = 0;
      for (int k = 0; k < n; k++) {
        v += a[i][k] * b[k][j];
      }
      if (c[i][j] != v) {
        pass_test = false;
      }
      cout << setw(7) << v << " ";
    }
    cout << "\n";
  }

  cout << "\n\n";
  if (!pass_test) {
    cout << "Both are not the same!";
  } else {
    cout << "Both are the same!";
  }

  return 0;
}
