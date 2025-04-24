#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

bool place(int k, int i, int *x) {
  for (int j = 0; j < k; j++) {
    if (x[j] == i || (abs(j - k) == abs(x[j] - i))) {
      return false;
    }
  }
  return true;
}

void write(int *a, int n) {
  for (int i = 0; i < n; i++) {
    // cout << a[i] << " ";
    for (int j = 0; j<a[i]; j++) {
      cout<<"󰝤 ";
    }
    cout<<" ";
    for (int j = a[i] + 1; j<n; j++) {
      cout<<"󰝤 ";
    }
    cout<<"\n";
  }
  cout << endl;
}

void backtrack(int k, int n, int *x) {
  for (int i = 0; i < n; i++) {
    if (place(k, i, x)) {
      x[k] = i;
      if (k == n - 1) {
        write(x, n);
      } else {
        backtrack(k + 1, n, x);
      }
    }
  }
}

int main() {
  srandom(time(NULL));
  int n = random() % 20 + 1;
  cout << "n = " << n << "\n";

  int *x = new int[n];
  backtrack(0, n, x);
  return 0;
}
