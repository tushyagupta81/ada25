#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iostream>
using namespace std;

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

bool is_valid(float a[][COL], float b[], int n) {
  for (int i = 0; i < n; i++) {
    // cout << "test arival = " << b[0] << endl;
    // cout << "acctual arival = " << a[i][0] << endl;
    // cout << "test finish = " << b[1] << endl;
    // cout << "acctual finish = " << a[i][1] << endl;
    if ((b[0] >= a[i][0] && b[0] <= a[i][1]) ||
        (b[1] >= a[i][0] && b[1] <= a[i][1]) ||
        (b[0] <= a[i][0] && b[1] >= a[i][0]) ||
        (b[0] <= a[i][0] && b[1] >= a[i][1])) {
      // cout << "returned false" << endl;
      return false;
    }
  }
  // cout << "returned true" << endl;
  return true;
}

int main() {
  int arival_time_max = 86400;
  int arival_range = arival_time_max + 1;
  int weight_max = 100;
  int weigth_min = 10;
  int weight_range = weight_max - weigth_min + 1;
  float curr_time;
  cout << "size,c1,c2\n";
  for (int n = 1000; n <= 100000; n += 1000) {
    cout << n;
    float items[n][COL];
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
      // arival time
      items[i][0] = rand() % arival_range;
      // finish time
      items[i][1] =
          rand() % (int)(arival_range - items[i][0]) + (int)items[i][0];
      // duration
      items[i][2] = items[i][1] - items[i][0];
      items[i][3] = i + 1;
    }

    // mode = 0 is according to arival_time
    quicksort(items, 0, n - 1, 0);
    int c1 = 1;
    curr_time = items[0][1];
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < n; i++) {
      if (items[i][0] < curr_time) {
        continue;
      } else {
        c1++;
        curr_time = items[i][1];
      }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << ", " << duration.count();

    // mode = 1 is according to final_time
    quicksort(items, 0, n - 1, 1);
    int c2 = 1;
    curr_time = items[0][1];
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < n; i++) {
      if (items[i][0] < curr_time) {
        continue;
      } else {
        c2++;
        curr_time = items[i][1];
      }
    }
    end = std::chrono::high_resolution_clock::now();
    duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << ", " << duration.count();

    // mode = 2 is according to duration
    quicksort(items, 0, n - 1, 2);
    float extras[n][COL];
    extras[0][0] = items[0][0];
    extras[0][1] = items[0][1];
    extras[0][2] = items[0][2];
    extras[0][3] = items[0][3];
    int c3 = 1;
    curr_time = items[0][1];
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < n; i++) {
      if (is_valid(extras, items[i], c3)) {
        extras[c3][0] = items[i][0];
        extras[c3][1] = items[i][1];
        extras[c3][2] = items[i][2];
        extras[c3][3] = items[i][3];
        c3++;
      }
    }
    end = std::chrono::high_resolution_clock::now();
    duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << ", " << duration.count();

    cout << "\n";
  }
  return 0;
}
