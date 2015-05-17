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

class FibonacciDiv2 {
public:
  vector<int> dp;
  int fibo(int n){
    if(n == 0) return dp[n] = 0;
    if(n == 1) return dp[n] = 1;
    if(dp[n] != 0) return dp[n];
    return dp[n] = fibo(n-1) + fibo(n-2);
  }

  int find(int N) {
    dp.resize(1000000);
    int i = 0;
    while(true){
      if(fibo(i) > N) break;
      i++;
    }
    int ans = min(fibo(i) - N, N - fibo(i-1));
    return ans;
  }
};

// BEGIN CUT HERE
int main(){
  FibonacciDiv2 test;
  cout << test.find(13) << endl;
}
// END CUT HERE
