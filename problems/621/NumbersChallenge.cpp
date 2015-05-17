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

class NumbersChallenge {
public:
  vector<int> a;
  bool dfs(int i, int sum, int n){
    if(sum == n) return true;
    if(i == a.size()) return sum == n;
    if(dfs(i+1,sum,n)) return true;
    if(dfs(i+1,sum+a[i],n)) return true;
    return false;
  }
  int MinNumber(vector <int> S) {
    a = S;
    int n = 1;
    while(dfs(0,0,n)) n++;
    return n;
  }
};

// BEGIN CUT HERE
int main(){
	NumbersChallenge test;
	//cout << test.MinNumber() << endl;
}
// END CUT HERE
