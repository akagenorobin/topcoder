#include<cmath>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>
#include<iostream>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<stack>
#include<list>
#include<algorithm>
using namespace std;

class BishopMove {
public:
  int howManyMoves(int r1, int c1, int r2, int c2) {
    int p1 = r1 * 8 + c1;
    int p2 = r2 * 8 + c2;
    set<int> s1, s2;
    for(int i=0; i<8; i++){
      for(int j=0; j<8; j++){
	if((i+j)%2 == 0) s1.insert(i*8+j);
	else s2.insert(i*8+j);
      }
    }
    if((s1.count(p1) && s2.count(p2)) || (s1.count(p2) && s2.count(p1))) return -1;
    else if(p1 == p2) return 0;
    else if((abs(p1 - p2)%7 == 0) || (abs(p1 - p2)%7 == 0)) return 1;
    else return 2;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 7; int Arg3 = 3; int Arg4 = 1; verify_case(0, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 5; int Arg2 = 2; int Arg3 = 5; int Arg4 = 0; verify_case(1, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 5; int Arg3 = 5; int Arg4 = 2; verify_case(2, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 7; int Arg3 = 4; int Arg4 = -1; verify_case(3, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  BishopMove test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
