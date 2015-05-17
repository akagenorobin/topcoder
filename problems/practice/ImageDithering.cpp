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

class ImageDithering {
public:
  int count(string dithered, vector <string> screen) {
    int res = 0;
    for(int i=0; i<screen.size(); i++){
      string::iterator it1 = screen[i].begin();
      while(it1 < screen[i].end()){
	string::iterator it2 = dithered.begin();
	while(it2 < dithered.end()){
	  if(*it1 == *it2) res++;
	  it2++;
	}
	it1++;
      }
    }
    return res;
  }
};

// BEGIN CUT HERE
int main(){
  ImageDithering test;
  //cout << test.count() << endl;
}
// END CUT HERE
