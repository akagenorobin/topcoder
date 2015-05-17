#include<cmath>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>
#include<iostream>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<list>
#include<algorithm>
using namespace std;

class Subsets {
public:
  map<int, int> ma;
  int ans;
  
  void dfs(map<int, int>::iterator it, map<int, int> ref, int sum, int product){
    if(it == ma.end() && sum > product){
      for(map<int, int>::iterator jt = ref.begin(); jt != ref.end(); jt++){
       	cout << jt->second << " ";
      }
      cout << endl;
      ans++;
    }
    if(sum + it->first >= product * it->first){
      if(it != ma.end() && ref[it->first] < it->second){
	ref[it->first]++;
	dfs(it, ref, sum + it->first, product * it->first);
	ref[it->first] -= 1;
      }
    }
    if(it != ma.end()){
      it++;
      dfs(it, ref, sum, product);
    }
  }
  
  int findSubset(vector <int> numbers) {
    sort(numbers.begin(), numbers.end());
    ans = 0;

    for(int i=0; i<numbers.size(); i++){
      if(ma.find(numbers[i]) != ma.end()) ma[numbers[i]]++;
      else ma.insert(map<int, int>::value_type(numbers[i], 1));
    }
    map<int, int> ref;
    ref = ma;
    for(map<int, int>::iterator it = ref.begin(); it != ref.end(); it++){
      it->second = 0;
      // cout << it->first << " " << it->second << endl;
    }

    dfs(ma.begin(), ref, 0, 1);
    return ans;
  }

  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, findSubset(Arg0)); }
  void test_case_1() { int Arr0[] = {1,1,1,1,2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(1, Arg1, findSubset(Arg0)); }
  void test_case_2() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, findSubset(Arg0)); }
  void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,10,20,30,40,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 77; verify_case(3, Arg1, findSubset(Arg0)); }
  void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,2,3,4,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(4, Arg1, findSubset(Arg0)); }
  void test_case_5() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
				     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
				     1,1,1,1,1,1,2,2,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8050; verify_case(5, Arg1, findSubset(Arg0)); }
  void test_case_6() { int Arr0[] = {5,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, findSubset(Arg0)); }
  // END CUT HERE
};

// BEGIN CUT HERE
int main(){
  Subsets test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
