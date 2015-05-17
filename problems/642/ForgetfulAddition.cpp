#include<cmath>
#include<cstdlib>
#include<sstream>
#include<string>
#include<vector>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<algorithm>
using namespace std;

class ForgetfulAddition{
public:
  int minNumber(string expression){
    int nmin = 999999999;
    for(int n=1; n<expression.size(); n++){
      string s1 = "";
      string s2 = "";
      for(int i=0; i<n; i++) s1 += expression[i];
      for(int i=n; i<expression.size(); i++) s2 += expression[i];
      int n1 = atoi(s1.c_str());
      int n2 = atoi(s2.c_str());
      if(n1 + n2 < nmin) nmin = n1 + n2;
    }
    return nmin;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "22"; int Arg1 = 4; verify_case(0, Arg1, minNumber(Arg0)); }
	void test_case_1() { string Arg0 = "123"; int Arg1 = 15; verify_case(1, Arg1, minNumber(Arg0)); }
	void test_case_2() { string Arg0 = "1289"; int Arg1 = 101; verify_case(2, Arg1, minNumber(Arg0)); }
	void test_case_3() { string Arg0 = "31415926"; int Arg1 = 9067; verify_case(3, Arg1, minNumber(Arg0)); }
	void test_case_4() { string Arg0 = "98765"; int Arg1 = 863; verify_case(4, Arg1, minNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  ForgetfulAddition test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
