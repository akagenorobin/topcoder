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

class BoxesDiv2 {
public:
  int findSize(vector <int> candyCounts) {
    int v = 0;
    for(vector<int>::iterator it = candyCounts.begin(); it != candyCounts.end(); it++){
      int i = 0;
      while(pow(2,i) < *it) i++;
      v += pow(2,i);
    }
    int i = 0;
    while(pow(2,i) < v) i++;
    return pow(2,i);
  }
};

// BEGIN CUT HERE
int main(){
  BoxesDiv2 test;
  //  cout << test.findSize() << endl;
}
// END CUT HERE
