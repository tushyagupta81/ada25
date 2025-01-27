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
  int n;
  cout << "Enter size of array: ";
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cout << i << ": ";
    cin >> a[i];
  }
  cout << "Peak: " << a[peak(a, 0, n - 1, n)];

  return 0;
}
