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

class DoubleWeights{
public:
    int n;
    vector <string> w1;
    vector <string> w2;
    int dfs(int i, int cost1, int cost2, vector<int> pass){
        if(i == 1) return cost1 * cost2;
        pass.push_back(i);
        int ans = 1000000;
        for(int j=0; j<n; j++){
            if(w1[i][j] == '.' || find(pass.begin(), pass.end(), j) != pass.end())
                continue;
            cost1 += (int)w1[i][j] - (int)'0';
            cost2 += (int)w2[i][j] - (int)'0';
            int c = dfs(j, cost1, cost2, pass);
            cost1 -= (int)w1[i][j] - (int)'0';
            cost2 -= (int)w2[i][j] - (int)'0';
            if(c < ans) ans = c;
        }
        return ans;
    }

    int minimalCost(vector <string> weight1, vector <string> weight2){
        n = weight1.size();
        w1 = weight1;
        w2 = weight2;
        vector<int> pass;
        int ans = dfs(0, 0, 0, pass);
        if(ans == 1000000) return -1;
        else return ans;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..14",
 "..94",
 "19..",
 "44.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..94",
 "..14",
 "91..",
 "44.."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 64; verify_case(0, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"..14",
 "..14",
 "11..",
 "44.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..94",
 "..94",
 "99..",
 "44.."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 36; verify_case(1, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..",
 ".."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".....9",
 "..9...",
 ".9.9..",
 "..9.9.",
 "...9.9",
 "9...9."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".....9",
 "..9...",
 ".9.9..",
 "..9.9.",
 "...9.9",
 "9...9."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2025; verify_case(3, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".4...1",
 "4.1...",
 ".1.1..",
 "..1.1.",
 "...1.1",
 "1...1."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".4...1",
 "4.1...",
 ".1.1..",
 "..1.1.",
 "...1.1",
 "1...1."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; verify_case(4, Arg2, minimalCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
    DoubleWeights test;
    int n;
    cout << "test number: ";
    cin >> n;
    test.run_test(n);
}
// END CUT HERE
