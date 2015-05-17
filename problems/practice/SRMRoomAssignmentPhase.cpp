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

class SRMRoomAssignmentPhase {
public:
  int countCompetitors(vector <int> ratings, int K) {
    int ans = 0;
    int n = 1;
    while(ratings.size() > n * K){
      if(ratings[n * K] > ratings[0]) ans++;
      n++;
    }
    return ans;
  }
};

// BEGIN CUT HERE
int main(){
  SRMRoomAssignmentPhase test;
  cout << test.countCompetitors() << endl;
}
// END CUT HERE
