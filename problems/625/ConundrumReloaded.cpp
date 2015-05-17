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

class ConundrumReloaded {
public:
  int localmin(string s){
    vector<int> v;
    v.resize(s.size());
    v[0] = 1;
    for(int i=1; i<s.size(); i++){
      if(s[i-1] == 'H') v[i] = v[i-1];
      if(s[i-1] == 'L') v[i] = -v[i-1];
    }
    int a = 0;
    for(int i=0; i<s.size(); i++){
      if(v[i] == -1) a++;
    }
    v[0] = -1;
    for(int i=1; i<s.size(); i++){
      if(s[i-1] == 'H') v[i] = v[i-1];
      if(s[i-1] == 'L') v[i] = -v[i-1];
    }
    int b = 0;
    for(int i=0; i<s.size(); i++){
      if(v[i] == -1) b++;
    }
    return min(a,b);
  }
  int minimumLiars(string answers){
    int n = answers.size();
    if(answers.find('?') == string::npos){
      bool judge = true;
      int a = 1000;
      int b = 1000;
      vector<int> v;
      v.resize(answers.size());
      v[0] = 1;
      for(int i=1; i<answers.size(); i++){
	if(answers[i-1] == 'H') v[i] = v[i-1];
	if(answers[i-1] == 'L') v[i] = -v[i-1];
      }
      if(answers[n-1] == 'H' && v[n-1] != v[0]) judge = false;
      if(answers[n-1] == 'L' && v[n-1] != -v[0]) judge = false;
      if(judge){
	a = 0;
	for(int i=1; i<v.size(); i++){
	  if(v[i] == -1) a++;
	}
      }
      v[0] = -1;
      for(int i=1; i<answers.size(); i++){
	if(answers[i-1] == 'H') v[i] = v[i-1];
	if(answers[i-1] == 'L') v[i] = -v[i-1];
      }
      if(answers[n-1] == 'H' && v[n-1] != v[0]) judge = false;
      if(answers[n-1] == 'L' && v[n-1] != -v[0]) judge = false;
      if(judge){
	b = 0;
	for(int i=1; i<v.size(); i++){
	  if(v[i] == -1) b++;
	}
      }
      if(a == 1000 && b == 1000) return -1;
      else return min(a,b);
    }
    else{
      vector<string> s;
      int i = 0;
      while(answers.find('?') != string::npos){
	s.push_back(answers.substr(0, answers.find('?')+1));
	answers = answers.substr(answers.find('?')+1);
	if(answers.find('?') == string::npos) s.push_back(answers);
      }
      if(s[s.size()-1].find('?') == string::npos){
	s[0] = s[s.size()-1] + s[0];
	s.pop_back();
      }
      int res = 0;
      for(int i=0; i<s.size(); i++){
	cout << s[i] <<  " " << localmin(s[i]) << endl;
	res += localmin(s[i]);
      }
      return res;
    }
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LLH"; int Arg1 = 1; verify_case(0, Arg1, minimumLiars(Arg0)); }
	void test_case_1() { string Arg0 = "?????"; int Arg1 = 0; verify_case(1, Arg1, minimumLiars(Arg0)); }
	void test_case_2() { string Arg0 = "LHLH?"; int Arg1 = 2; verify_case(2, Arg1, minimumLiars(Arg0)); }
	void test_case_3() { string Arg0 = "??LLLLLL??"; int Arg1 = 3; verify_case(3, Arg1, minimumLiars(Arg0)); }
	void test_case_4() { string Arg0 = "LLL"; int Arg1 = -1; verify_case(4, Arg1, minimumLiars(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  ConundrumReloaded test;
  cout << test.minimumLiars("LHLH?LHLHLLHLHLLHLH?HLHLLH????HLLLH?L") << endl;
  cout << test.minimumLiars("????????????HLH?LH?LLLLL??LHH?????HHH????H???????") << endl;

  // int n;
  // cin >> n;
  // test.run_test(n);
}
// END CUT HERE
