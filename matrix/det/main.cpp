#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

void det(vector<vector<int> > a, int x, int y, int row_to_skip, int &d, int c, int n){
  if(n-y <= 2){
    cout<<"yo";
    return;
  }
  for(int i=0;i<n-y-3;i++){
    det(a,x+1,y+1,row_to_skip+i+1,d,c,n);
  }
}

int main() {
  srand(time(NULL));
  int n = 3;
  vector<vector<int> > a(n,vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      // a[i][j] = rand() % 100;
      a[i][j] = i;
    }
  }
  int d = 0;
  det(a,1,1,0,d,0,n);
  return 0;
}
