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

class RGBTree{
public:
    string exist(vector <string> G){

    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".RGB",
 "R...",
 "G...",
 "B..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Exist"; verify_case(0, Arg1, exist(Arg0)); }
	void test_case_1() { string Arr0[] = {".RRB",
 "R...",
 "R...",
 "B..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Does not exist"; verify_case(1, Arg1, exist(Arg0)); }
	void test_case_2() { string Arr0[] = {".R..BG..G..RG","R...GG..BR.G.","...G.GG.RR.BB","..G.RR.B..GRB","BG.R.G.BRRR.G","GGGRG.R....RR","..G..R.BGRR..","...BB.B.RB.G.","GBR.R.GR.B.R.",".RR.R.RBB.BRB","...GR.R..B...","RGBR.R.GRR...","G.BBGR...B..."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Exist"; verify_case(2, Arg1, exist(Arg0)); }
	void test_case_3() { string Arr0[] = {".............",".......BB.R..",".......RR....",".....G.G....R","........BB...","...G.........","........B...R",".BRG.......G.",".BR.B.B...GB.","....B......GR",".R......G....",".......GBG..B","...R..R..R.B."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Does not exist"; verify_case(3, Arg1, exist(Arg0)); }
	void test_case_4() { string Arr0[] = {"..B.BB...RB..","......R..B.G.","B.......BB...",".......R...G.","B....GRB..R..","B...G.RG.R...",".R..RR..B.RB.","...RBG...G...","..B...B......","RBB..R.G....R","B...R.R......",".G.G..B.....R",".........R.R."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Exist"; verify_case(4, Arg1, exist(Arg0)); }
	void test_case_5() { string Arr0[] = {"....",
 "....",
 "....",
 "...."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Does not exist"; verify_case(5, Arg1, exist(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
    RGBTree test;
    int n;
    cout << "test number: ";
    cin >> n;
    test.run_test(n);
}
// END CUT HERE
