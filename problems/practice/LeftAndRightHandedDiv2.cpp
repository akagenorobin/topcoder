#include<cmath>
#include<cstdlib>
#include<cstdio>
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

class LeftAndRightHandedDiv2 {
public:
  int count(string S) {
    int c = 0;
    for(int i=0; i<S.length()-1; i++){
      if(S[i] == 'R' && S[i+1] == 'L') c++;
    }
    return c;
  }
};

// BEGIN CUT HERE
int main(){
  LeftAndRightHandedDiv2 test;
  cout << test.count("RLRLRLRLLLRRLLLRLRLRL") << endl;
}
// END CUT HERE
