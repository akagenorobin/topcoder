#include<cmath>
#include<cstdlib>
#include<cstdio>
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

class BinaryCode {
public:
  int int_st(char s){
    int n;
    stringstream ss;
    ss << s;
    ss >> n;
    return n;
  }

  string st_int(int n){
    string s;
    stringstream ss;
    ss << n;
    return ss.str();
  }

  vector<string> decode(string message) {
    vector<string> res;
    res.resize(2);

    for(int i=0; i<2; i++){
      int q0 = 0;
      int q1 = i;
      int q = i;
      int p;
      string::iterator it = message.begin();

      while(true){
	res[i] += st_int(q);
	p = int_st(*it);

	q = p - q0 - q1;
	q0 = q1;
	q1 = q;

	if(it == message.end()-1){
	  if(q != 0) res[i] = "NONE";
	  break;
	}

	if(q != 1 && q != 0){
	  res[i] = "NONE";
	  break;
	}

	it++;
      }
      cout << endl;
    }

    return res;
  }
};

// BEGIN CUT HERE
int main(){
  BinaryCode test;
  cout << test.decode("11")[0] << endl;
}
// END CUT HERE
