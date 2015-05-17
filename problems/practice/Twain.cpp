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

class Twain {
public:
  string origin;
  void replace(string &phrase, string from, string to){
    string::size_type pos = 0;
    while(pos = phrase.find(from, pos), pos != string::npos) {
      phrase.replace(pos, from.length(), to);
      pos += to.length();
    }
  }
  
  string getNewSpelling(int year, string phrase) {
    origin = phrase;
    if(phrase != ""){
      if(year >= 1){
	string::iterator it = phrase.begin();
	while(it < phrase.end()){
	  if((it == phrase.begin() || *(it-1) == ' ') && *it == 'x'){
	    it = phrase.erase(it);
	    it = phrase.insert(it, 'z');
	  }
	  it++;
	}
	replace(phrase, "x", "ks");
      }
      if(year >= 2) replace(phrase, "y", "i");
      if(year >= 3){
	string::iterator it = phrase.begin();
	while(it < phrase.end()-1){
	  if(*it == 'c' && (*(it+1) == 'i' || *(it+1) == 'e')){
	    it = phrase.erase(it);
	    it = phrase.insert(it, 's');
	  }
	  it++;
	}
      }
      if(year >= 4){
	string::iterator it = phrase.begin();
	while(it != phrase.end()-1){
	  if(*it == 'c' && *(it+1) == 'k'){
	    it = phrase.erase(it);
	    // cout << *it << endl;
	  }
	  else it++;
	}
      }
      if(year >= 5){
	string::iterator it = phrase.begin();
	while(it < phrase.end()-2){
	  if((it == phrase.begin() || *(it-1) == ' ') && *it == 's' && *(it+1) == 'c' && *(it+2) == 'h'){
	    it++;
	    it = phrase.erase(it);
	    it = phrase.erase(it);
	    it = phrase.insert(it,'k');
	  }
	  it++;
	}
	it = phrase.begin();
	while(it < phrase.end()-2){
	  if(*it == 'c' && *(it+1) == 'h' && *(it+2) == 'r'){
	    it = phrase.erase(it);
	    it = phrase.erase(it);
	    it = phrase.insert(it,'k');
	  }
	  it++;
	}
	it = phrase.begin();
	while(it < phrase.end()-1){
	  if(*it == 'c' && *(it+1) != 'h'){
	    it = phrase.erase(it);
	    it = phrase.insert(it,'k');
	  }
	  it++;
	}
      }
      if(year >= 6){
	string::iterator it = phrase.begin();
	while(it < phrase.end()-2){
	  if((it == phrase.begin() || *(it-1) == ' ') && *it == 'k' && *(it+1) == 'n'){
	    it = phrase.erase(it);
	  }
	  it++;
	}
      }
      if(year >= 7){
	string::iterator it = phrase.begin();
	while(it < phrase.end()-1){
	  if(*it != 'a' && *it != 'i' && *it != 'u' && *it != 'e' && *it != 'o' && *it == *(it+1)){
	    it = phrase.erase(it);
	  }
	  else it++;
	}
      }
    }
    return phrase;
  }
};

// BEGIN CUT HERE
int main(){
	 Twain test;
	 cout << test.getNewSpelling(7, "sch kn x xschrx cknnchc cyck xxceci") << " <= " << test.origin << endl;
}
// END CUT HERE
