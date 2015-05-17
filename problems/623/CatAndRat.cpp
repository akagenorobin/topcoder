#include<cmath>
#include<cstdlib>
#include<sstream>
#include<string>
#include<vector>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<algorithm>
using namespace std;

#define PI asin(1) * 2

class CatAndRat{
public:
  double getTime(int R, int T, int Vrat, int Vcat){
    if(T==0) return 0;
    if(Vcat > Vrat){
      if(T< PI * R / Vrat) return (double)(Vrat * T) / (Vcat - Vrat);
      else return PI * (double)R / (Vcat - Vrat);
    }
    else return -1;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; double Arg4 = -1.0; verify_case(0, Arg4, getTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; double Arg4 = 1.0; verify_case(1, Arg4, getTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 2; int Arg3 = 1; double Arg4 = -1.0; verify_case(2, Arg4, getTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 1000; int Arg2 = 1; int Arg3 = 1000; double Arg4 = 1.001001001001001; verify_case(3, Arg4, getTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1000; int Arg2 = 1; int Arg3 = 2; double Arg4 = 3.141592653589793; verify_case(4, Arg4, getTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  CatAndRat test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
