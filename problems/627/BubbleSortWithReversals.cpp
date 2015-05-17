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

class BubbleSortWithReversals{
public:
  int bubble(vector<int> A){
    for(int i=0; i<A.size(); i++){
      cout << A[i] << " ";
    }
    cout << endl;
    int ans = 0;
    for(int i=0; i<A.size()-1; i++){
      for(int j=0; j<A.size()-1; j++){
	if(A[j] > A[j+1]){
	  swap(A[j], A[j+1]);
	  ans++;
	}
      }
    }
    // for(int i=0; i<A.size(); i++){
    //   cout << A[i] << " ";
    // }
    // cout << endl;
    return ans;
  }
  int getMinSwaps(vector <int> A, int K){
    vector<int> B = A;
    sort(B.begin(), B.end());
    vector<int> distance;
    distance.resize(A.size());
    for(int i=0; i<distance.size(); i++) distance[i] = 1000000;
    for(int i=0; i<A.size(); i++){
      for(int j=0; j<A.size(); j++){
	if(A[i] == B[j] && distance[i] == 1000000) distance[i] = j-i;
	if(A[i] == B[j] && j > i) distance[i] = min(distance[i], j-i);
	if(A[i] == B[j] && j < i) distance[i] = max(distance[i], j-i);
      }
    }
    for(int i=0; i<distance.size(); i++) cout << distance[i] << " ";
    cout << endl;
    for(int i=0; i<K; i++){
      for(int n=0; n<i; n++){


    }
    return bubble(A);
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,8,8,7,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(0, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {7,2,2,13,5,5,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {12,5,1,10,12,6,6,10,6,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 12; verify_case(2, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; verify_case(3, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {482,619,619,601,660,660,691,691,77,77,96,77}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 22; verify_case(4, Arg2, getMinSwaps(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  BubbleSortWithReversals test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
