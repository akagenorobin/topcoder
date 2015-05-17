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

class RelativelyPrimeSubset {
public:
  vector<int> prime = {2,3,5,7,11,13,17,18,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};

  vector<int> ex(vector<int> x, vector<int> y){
    vector<int> z;
    z.resize(x.size());
    for(int i=0; i<x.size(); i++){
      if(x[i]==y[i]) z[i] = 0;
      else z[i] = 1;
    }
    return z;
  }

  int findSize(vector <int> S) {
    int N = S.size();
    sort(S.begin(), S.end());
    int ans = 0;
    if(S[0]==1) ans = 1;

    int imax = 0;
    for(int i=0; i<prime.size(); i++){
      for(int j=0; j<N; j++){
	if(S[j]%prime[i]==0){
	  imax = i;
	  break;
	}
      }
    }

    vector< vector<int> > v;
    v.resize(N);
    for(int j=0; j<N; j++) v[j].resize(imax+1);
    
    for(int i=0; i<=imax; i++){
      for(int j=0; j<N; j++){
	if(S[j]%prime[i]==0) v[j][i] = 1;
	else v[j][i] = 0;
      }
    }

    for(int j=0; j<N; j++){
      for(int i=0; i<=imax; i++){
	cout << v[j][i] << " ";
      }
      cout << endl;
    }

    for(int i=0; i<N; i++){
      vector<int> w = v[i];
      for(int j=0; j<N; j++){
	bool judge = false;
	for(int k=0; k<=imax; k++){
	  if(v[j][k]==1) judge = true;
	}
	if(judge){
	  v[j] = ex(w,v[j]);
	}
      }
    }

    cout << endl;
    for(int j=0; j<N; j++){
      for(int i=0; i<=imax; i++){
	cout << v[j][i] << " ";
      }
      cout << endl;
    }

    for(int j=0; j<N; j++){
      bool judge = false;
      for(int i=0; i<=imax; i++){
	if(v[j][i]==1) judge = true;
      }
      if(judge) ans++;
    }

    return ans;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3,7,11,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, findSize(Arg0)); }
	void test_case_1() { int Arr0[] = {4,8,12,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, findSize(Arg0)); }
	void test_case_2() { int Arr0[] = {100,17,81,82}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, findSize(Arg0)); }
	void test_case_3() { int Arr0[] = {2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, findSize(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  RelativelyPrimeSubset test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
