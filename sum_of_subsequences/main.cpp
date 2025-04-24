#include <ctime>
#include <iostream>
using namespace std;

int sum(int *a) {
  int s = 0, i = 0;
  while (1) {
    if (a[i] == -1) {
      break;
    }
    s += a[i++];
  }
  return s;
}

void write(int *a, int k) {
  cout << "(";
  for (int i = 0; i < k; i++) {
    cout << a[i] << ", ";
  }
  cout << ")\n";
}

bool check(int *a, int k, int c) {
  for (int i = 0; i < k; i++) {
    if (a[i] == c) {
      return false;
    }
  }
  return true;
}

void nextVal(int *a, int *s, int n, int k, int S) {
  int i = 0;
  do {
    if (check(a, k, s[i]) && s[i] <= S) {
      a[k] = s[i];
      return;
    }else{
      a[k] = -1;
    }
    i++;
  } while (i<n);
}

void backtrack(int k, int *s, int *a, int S, int S_curr, int n) {
  do {
    nextVal(a, s, n, k, S_curr);
    if (a[k] == -1) {
      return;
    }
    if (sum(a) == S) {
      write(a, k+1);
      return;
    }
    S_curr -= a[k];
    backtrack(k + 1, s, a, S, S_curr, n);
  } while (1);
}

int main() {
  srandom(time(NULL));
  int n = random() % 20 + 1;
  n = 5;
  cout << "Length of set: " << n << endl;

  int *s = new int[n];
  int *a = new int[n];
  int input[5] = {1, 2, 3, 4, 5};
  for (int i = 0; i < n; i++) {
    // s[i] = random() % 20;
    s[i] = input[i];
    a[i] = -1;
  }

  int S = 6;

  backtrack(0, s, a, S, S, n);
  write(a, n);

  return 0;
}
