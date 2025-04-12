#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int lcs(int **len, string **dir, int *a, int *b, int i, int j) {
  if (i == 0 || j == 0) {
    return len[i][j];
  }
  if (a[i - 1] == b[j - 1]) {
    len[i][j] = 1 + lcs(len, dir, a, b, i - 1, j - 1);
    dir[i - 1][j - 1] = "󰁛";
  } else {
    int l1 = lcs(len, dir, a, b, i, j - 1);
    int l2 = lcs(len, dir, a, b, i - 1, j);
    if (l1 > l2) {
      len[i][j] = l1;
      dir[i - 1][j - 1] = "";
    } else {
      len[i][j] = l2;
      dir[i - 1][j - 1] = "";
    }
  }
  return len[i][j];
}

int main() {
  srand(time(NULL));

  int n = rand() % 9 + 1;
  int m = rand() % 9 + 1;

  int *a = new int[n];
  int *b = new int[m];
  string **dir = new string *[n];
  cout << "A -> ";
  for (int i = 0; i < n; i++) {
    dir[i] = new string[m];
    a[i] = rand() % 10;
    cout << a[i] << ", ";
  }
  cout << "\n";
  cout << "B -> ";
  for (int i = 0; i < m; i++) {
    b[i] = rand() % 10;
    cout << b[i] << ", ";
  }
  cout << "\n";

  int **len = new int *[n + 1];
  for (int i = 0; i < n + 1; i++) {
    len[i] = new int[m + 1];
    for (int j=0; j<m+1; j++) {
      len[i][j] = 0;
    }
  }
  lcs(len, dir, a, b, n, m);

  cout << "\nLength matrix:\n";
  cout << "   0 ";
  for (int i = 0; i < m; i++) {
    cout << b[i] << " ";
  }
  cout << "\n";
  for (int i = 0; i < n + 1; i++) {
    i == 0 ? cout << "0: " : cout << a[i-1] << ": ";
    for (int j = 0; j < m + 1; j++) {
      cout << len[i][j] << " ";
    }
    cout << "\n";
  }

  cout << "\nDirection matrix:\n";
  cout << "   ";
  for (int i = 0; i < m; i++) {
    cout << b[i] << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    cout << a[i] << ": ";
    for (int j = 0; j < m; j++) {
      cout << (dir[i][j] != "" ? dir[i][j] : " ") << " ";
    }
    cout << "\n";
  }
  return 0;
}
