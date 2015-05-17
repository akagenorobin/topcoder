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

#define MAX_V 50

class PowerOutage {
public:
  vector< vector< pair<int, int> > > connect;

  int estimateTimeOut(vector <int> fromJunction, vector <int> toJunction, vector <int> ductLength) {
    connect.resize(MAX_V);
    for(int i=0; i<fromJunction.size(); i++){
      connect[fromJunction[i]].push_back(make_pair(toJunction[i], ductLength[i]));
    }
    //for(int i=0; i<6; i++)
    //cout << i << " " << nodecost(i) << endl;
    return dfs(0);
  }

  int nodecost(int i){
    int c = 0;
    for(vector< pair<int,int> >::iterator it = connect[i].begin(); it != connect[i].end(); it++){
      c += it->second + nodecost(it->first);
    }
    return c;
  }

  int dfs(int i){
    int min = 10000000;
    for(vector< pair<int,int> >::iterator it = connect[i].begin(); it != connect[i].end(); it++){
      int c = 0;
      c += it->second + dfs(it->first);
      for(vector< pair<int,int> >::iterator jt = connect[i].begin(); jt != connect[i].end(); jt++){
	if(it != jt) c += 2*jt->second + 2*nodecost(jt->first);
      }
      //if(i == 0) cout << it->first << " " << c << endl;
      min = min < c ? min : c;
    }
    if(min == 10000000) min = 0;
    //cout << i << " " << min << endl;
    return min;
  }

};

// BEGIN CUT HERE
int main(){
  PowerOutage test;
  int fromJunction[] = {0,0,0,1,4};
  int toJunction[] = {1,3,4,2,5};
  int ductLength[] = {10,10,100,10,5};
  vector<int> f,t,d;

  for(int i=0; i<5; i++){
    f.push_back(fromJunction[i]);
    t.push_back(toJunction[i]);
    d.push_back(ductLength[i]);
  }
  cout << test.estimateTimeOut(f, t, d) << endl;
}
// END CUT HERE
