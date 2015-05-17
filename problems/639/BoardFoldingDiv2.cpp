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

class BoardFoldingDiv2 {
public:
  int howMany(vector <string> paper) {
    set< vector<string> > s;
    queue< vector<string> > q;
    s.insert(paper);
    q.push(paper);
    int c=0;
    while(!q.empty()){
      vector<string> p = q.front();
      for(int i=0; i<p.size(); i++)
	cout << p[i] << endl;
      cout << endl;
      int width = p[0].size()-1;
      int height = p.size()-1;
      for(int i=0; i<width; i++){
	int il = i;
	int ir = i+1;
	bool judge = true;

	while(il >= 0 && ir <= width){
	  for(int j=0; j<=height; j++){
	    if(p[j][il] != p[j][ir]) judge = false;
	    if(!judge) break;
	  }
	  if(!judge) break;
	  il--;
	  ir++;
	}
	if(judge){
	  vector<string> pnew = p;
	  if(i < width - i){
	    for(int j=0; j<p.size(); j++){
	      for(int k=0; k<i+1; k++){
		pnew[j][k] = '2';
	      }
	    }
	  }
	  else{
	    for(int j=0; j<p.size(); j++){
	      for(int k=i+1; k<p[0].size(); k++){
		pnew[j][k] = '2';
	      }
	    }
	  }
	  if(s.count(pnew) == 0){
	    s.insert(pnew);
	    q.push(pnew);
	  }
	}
      }
      for(int i=0; i<height; i++){
	int il = i;
	int ir = i+1;
	bool judge = true;
	while(il >= 0 && ir <= height){
	  for(int j=0; j<=height; j++){
	    if(p[il][j] != p[ir][j]) judge = false;
	    if(!judge) break;
	  }
	  if(!judge) break;
	  il--;
	  ir++;
	}
	if(judge){
	  vector<string> pnew = p;
	  if(i < height - i){
	    for(int j=i+1; j<p.size(); j++){
	      for(int k=0; k<p[0].size(); k++){
		pnew[j][k] = '2';
	      }
	    }
	  }
	  else{
	    for(int j=0; j<i+1; j++){
	      for(int k=0; k<p[0].size(); k++){
		pnew[j][k] = '2';
	      }
	    }
	  }
	  if(s.count(pnew) == 0){
	    s.insert(pnew);
	    q.push(pnew);
	  }
	}
      }
      c++;
      q.pop();
    }

    return c;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"10",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { string Arr0[] = {"1111111",
 "1111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 84; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { string Arr0[] = {"0110",
 "1001",
 "1001",
 "0110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { string Arr0[] = {"0",
 "0",
 "0",
 "1",
 "0",
 "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { string Arr0[] = {"000",
 "010",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
  BoardFoldingDiv2 test;
  int n;
  cin >> n;
  test.run_test(n);
}
// END CUT HERE
