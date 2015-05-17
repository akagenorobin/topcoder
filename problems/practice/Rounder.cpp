#include<cmath>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>
#include<iostream>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<list>
#include<algorithm>
using namespace std;

class Rounder {
public:
  int round(int n, int b) {
    int m1 = b * (int)(n / b);
    int m2 = b * ((int)(n / b) + 1);
    //cout << m1 << " " << m2 << endl;
    if(n - m1 >= m2 - n) return m2;
    else return m1;
  }
};

// BEGIN CUT HERE
int main(){
  Rounder test;
  cout << test.round(123456, 7) << endl;
}
// END CUT HERE
