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
  srand(time(NULL));
  cout << "size,stack_call_recursive,stack_call_iterative\n";
  for (int n = 100000; n <= 1000000; n += 100000) {
    cout << n;
    vector<int> a(n, 0),b(n,0);
    for (int j = 0; j < n; ++j) {
      a[j] = b[j] = rand();
    }

    int stack = 0;
    int maxStack = 0;
    quicksort(a, 0, n - 1, stack, maxStack);
    cout << ", " << maxStack;

    std::stack<int> s;
    int l = 0;
    int h = n;
    int maxStack2 = 0;
    do {
      if (s.size() > maxStack2) {
        maxStack2 = s.size();
      }
      while (l < h) {
        int j = partition(b, l, h);
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
    cout << ", " << maxStack2/2 << "\n";
  }
  return 0;
}
