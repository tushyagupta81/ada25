#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

void mergePurge(set<pair<int, int>> a, set<pair<int, int>> b,
                set<pair<int, int>> &res, int *c, int W) {
  set<pair<int, int>> r;
  for (auto const ta : a) {
    r.insert(ta);
  }
  for (auto const tb : b) {
    r.insert(tb);
  }
  bool to_put = false;
  for (auto i = r.begin(); i != r.end(); i++) {
    if (i->second > W) {
      continue;
    }
    to_put = true;
    for (auto j = r.begin(); j != r.end(); j++) {
      if (i == j) {
        continue;
      }
      if (i->first <= j->first && i->second > j->second) {
        to_put = false;
        continue;
      }
    }
    if (to_put) {
      res.insert({i->first, i->second});
    }
  }
}

void create_couterpart(set<pair<int, int>> &a, set<pair<int, int>> &b, int *c) {
  int temp1, temp2;
  for (auto const t : a) {
    temp1 = c[0] + t.first;
    temp2 = c[1] + t.second;
    b.insert({temp1, temp2});
  }
}

void knapsack(int **a, int n, int i, vector<set<pair<int, int>>> &s, int W) {
  if (i >= n) {
    return;
  }
  set<pair<int, int>> s1;
  create_couterpart(s[i], s1, a[i]);
  mergePurge(s[i], s1, s[i + 1], a[i], W);
  knapsack(a, n, i + 1, s, W);
}

void traceBack(vector<set<pair<int, int>>> a, int *x, int **c, int p, int w,
               int n) {
  for (int i = n - 1; i >= 0; i--) {
    if (a[i + 1].count({p, w}) > 0 && a[i].count({p, w}) <= 0) {
      x[i] = 1;
      p = p - c[i][0];
      w = w - c[i][1];
    } else {
      x[i] = 0;
    }
  }
}

void max_tuple(set<pair<int, int>> res, pair<int, int> &max_t) {
  for (auto const t : res) {
    if (t.first > max_t.first) {
      max_t.first = t.first;
      max_t.second = t.second;
    }
  }
}

int main() {
  // Uncontrolled experiment
  // srand(time(NULL));
  // int n = 25;
  // int W = 100;
  // int **a = new int *[n];
  // for (int i = 0; i < n; i++) {
  //   a[i] = new int[2];
  //   for (int j = 0; j < 2; j++) {
  //     a[i][j] = rand() % 99 + 1;
  //   }
  // }

  // Controlled experiment 1
  // int n = 4;
  // int W = 10;
  // int **a = new int *[n];
  // int input[4][2] = {
  //     {10, 5},
  //     {40, 4},
  //     {30, 6},
  //     {50, 3},
  // };

  // Controlled experiment 2
  int n = 3;
  int W = 6;
  int **a = new int *[n];
  int input[3][2] = {
      {1, 2},
      {2, 3},
      {5, 4},
  };

  for (int i = 0; i < n; i++) {
    a[i] = new int[2];
    for (int j = 0; j < 2; j++) {
      a[i][j] = input[i][j];
    }
  }

  vector<set<pair<int, int>>> res;
  for (int i = 0; i < n + 1; i++) {
    set<pair<int, int>> s = {};
    res.push_back(s);
  }

  res[0] = {{0, 0}};
  int *x = new int[n];

  knapsack(a, n, 0, res, W);

  pair<int, int> max_t = {INT_MIN, 0};
  max_tuple(res[n], max_t);

  traceBack(res, x, a, max_t.first, max_t.second, n);

  cout << "Tuples to include:\n";
  for (int i = 0; i < n; i++) {
    if (x[i] == 1) {
      cout << "(" << a[i][0] << ", " << a[i][1] << ")" << "\n";
    }
  }

  return 0;
}
