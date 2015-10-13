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

class Drbalance{
public:
  int lesscng(string s, int k){
      vector<int> v;
      int n = s.size();
      v.resize(n);
      int nega = 0;
      if(s[0] == '+') v[0] = 1;
      else{
          v[0] = -1;
          nega = 1;
      }
      for(int i=1; i<n; i++){
          if(s[i] == '+') v[i] = v[i-1] + 1;
          else v[i] = v[i-1] - 1;
          if(v[i] < 0) nega += 1;
      }
      int count = 0;
      int p = 0;
      while(nega > k){
          for(int i=0; i<n; i++){
              if(s[i] == '-'){
                  s[i] = '+';
                  p = i;
                  break;
              }
          }
          for(int i=p; i<n; i++){
              if(v[i] < 0){
                  v[i] += 2;
                  if(v[i] >= 0) nega -= 1;
              }
          }
          cout << s << endl;
          count++;
      }
      return count;
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "---"; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "+-+-"; int Arg1 = 0; int Arg2 = 0; verify_case(1, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "-+-+---"; int Arg1 = 2; int Arg2 = 1; verify_case(2, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "-------++"; int Arg1 = 3; int Arg2 = 3; verify_case(3, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "-+--+--+--++++----+"; int Arg1 = 3; int Arg2 = 2; verify_case(4, Arg2, lesscng(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  Drbalance test;
  //int n;
  //cin >> n;
  //test.run_test(n);
  cout << test.lesscng("-----+-----+--++---+---++---+--+----+-+---", 22) << endl;
  cout << test.lesscng("---+------+-+-++--+--+---+-+------", 28) << endl;

}
// END CUT HERE
