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

class TheGridDivTwo{
public:
  int find(vector <int> x, vector <int> y, int k){
    set< pair<int,int> > blocks;
    for(int i=0; i<x.size(); i++){
      blocks.insert(make_pair(x[i],y[i]));
    }
    pair<int,int> p,pnew;
    queue< pair<int,int> > q,qnew;
    set< pair<int,int> > s;
    q.push(make_pair(0,0));
    s.insert(make_pair(0,0));
    for(int t=0; t<k; t++){
      bool judge = true;
      //cout << "t = " << t << endl;
      while(!q.empty()){
	p = q.front();
	q.pop();
	for(int i=0; i<x.size(); i++){
	  if(x[i] > p.first){
	    judge = false;
	    break;
	  }
	}
	if(judge){
	  //cout << p.first << " " << p.second << endl;
	  s.insert(make_pair(p.first+k-t,p.second));
	}
	//cout << p.first << " " << p.second << endl;
	for(int n=0; n<4; n++){
	  if(n==0){
	    pnew = make_pair(p.first+1,p.second);
	  }
	  if(n==1){
	    pnew = make_pair(p.first-1,p.second);
	  }
	  if(n==2){
	    pnew = make_pair(p.first,p.second+1);
	  }
	  if(n==3){
	    pnew = make_pair(p.first,p.second-1);
	  }
	  if(s.count(pnew)) continue;
	  if(blocks.count(pnew)==0){
	    s.insert(pnew);
	    qnew.push(pnew);
	  }
	}
      }
      if(judge) break;
      q = qnew;
      //cout << endl;
    }
    int xmax = 0;
    for(set< pair<int,int> >::iterator it=s.begin(); it!=s.end(); it++){
      if(it->first>xmax) xmax = it->first;
    }
    return xmax;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2,-1,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 2; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {-1, 0, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -1, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = 0; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; int Arg3 = 1000; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,0,0,-1,-1,-2,-2,-3,-3,-4,-4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,-1,1,-2,2,-3,3,-4,4,-5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; int Arg3 = 31; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  TheGridDivTwo test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
