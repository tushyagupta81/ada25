#include <chrono>
#include <iostream>
#include <math.h>
using namespace std;

void magic_square(int n) {
  int a[n][n];
  int row = 0;
  int col = n / 2;
  for (int i = 1; i <= n * n; i++) {
    a[row][col] = i;
    if (i % n == 0) {
      row++;
    } else {
      row--;
      col--;
    }
    if (col < 0) {
      col = n - 1;
    }
    if (col >= n) {
      col = 0;
    }
    if (row < 0) {
      row = n - 1;
    }
    if (row >= n) {
      row = 0;
    }
  }
  // cout << "\n";
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cout << setw(to_string(n * n).length() + 1) << a[i][j] << ", ";
  //   }
  //   cout << "\n";
  // }
}

int main() {
  // int n;
  // cout << "Enter size of magic square(odd): ";
  // cin >> n;
  cout<<"size,time\n";
  for (int n = 5; n < 1000; n += 2) {
    cout << n;
    long res = 0;
    for (int m = 0; m < 10; ++m) {

      auto start = std::chrono::high_resolution_clock::now();
      magic_square(n);
      auto end = std::chrono::high_resolution_clock::now();
      auto duration =
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
      res += duration.count();
    }
    cout << "," << res/10 << "\n";
  }
  return 0;
}
