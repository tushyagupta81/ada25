#include <ctime>
#include <iostream>
#include <stack>
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

int main() {
  // int n;
  // cout << "Enter length of array: ";
  // cin >> n;
  // vector<int> a(n);
  // // for (int i = 0; i < n; i++) {
  // //   cin >> a[i];
  // // }
  //
  // for (int j = 0; j < n; ++j) {
  //   a[j] = rand();
  // }
  // stack<int> s;
  // int l = 0;
  // int h = n - 1;
  // do {
  //   while (l < h) {
  //     int j = partition(a, l, h);
  //     if (l - j < h) {
  //       h = j - 1;
  //       s.push(j - 1);
  //       s.push(l);
  //     } else {
  //       l = j + 1;
  //       s.push(h);
  //       s.push(j + 1);
  //     }
  //   }
  //   l = s.top();
  //   s.pop();
  //   h = s.top();
  //   s.pop();
  //
  // } while (!s.empty());
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

      auto start = std::chrono::high_resolution_clock::now();
      std::stack<int> s;
      int l = 0;
      int h = n;
      do {
        while (l < h) {
          int j = partition(a, l, h);
          if (l - j < h) {
            h = j - 1;
            s.push(j - 1);
            s.push(l);
          } else {
            l = j + 1;
            s.push(h);
            s.push(j + 1);
          }
        }
        l = s.top();
        s.pop();
        h = s.top();
        s.pop();

      } while (!s.empty());
      auto end = std::chrono::high_resolution_clock::now();
      auto duration =
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
      res += duration.count();
    }
    cout << "," << res / 10 << "\n";
  }
  return 0;
}
