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

class ManySquares{
public:
  int howManySquares(vector <int> sticks){
    map<int, int> dic;
    for(int i=0; i<sticks.size(); i++){
      if(dic.count(sticks[i])) dic[sticks[i]]++;
      else dic.insert(map<int, int>::value_type(sticks[i], 1));
    }
    int ans = 0;
    for(map<int, int>::iterator it = dic.begin(); it != dic.end(); it++){
      ans += it->second / 4;
      // cout << it->first << " " << it->second << endl;
    }
    cout << ans << endl;
    return ans;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,2,2,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, howManySquares(Arg0)); }
	void test_case_1() { int Arr0[] = {3, 1, 4, 4, 4, 10, 10, 10, 10}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, howManySquares(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,1,2,3,4,1,2,3,1,2,3,4,1,2,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, howManySquares(Arg0)); }
	void test_case_3() { int Arr0[] = {1,1,1,2,2,2,3,3,3,4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, howManySquares(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1,1,2,1,1,1,3,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, howManySquares(Arg0)); }
	void test_case_5() { int Arr0[] = {2,2,4,4,8,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, howManySquares(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  ManySquares test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
