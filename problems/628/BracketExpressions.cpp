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

class BracketExpressions {
public:
  string ifPossible(string expression) {
    stack<char> s;
    s.push(expression[0]);
    int i = 1;
    while(true){
      if(i == expression.size()) break;
      if(s.empty()) s.push(expression[i]);
      else{
	char c = s.top();
	if(c == '(' && expression[i] == ')') s.pop();
	else if(c == '{' && expression[i] == '}') s.pop();
	else if(c == '[' && expression[i] == ']') s.pop();
	else s.push(expression[i]);
      }
      i++;
    }
    if(s.empty()) return "possible";

    stack<char> s2;
    s2.push(s.top());
    s.pop();
    while(true){
      if(s.empty()) break;
      char c = s.top();
      if(s2.empty()) s2.push(c);
      else{
	char c2 = s2.top();
	if((c == '(' || c == 'X') && (c2 == ')' || c2 == 'X')) s2.pop();
	else if((c == '{' || c == 'X') && (c2 == '}' || c2 == 'X')) s2.pop();
	else if((c == '[' || c == 'X') && (c2 == ']' || c2 == 'X')) s2.pop();
	else s2.push(c);
      }
      s.pop();
    }
    return s2.empty() ? "possible" : "impossible";
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "([]{})"; string Arg1 = "possible"; verify_case(0, Arg1, ifPossible(Arg0)); }
	void test_case_1() { string Arg0 = "(())[]"; string Arg1 = "possible"; verify_case(1, Arg1, ifPossible(Arg0)); }
	void test_case_2() { string Arg0 = "({])"; string Arg1 = "impossible"; verify_case(2, Arg1, ifPossible(Arg0)); }
	void test_case_3() { string Arg0 = "[]X"; string Arg1 = "impossible"; verify_case(3, Arg1, ifPossible(Arg0)); }
	void test_case_4() { string Arg0 = "([]X()[()]XX}[])X{{}}]"; string Arg1 = "possible"; verify_case(4, Arg1, ifPossible(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  BracketExpressions test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
