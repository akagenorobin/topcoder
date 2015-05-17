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

class HappyLetterDiv2{
public:
  char getHappyLetter(string letters){
    map<char, int> dic;
    for(int i=0; i<letters.size(); i++){
      if(dic.count(letters[i])) dic[letters[i]]++;
      else dic.insert(map<char, int>::value_type(letters[i], 1));
    }
    char happy = '.';
    int lmax = 0;
    for(map<char, int>::iterator it = dic.begin(); it != dic.end(); it++){
      // cout << it->first << " " << it->second << endl;
      if(it->second > lmax){
	happy = it->first;
	lmax = it->second;
      }
    }
    // cout << lmax << " " << letters.size()/2 << endl;
    if(lmax > letters.size()/2) return happy;
    else return '.';
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const char &Expected, const char &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aacaaa"; char Arg1 = 'a'; verify_case(0, Arg1, getHappyLetter(Arg0)); }
	void test_case_1() { string Arg0 = "dcdjx"; char Arg1 = '.'; verify_case(1, Arg1, getHappyLetter(Arg0)); }
	void test_case_2() { string Arg0 = "bcbbbbba"; char Arg1 = 'b'; verify_case(2, Arg1, getHappyLetter(Arg0)); }
	void test_case_3() { string Arg0 = "aabc"; char Arg1 = '.'; verify_case(3, Arg1, getHappyLetter(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  HappyLetterDiv2 test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
