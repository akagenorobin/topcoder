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

class Time {
	public:
	string whatTime(int seconds) {
	  int hours = (int)(seconds / 3600);
	  seconds -= hours * 3600;
	  int minutes = (int)(seconds / 60);
	  seconds -= minutes * 60;
	  stringstream ss;
	  ss << hours << ":" << minutes << ":" << seconds;
	  return ss.str();
	}

};

// BEGIN CUT HERE
int main(){
	Time test;
	cout << test.whatTime(5436) << endl;
}
// END CUT HERE
