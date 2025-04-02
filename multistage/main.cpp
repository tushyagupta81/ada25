#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int **res = new int *[2];
int a[12][12] = {
    {0, 9, 7, 3, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 4, 2, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 11, 8, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 6, 5, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};
int sink = 11;

int set_data(int stage, int source) {
  int cal;
  for (int i = 0; i < 12; i++) {
    if (a[source][i] != 0) {
      cal = a[source][i] + set_data(stage + 1, i);
      if (cal < res[0][source] || res[0][source] == 0) {
        res[0][source] = cal;
        res[1][source] = i;
      }
    }
  }
  return res[0][source];
}

int main() {
  for (int i = 0; i < 2; i++) {
    res[i] = new int[12];
  }
  for (int i = 0; i < 12; i++) {
    res[0][i] = 0;
    res[1][i] = 0;
  }
  res[0][sink] = 0;
  res[1][sink] = sink;

  set_data(1, 0);

  cout << "Vert |";
  for (int i = 0; i < 12; i++) {
    cout << setw(3) << i + 1 << ",";
  }
  cout << "\n";
  cout << "Cost |";
  for (int i = 0; i < 12; i++) {
    cout << setw(3) << res[0][i] << ",";
  }
  cout << "\n";
  cout << "Dist |";
  for (int i = 0; i < 12; i++) {
    cout << setw(3) << res[1][i] + 1 << ",";
  }

  return 0;
}
