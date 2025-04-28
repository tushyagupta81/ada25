#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

void write(int *a, int *w, int n, int k) {
  for (int i = 0; i < n; i++) {
    cout << setw(2) << w[i] << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    if (i > k) {
      cout << setw(2) << 0 << " ";
    } else {
      cout << setw(2) << a[i] << " ";
    }
  }
  cout << "\n\n";
}

void backtrack(int *x, int k, int *w, int remainder, int reached, int target,
               int n) {
  x[k] = 1;
  if (reached + w[k] == target) {
    write(x, w, n, k);
    return;
  } else if (k + 1 < n && reached + w[k] + w[k + 1] > target) {
  } else {
    backtrack(x, k + 1, w, remainder - w[k], reached + w[k], target, n);
  }

  if ((k + 1 < n) && (reached + remainder - w[k] >= target) &&
      (reached + w[k + 1] <= target)) {
    x[k] = 0;
    backtrack(x, k + 1, w, remainder - w[k], reached, target, n);
  }
}

int main() {
  srandom(time(NULL));
  int n = random() % 20 + 1;
  n = 5;
  cout << "Length of set: " << n << endl;

  int *s = new int[n];
  int *a = new int[n];
  int sum = 0;
  int input[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < n; i++) {
    s[i] = random() % 20;
    // s[i] = input[i];
    sum += s[i];
    a[i] = 0;
  }

  sort(s, s + n);

  // int S = 6;
  int S = random() % 40;
  cout << "Sum of subsets: " << S << endl;

  backtrack(a, 0, s, sum, 0, S, n);

  return 0;
}
