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

class BestRoads {
public:
  vector <int> numberOfRoads(vector <string> roads, int M) {
    int N = roads.size();
    vector<int> ans;

    vector< vector<int> > link;
    link.resize(N);
    int R = 0;
    for(int i=0; i<N-1; i++){
      for(int j=i+1; j<N; j++){
	if(roads[i][j] == 'Y'){
	  link[i].push_back(j);
	  link[j].push_back(i);
	  R += 1;
	}
      }
    }
    /*
    for(int i=0; i<link.size(); i++){
      for(int j=0; j<link[i].size(); j++){
	cout << link[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    */
    if(R < M) return ans;

    vector<int> id;
    vector< set<int> > prior;
    prior.resize(N);
    int c = 0;
    id.resize(N);
    for(int i=0; i<N; i++) id[i] = i;
    for(int i=0; i<link.size(); i++){
      for(int j=0; j<link[i].size(); j++){
	if(id[i] != id[link[i][j]]){
	  prior[i].insert(link[i][j]);
	  prior[link[i][j]].insert(i);
	  for(int t=0; t<N; t++)
	    if(id[t] == id[link[i][j]]) id[t] = id[i];
	  M -= 1;
	  c += 1;
	}
      }
    }
    if(c != N-1) return ans;

    for(int i=0; i<prior.size(); i++){
      for(set<int>::iterator it=prior[i].begin(); it!=prior[i].end(); it++){
	cout << *it << " ";
      }
      cout << endl;
    }
    
    for(int i=0; i<link.size(); i++){
      if(M==0) break;
      for(int j=0; j<link[i].size(); j++){
	if(M==0) break;
	if(prior[i].count(link[i][j]) == 0){
	  prior[i].insert(link[i][j]);
	  prior[link[i][j]].insert(i);
	  M -= 1;
	}
      }
    }
    /*
    for(int i=0; i<prior.size(); i++){
      for(set<int>::iterator it=prior[i].begin(); it!=prior[i].end(); it++){
	cout << *it << " ";
      }
      cout << endl;
    }
    */
    ans.resize(N);
    for(int i=0; i<N; i++) ans[i] = prior[i].size();
    return ans;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"NYYYY","YNYYY","YYNYY","YYYNY","YYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arr2[] = {4, 4, 4, 4, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, numberOfRoads(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NYY","YNY","YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arr2[] = {2, 1, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, numberOfRoads(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYNNY","YNNNY","NNNNN","NNNNY","YYNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, numberOfRoads(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NYYNYYYN","YNNNNYYN","YNNNYNNN","NNNNNNYY","YNYNNNNN","YYNNNNYY","YYNYNYNY","NNNYNYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arr2[] = {5, 3, 2, 2, 2, 2, 3, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, numberOfRoads(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"NNYY","NNYY","YYNN","YYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, numberOfRoads(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  BestRoads test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
