#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<sstream>
#include<vector>
#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

class InterestingNumber {
	public:
	string isInteresting(string x) {
	  bool judge = true;
	  int x_int;
	  stringstream ss;
	  ss << x;
	  ss >> x_int;

	  vector<int> xv;
	  int i = 0;
	  while(int(x_int/pow(10,i)) != 0){
	    xv.push_back(int(x_int/pow(10,i)) - int(x_int/pow(10,i+1))*10);
	    //cout << xv[i] << endl;
	    i++;
	  }

	  for(int i=0; i<10; i++){
	    int n=0;
	    for(int j=0; j<xv.size(); j++){
	      if(xv[j] == i) n++;
	    }
	    //cout << i << " " << n << endl;
	    if(n != 0 && n != 2){
	      judge = false;
	      break;
	    }
	  }

	  if(judge){
	    for(int i=0; i<xv.size(); i++){
	      if(xv[i] == 10) continue;
	      int s = xv[i];
	      xv[i] = 10;
	      if(i+s+1 < xv.size() && xv[i+s+1] == s){
		xv[i+s+1] = 10;
	      }
	      else{
		judge = false;
		break;
	      }
	    }
	  }

	  return judge ? "Interesting" : "Not interesting";
	}

};
/*
// BEGIN CUT HERE
int main(){
	InterestingNumber test;
	cout << test.isInteresting("2002") << endl;
	cout << test.isInteresting("1001") << endl;
	cout << test.isInteresting("41312432") << endl;
	cout << test.isInteresting("611") << endl;
	cout << test.isInteresting("64200246") << endl;
	cout << test.isInteresting("63143164") << endl;
}
// END CUT HERE
*/
