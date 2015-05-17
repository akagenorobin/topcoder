#include<cmath>
#include<cstdlib>
#include<sstream>
#include<string>
#include<vector>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<map>
#include<algorithm>
using namespace std;

#define MAX_N 51

class ApplesAndPears{
public:
  map<char, vector< vector<int> > > ref;

  int rect(char c, int x0, int y0, int x1, int y1){
    vector< vector<int> > table = ref[c];
    return table[x1][y1] - table[x1][y0] - table[x0][y1] + table[x0][y0];
  }

  int getArea(vector <string> board, int K){
    int n = board.size();
    vector< vector<int> > table;
    table.resize(MAX_N);
    for(int i=0; i<MAX_N; i++) table[i].resize(MAX_N);
    ref.insert(map<char, vector< vector<int> > >::value_type('A', table));
    ref.insert(map<char, vector< vector<int> > >::value_type('P', table));
    ref.insert(map<char, vector< vector<int> > >::value_type('.', table));

    for(int x=0; x<=n; x++){
      int a = 0;
      int p = 0;
      int e = 0;
      for(int y=0; y<=n; y++){
	if(x == 0 || y == 0){
	  ref['A'][x][y] = 0;
	  ref['P'][x][y] = 0;
	  ref['.'][x][y] = 0;
	}
	else{
	  if(board[x-1][y-1] == 'A') a++;
	  if(board[x-1][y-1] == 'P') p++;
	  if(board[x-1][y-1] == '.') e++;
	  ref['A'][x][y] = a + ref['A'][x-1][y];
	  ref['P'][x][y] = p + ref['P'][x-1][y];
	  ref['.'][x][y] = e + ref['.'][x-1][y];
	}
      }
    }
    /*
    for(int x=0; x<=n; x++){
      for(int y=0; y<=n; y++){
     	cout << x << " " << y << " " << ref['A'][x][y] << endl;
      }
    }
    */
    int A = rect('A', 0, 0, n, n);
    int P = rect('P', 0, 0, n, n);
    int E = rect('.', 0, 0, n, n);
    // cout << A << " " << P << " " << E << endl;
    int ans = 0;
    for(int x0=0; x0<=n-1; x0++){
      for(int y0=0; y0<=n-1; y0++){
	for(int x1=x0+1; x1<=n; x1++){
	  for(int y1=y0+1; y1<=n; y1++){
	    int S = (x1 - x0) * (y1 - y0);
	    int a = rect('A', x0, y0, x1, y1);
	    int p = rect('P', x0, y0, x1, y1);
	    int e = rect('.', x0, y0, x1, y1);
	    if(S <= A && 2*p+e <= K && (p == 0 || E > 0)) ans = max(ans, S);
	    if(S <= P && 2*a+e <= K && (a == 0 || E > 0)) ans = max(ans, S);
	    if(S <= E && a+p <= K) ans = max(ans, S);
	  }
	}
      }
    }
    return ans;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".A",
 "P."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getArea(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".A",
 "P."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, getArea(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".PP", 
 "PPA", 
 "PAP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(2, Arg2, getArea(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"A.P.PAAPPA",
 "PPP..P.PPP",
 "AAP.A.PAPA",
 "P.PA.AAA.A",
 "...PA.P.PA",
 "P..A.A.P..",
 "PAAP..A.A.",
 "PAAPPA.APA",
 ".P.AP.P.AA",
 "..APAPAA.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 21; verify_case(3, Arg2, getArea(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  ApplesAndPears test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
