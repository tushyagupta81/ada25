#include <iostream>
using namespace std;

int partition(vector<int> &a, int l, int h) {
  int pivot = a[l];
  int j = h, i = l + 1;
  while (j >= i) {
    while (a[j] > pivot && j > l) {
      j--;
    }
    while (a[i] < pivot && i <= h) {
      i++;
    }
    if (i >= j) {
      break;
    }
    swap(a[i], a[j]);
  }
  swap(a[l], a[i - 1]);
  return i - 1;
}

void quicksort(vector<int> &a, int l, int h) {
  if (l < h) {
    int p = partition(a, l, h);
    quicksort(a, l, p - 1);
    quicksort(a, p + 1, h);
  }
}

int main() {
  // int n;
  // cout << "Enter length of array: ";
  // cin >> n;
  // int a[n];
  // for (int i = 0; i < n; i++) {
  //   cin >> a[i];
  // }
  //
  // quicksort(a, 0, n - 1);
  //
  // for (int i = 0; i < n; i++) {
  //   cout << a[i] << " ";
  // }
  int n = 10;
  for (int i = 0; i < 100; ++i) {
    cout << n;
    long res = 0;
    for (int k = 0; k < 10; ++k) {
      vector<int> a(n,0);
      for (int j = 0; j < n; ++j) {
        a[j] = rand();
      }

      auto start = std::chrono::high_resolution_clock::now();
      quicksort(a, 0, n - 1);
      auto end = std::chrono::high_resolution_clock::now();
      auto duration =
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
      res += duration.count();
    }
    cout << " -> " << res/10 << "\n";
    n *= 2;
  }
  return 0;
}
