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

class DevuAndPlantingTrees{
public:
  vector<string> g;
  int n;
  bool free(int i, int j){
    if(g[i][j]!='.') return false;
    else if(i==0){
      if(j==0){
	if(g[0][1]=='.' && g[1][0]=='.' && g[1][1]=='.')
	  return true;
	else
	  return false;
      }
      else if(j==n-1){
	if(g[0][n-2]=='.' && g[1][n-1]=='.' && g[1][n-2]=='.')
	  return true;
	else
	  return false;
      }
      else{
	if(g[0][j-1]=='.' && g[0][j+1]=='.' && g[1][j-1]=='.' && g[1][j]=='.' && g[1][j+1]=='.')
	  return true;
	else
	  return false;
      }
    }
    else{
      if(j==0){
	if(g[1][1]=='.' && g[0][0]=='.' && g[0][1]=='.')
	  return true;
	else
	  return false;
      }
      else if(j==n-1){
	if(g[1][n-2]=='.' && g[0][n-1]=='.' && g[0][n-2]=='.')
	  return true;
	else
	  return false;
      }
      else{
	if(g[1][j-1]=='.' && g[1][j+1]=='.' && g[0][j-1]=='.' && g[0][j]=='.' && g[0][j+1]=='.')
	  return true;
	else
	  return false;
      }
    }
  }

  int maximumTreesDevuCanGrow(vector <string> garden){
    g = garden;
    n = garden[0].size();
    for(int i=0; i<2; i++){
      for(int j=0; j<n; j++){
	if(free(i,j)) g[i][j] = '*';
      }
    }
    int ans = 0;
    for(int i=0; i<2; i++){
      for(int j=0; j<n; j++){
	if(g[i][j]!='.') ans++;
	//cout << g[i][j];
      }
      //cout << endl;
    }
    return ans;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..", ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maximumTreesDevuCanGrow(Arg0)); }
	void test_case_1() { string Arr0[] = {"..", ".*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, maximumTreesDevuCanGrow(Arg0)); }
	void test_case_2() { string Arr0[] = {"...",
"..*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, maximumTreesDevuCanGrow(Arg0)); }
	void test_case_3() { string Arr0[] = {".....*..........",
".*.......*.*..*."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, maximumTreesDevuCanGrow(Arg0)); }
	void test_case_4() { string Arr0[] = {"....*.*.*...........*........",
"*..........*..*.*.*....*...*."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(4, Arg1, maximumTreesDevuCanGrow(Arg0)); }
	void test_case_5() { string Arr0[] = {".....*..*..........*............................*",
"*..*.............*...*.*.*.*..*.....*.*...*...*.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 23; verify_case(5, Arg1, maximumTreesDevuCanGrow(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  DevuAndPlantingTrees test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
