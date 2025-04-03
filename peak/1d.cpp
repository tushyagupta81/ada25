#include <chrono>
#include <ctime>
#include <iostream>
using namespace std;

int peak(int a[], int l, int h, int n) {
  // if (l > h) {
  //   return -1;
  // }
  int mid = (l + h) / 2;
  if (mid < n - 1 && a[mid] < a[mid + 1]) {
    return peak(a, mid + 1, h, n);
  } else if (mid > 0 && a[mid] < a[mid - 1]) {
    return peak(a, l, mid - 1, n);
  } else {
    return mid;
  }
}

int main() {
  // int n;
  // cout << "Enter size of array: ";
  // cin >> n;
  // int a[n];
  // for (int i = 0; i < n; i++) {
  //   cout << i << ": ";
  //   cin >> a[i];
  // }
  // cout << "Peak: " << a[peak(a, 0, n - 1, n)];

  srand(time(NULL));
  cout << "size,time\n";
  for (int n = 100000; n <= 2000000; n += 100000) {
    cout << n;
    long res = 0;
    for (int k = 0; k < 10; ++k) {
      int a[n];
      for (int j = 0; j < n; ++j) {
        a[j] = rand();
      }
      int stack = 0;
      int maxStack = 0;

      auto start = std::chrono::high_resolution_clock::now();
      peak(a, 0, n - 1, n);
      auto end = std::chrono::high_resolution_clock::now();
      auto duration =
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
      res += duration.count();

      // cout << "maxStack = " << maxStack << "\n";
    }
    cout << "," << res / 10 << "\n";
  }
  return 0;
}
