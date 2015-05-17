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

class LightSwitchingPuzzle{
public:
  int n;
  set<int> toggle(set<int> lights, int d){
    for(int i=1; i<=n/d; i++){
      set<int>::iterator it = lights.find(d*i);
      if(it == lights.end()) lights.insert(d*i);
      else lights.erase(it);
    }
    return lights;
  }

  int minFlips(string state){
    n = state.size();
    set<int> lights;
    for(int i=0; i<n; i++)
      if(state[i] == 'Y') lights.insert(i+1);

    int ans = 0;
    while(!lights.empty()){
      lights = toggle(lights, *lights.begin());
      ans++;
    }
    return ans;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YYYYYY"; int Arg1 = 1; verify_case(0, Arg1, minFlips(Arg0)); }
	void test_case_1() { string Arg0 = "YNYNYNYNY"; int Arg1 = 2; verify_case(1, Arg1, minFlips(Arg0)); }
	void test_case_2() { string Arg0 = "NNNNNNNNNN"; int Arg1 = 0; verify_case(2, Arg1, minFlips(Arg0)); }
	void test_case_3() { string Arg0 = "YYYNYYYNYYYNYYNYYYYN"; int Arg1 = 4; verify_case(3, Arg1, minFlips(Arg0)); }
	void test_case_4() { string Arg0 = "NYNNYNNNYNNNNYNNNNNYNNNNNNYNNNNNNNY"; int Arg1 = 12; verify_case(4, Arg1, minFlips(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  LightSwitchingPuzzle test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
