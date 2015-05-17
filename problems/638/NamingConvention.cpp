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

class NamingConvention{
public:
  string toCamelCase(string variableName) {
    for(string::iterator it = variableName.begin(); it != variableName.end(); it++){
      if(*it == '_'){
	it = variableName.erase(it);
	*it = toupper(*it);
      }
    }
    return variableName;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "sum_of_two_numbers"; string Arg1 = "sumOfTwoNumbers"; verify_case(0, Arg1, toCamelCase(Arg0)); }
	void test_case_1() { string Arg0 = "variable"; string Arg1 = "variable"; verify_case(1, Arg1, toCamelCase(Arg0)); }
	void test_case_2() { string Arg0 = "t_o_p_c_o_d_e_r"; string Arg1 = "tOPCODER"; verify_case(2, Arg1, toCamelCase(Arg0)); }
	void test_case_3() { string Arg0 = "the_variable_name_can_be_very_long_like_this"; string Arg1 = "theVariableNameCanBeVeryLongLikeThis"; verify_case(3, Arg1, toCamelCase(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  NamingConvention test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
