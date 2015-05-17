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

class AddMultiply {
public:
  vector <int> makeExpression(int y) {
    vector<int> x;
    x.resize(3);
    x[0] = 30;
    x[1] = 30;
    x[2] = y - 900;
    return x;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 6; int Arr1[] = {2, 2, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, makeExpression(Arg0)); }
	void test_case_1() { int Arg0 = 11; int Arr1[] = {2, 3, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, makeExpression(Arg0)); }
	void test_case_2() { int Arg0 = 0; int Arr1[] = {7, 10, -70 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, makeExpression(Arg0)); }
	void test_case_3() { int Arg0 = 500; int Arr1[] = {-400, -3, -700 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, makeExpression(Arg0)); }
	void test_case_4() { int Arg0 = 2; int Arr1[] = {2, 2, -2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, makeExpression(Arg0)); }
	void test_case_5() { int Arg0 = 5; int Arr1[] = {5, 2, -5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, makeExpression(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  AddMultiply test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
