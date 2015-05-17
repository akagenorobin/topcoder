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

class Swimmers {
	public:
	vector <int> getSwimTimes(vector <int> distances, vector <int> speeds, int current) {
	  vector<int> time;
	  time.resize(distances.size());
	  for(int i=0; i<distances.size(); i++){
	    if(distances[i] == 0){
	      time[i] = 0;
	      continue;
	    }
 	    else if(speeds[i] <= current){
	      time[i] = -1;
	      continue;
	    }
 	    else{
 	      time[i] = 0;
 	      time[i] += (int)((double)distances[i] / (speeds[i] + current) + (double)distances[i] / (speeds[i] - current));
 	    }
 	  }
 	  return time;
 	}
};

// BEGIN CUT HERE
 int main(){
 	Swimmers test;
	// cout << test.getSwimTimes() << endl;
}
// END CUT HERE
