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
#include<set>
#include<algorithm>
using namespace std;

class GameOfSegments {
public:
  int mem[1001];
  int grundy(int i){
    if(mem[i] != -1) return mem[i];
    set<int> s;
    for(int j=0; j<(i-2)/2+1; j++){
      s.insert(grundy(j) ^ grundy(i-j-2));
    }

    int res = 0;
    while(s.count(res)) res++;
    return mem[i] = res;
  }

  int winner(int N) {
    for(int i=0; i<1001; i++) mem[i] = -1;
    mem[0] = 0;
    mem[1] = 0;
    mem[2] = 1;
    for(int i=3; i<1001; i++){
      if(grundy(i) == 0)
	cout << i << endl;
    }
    return grundy(N) == 0 ? 2 : 1;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; verify_case(0, Arg1, winner(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 1; verify_case(1, Arg1, winner(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 2; verify_case(2, Arg1, winner(Arg0)); }
	void test_case_3() { int Arg0 = 191; int Arg1 = 2; verify_case(3, Arg1, winner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  GameOfSegments test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
