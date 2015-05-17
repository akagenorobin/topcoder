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

class TwoWaysSorting {
public:
  string sortingMethod(vector <string> stringList) {
    bool lex = true;
    for(vector<string>::iterator i=stringList.begin(); i<stringList.end()-1; i++){
      if(*i > *(i+1)){
	//cout << *i << " " << *(i+1) << endl;
	lex = false;
	break;
      }
    }
    bool len = true;
    for(vector<string>::iterator i=stringList.begin(); i<stringList.end()-1; i++){
      if(i->length() > (i+1)->length()){
	//cout << i->length() << " " << (i+1)->length() << endl;
	len = false;
	break;
      }
    }
    if(lex && len) return "both";
    else if(lex) return "lexicographically";
    else if(len) return "lengths";
    else return "none";
  }
};

// BEGIN CUT HERE
int main(){
  //	TwoWaysSorting test;
  //	cout << test.sortingMethod() << endl;
}
// END CUT HERE
