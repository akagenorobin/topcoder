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
#include<functional>
using namespace std;

class MixingColors {
public:
  int minColors(vector <int> colors) {
    int n = colors.size();
    // for(int i=0; i<n; i++) cout << colors[i] << " ";
    // cout << endl;
    int ans = 0;
    while(true){
      int c = *max_element(colors.begin(), colors.end());
      if(c==0) break;
      for(int i=0; i<n; i++){
	if((colors[i] ^ c) < colors[i]) colors[i] ^= c;
      }
      // for(int i=0; i<n; i++) cout << colors[i] << " ";
      // cout << endl;
      ans++;
   }

    return ans;
  }
};

// BEGIN CUT HERE
int main(){
  MixingColors test;
  int c[] = {1,8,9};
  vector<int> colors;
  for(int i=0; i<3; i++) colors.push_back(c[i]);
  cout << test.minColors(colors) << endl;
}
// END CUT HERE
