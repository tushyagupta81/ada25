#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

#define MAX_LOAD 500
#define COL 4

int partition(float a[][COL], int l, int h, int mode) {
  int pivot = a[l][mode];
  int j = h, i = l + 1;
  while (j >= i) {
    while (a[j][mode] >= pivot && j > l) {
      j--;
    }
    while (a[i][mode] < pivot && i <= h) {
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

void quicksort(float a[][COL], int l, int h, int mode) {
  if (l < h) {
    int p = partition(a, l, h, mode);
    quicksort(a, l, p - 1, mode);
    quicksort(a, p + 1, h, mode);
  }
}

int main() {
  int profit_max = 1000;
  int profit_min = 10;
  int profit_range = profit_max - profit_min + 1;
  int weight_max = 100;
  int weigth_min = 10;
  int weight_range = weight_max - weigth_min + 1;
  // int n;
  // cout << "Enter number of items: ";
  // cin >> n;
  // float items[n][COL];
  // srand(time(NULL));
  // for (int i = 0; i < n; ++i) {
  //   items[i][0] = rand() % profit_range + profit_min;
  //   items[i][1] = rand() % weight_range + weigth_min;
  //   items[i][2] = items[i][0] / items[i][1];
  //   items[i][3] = i + 1;
  // }
  //
  // // cout << "Catalog\n";
  // // for (int i = 0; i < n; ++i) {
  // //   cout << setw(to_string(n).length()) << fixed << setprecision(0)
  // //        << items[i][3] << ". Profit: " << setw(4) << fixed <<
  // //        setprecision(0)
  // //        << items[i][0] << ", Weight: " << setw(3) << items[i][1]
  // //        << ", Ratio: " << fixed << setprecision(2) << setw(5) <<
  // items[i][2]
  // //        << "\n";
  // // }
  //
  // // mode = 0 is according to profit
  // quicksort(items, 0, n - 1, 0);
  // int curr_load = 0, curr_profit = 0;
  // float per;
  // for (int i = n - 1; i >= 0; --i) {
  //   if (items[i][1] <= MAX_LOAD - curr_load) {
  //     curr_load += items[i][1];
  //     curr_profit += items[i][0];
  //   } else {
  //     per = (float)(MAX_LOAD - curr_load) / items[i][1];
  //     curr_load += items[i][1] * per;
  //     curr_profit += items[i][0] * per;
  //   }
  //   if (curr_load == MAX_LOAD) {
  //     break;
  //   }
  // }
  // cout << "\nSort by Profit\n Total Profit: " << curr_profit
  //      << "\n Total Load: " << curr_load << "\n";
  //
  // // mode = 1 is according to weight
  // quicksort(items, 0, n - 1, 1);
  // curr_load = 0, curr_profit = 0;
  // for (int i = n - 1; i >= 0; --i) {
  //   if (items[i][1] <= MAX_LOAD - curr_load) {
  //     curr_load += items[i][1];
  //     curr_profit += items[i][0];
  //   } else {
  //     per = (float)(MAX_LOAD - curr_load) / items[i][1];
  //     curr_load += items[i][1] * per;
  //     curr_profit += items[i][0] * per;
  //   }
  //   if (curr_load == MAX_LOAD) {
  //     break;
  //   }
  // }
  // cout << "\nSort by Weight\n Total Profit: " << curr_profit
  //      << "\n Total Load: " << curr_load << "\n";
  //
  // // mode = 2 is according to profit/weight
  // quicksort(items, 0, n - 1, 2);
  // curr_load = 0, curr_profit = 0;
  // for (int i = n - 1; i >= 0; --i) {
  //   if (items[i][1] <= MAX_LOAD - curr_load) {
  //     curr_load += items[i][1];
  //     curr_profit += items[i][0];
  //   } else {
  //     per = (float)(MAX_LOAD - curr_load) / items[i][1];
  //     curr_load += items[i][1] * per;
  //     curr_profit += items[i][0] * per;
  //   }
  //   if (curr_load == MAX_LOAD) {
  //     break;
  //   }
  // }
  // cout << "\nSort by Profit/Weight\n Total Profit: " << curr_profit
  //      << "\n Total Load: " << curr_load << "\n";
  cout<<"size,time\n";
  for (int n = 1000; n <= 100000; n += 1000) {
    double res = 0;
    for (int m = 0; m < 10; m++) {
      float items[n][COL];
      srand(time(NULL));
      for (int i = 0; i < n; ++i) {
        items[i][0] = rand() % profit_range + profit_min;
        items[i][1] = rand() % weight_range + weigth_min;
        items[i][2] = items[i][0] / items[i][1];
        items[i][3] = i + 1;
      }

      auto start = std::chrono::high_resolution_clock::now();

      // mode = 0 is according to profit
      quicksort(items, 0, n - 1, 0);
      int curr_load = 0, curr_profit = 0;
      float per;
      for (int i = n - 1; i >= 0; --i) {
        if (items[i][1] <= MAX_LOAD - curr_load) {
          curr_load += items[i][1];
          curr_profit += items[i][0];
        } else {
          per = (float)(MAX_LOAD - curr_load) / items[i][1];
          curr_load += items[i][1] * per;
          curr_profit += items[i][0] * per;
        }
        if (curr_load == MAX_LOAD) {
          break;
        }
      }

      // mode = 1 is according to weight
      quicksort(items, 0, n - 1, 1);
      curr_load = 0, curr_profit = 0;
      for (int i = n - 1; i >= 0; --i) {
        if (items[i][1] <= MAX_LOAD - curr_load) {
          curr_load += items[i][1];
          curr_profit += items[i][0];
        } else {
          per = (float)(MAX_LOAD - curr_load) / items[i][1];
          curr_load += items[i][1] * per;
          curr_profit += items[i][0] * per;
        }
        if (curr_load == MAX_LOAD) {
          break;
        }
      }

      // mode = 2 is according to profit/weight
      quicksort(items, 0, n - 1, 2);
      curr_load = 0, curr_profit = 0;
      for (int i = n - 1; i >= 0; --i) {
        if (items[i][1] <= MAX_LOAD - curr_load) {
          curr_load += items[i][1];
          curr_profit += items[i][0];
        } else {
          per = (float)(MAX_LOAD - curr_load) / items[i][1];
          curr_load += items[i][1] * per;
          curr_profit += items[i][0] * per;
        }
        if (curr_load == MAX_LOAD) {
          break;
        }
      }
      auto end = std::chrono::high_resolution_clock::now();
      auto duration =
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
      res += duration.count();
    }
    cout << n << "," << fixed << res / 10 << "\n";
  }

  return 0;
}
