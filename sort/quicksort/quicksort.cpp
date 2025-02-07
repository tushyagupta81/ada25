#include <ctime>
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

void quicksort(vector<int> &a, int l, int h, int &stack, int &maxStack) {
  if (l < h) {
    if (stack > maxStack) {
      maxStack = stack;
    }
    stack++;
    int p = partition(a, l, h);
    stack--;
    stack++;
    quicksort(a, l, p - 1, stack, maxStack);
    stack--;
    stack++;
    quicksort(a, p + 1, h, stack, maxStack);
    stack--;
  }
}

int main() {
  // int n;
  // cout << "Enter length of array: ";
  // cin >> n;
  // vector<int> a(n);
  // for (int i = 0; i < n; i++) {
  //   cin >> a[i];
  // }
  // int stack = 0;
  //
  // quicksort(a, 0, n - 1, stack);
  //
  // for (int i = 0; i < n; i++) {
  //   cout << a[i] << " ";
  // }
  srand(time(NULL));
  cout << "size,time\n";
  for (int n = 100000; n <= 1000000; n += 100000) {
    cout << n;
    long res = 0;
    for (int k = 0; k < 10; ++k) {
      vector<int> a(n, 0);
      for (int j = 0; j < n; ++j) {
        a[j] = rand();
      }
      int stack = 0;
      int maxStack = 0;

      auto start = std::chrono::high_resolution_clock::now();
      quicksort(a, 0, n - 1, stack, maxStack);
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
