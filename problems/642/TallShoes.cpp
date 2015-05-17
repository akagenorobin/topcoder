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

class TallShoes{
public:
  vector< vector< pair<int,int> > > connect;
  int n;

  bool possible(int i, long long h, long long B, vector<bool> used){
    //cout << i << " " << h << " " << B << endl;
    bool judge = false;
    if(i == n-1) return true;
    used[i] = true;
    for(int j=0; j<connect[i].size(); j++){
      int k = connect[i][j].first;
      int c = connect[i][j].second;
      if(!used[k]){
	if(h <= c) judge = possible(k, h, B, used);
	else if(B >= (h-c)*(h-c)) judge = possible(k, h, B-(h-c)*(h-c), used);
      }
      if(judge) return true;
    }
    return judge;
  }


  int maxHeight(int N, vector <int> X, vector <int> Y, vector <int> height, long long B){
    n = N;

    connect.resize(n);
    for(int i=0; i<X.size(); i++){
      connect[X[i]].push_back(make_pair(Y[i], height[i]));
      connect[Y[i]].push_back(make_pair(X[i], height[i]));
    }
    long long hmin = 1000000;
    for(int i=0; i<n; i++)
      if(hmin > height[i]) hmin = height[i];
    hmin += (int)(pow(B/(n-1), 0.5));

    vector<bool> used;
    used.resize(n);
    for(int i=0; i<n; i++) used[i] = false;
    long long h = hmin;
    bool judge = true;
    while(judge){
      h++;
      judge = possible(0, h, B, used);
    }

    return h-1;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 4, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 1LL; int Arg5 = 4; verify_case(0, Arg5, maxHeight(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 4, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 52LL; int Arg5 = 9; verify_case(1, Arg5, maxHeight(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 8; int Arr1[] = {0, 0, 3, 3, 4, 4, 4, 7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 1, 2, 3, 5, 6, 5, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1000, 1000, 1000, 1000, 1, 1000, 1000, 1000, 1000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 3LL; int Arg5 = 2; verify_case(2, Arg5, maxHeight(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {0,1,2,3,4,5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0,0,0,0,0,0,0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 9876543210123LL; int Arg5 = 1047565; verify_case(3, Arg5, maxHeight(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 6; int Arr1[] = {0,0,0,0,0,1,1,1,1,2,2,2,3,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,2,3,4,5,3,4,5,4,5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {999999,986588,976757,988569,977678,999999,967675,947856,955856,999999,975956,956687,999999,979687,999999}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 0LL; int Arg5 = 999999; verify_case(4, Arg5, maxHeight(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  TallShoes test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
