#include <iostream>
using namespace std;

#define N 5

int peak(int a[][N], int y1, int y2, int x1, int x2, int n) {
  // if(y2>=y1 || x2>=x1){
  //   return -1;
  // }
  int m1 = (y1 + y2) / 2;
  int m2 = (x1 + x2) / 2;
  if (m2 < n - 1 && a[m1][m2] < a[m1][m2 + 1]) {
    return peak(a, y1, y2, m2 + 1, x2, n);
  } else if (m2 > 0 && a[m1][m2] < a[m1][m2 - 1]) {
    return peak(a, y1, y2, x1, m2 - 1, n);
  } else if (m1 < n - 1 && a[m1][m2] < a[m1 + 1][m2]) {
    return peak(a, m1 + 1, y2, x1, x2, n);
  } else if (m1 > 0 && m2 < n - 1 && a[m1][m2] < a[m1 - 1][m2]) {
    return peak(a, y1, m1 - 1, x1, x2, n);
  } else {
    return a[m1][m2];
  }
}

int main() {
  // int n;
  // cout << "Enter size of array: ";
  // cin >> n;
  // int a[n][3];
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < 3; j++) {
  //     cout << i << ", " << j << ": ";
  //     cin >> a[i][j];
  //   }
  // }
  int a[N][N] = {
      {24, 54, 52, 102, 1},    {63, 652, 432, 43, 143}, {43, 65, 24, 14, 6543},
      {65, 35, 765, 252, 765}, {645, 23, 543, 24, 43},
  };
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << a[i][j] << ", ";
    }
    cout << "\n";
  }
  cout << peak(a, 0, N - 1, 0, N - 1, N);
  return 0;
}
