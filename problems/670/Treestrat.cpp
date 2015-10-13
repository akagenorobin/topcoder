#include<cmath>
#include<cstdlib>
#include<sstream>
#include<string>
#include<vector>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<algorithm>
using namespace std;

class Treestrat{
public:
    int n;
    vector< vector<int> > connect;
    set<int> neib(set<int> s){
        set<int> snew;
        for(set<int>::iterator it = s.begin(); it != s.end(); it++){
            int p = *it;
            snew.insert(p);
            for(int j=0; j<connect[p].size(); j++){
                snew.insert(connect[p][j]);
            }
        }
        /*
        for(set<int>::iterator it = snew.begin(); it != snew.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
        */
        return snew;
    }

    int count(vector< set<int> > va, set<int> sb){
        int count = 0;
        bool gameover = false;
        while(true){
            count++;
            sb = neib(sb);
            for(int i=0; i<va.size(); i++){
                va[i] = neib(va[i]);
                for(set<int>::iterator it = va[i].begin(); it != va[i].end();){
                    if(sb.find(*it) != sb.end()){
                        va[i].erase(it++);
                    }
                    else it++;
                }
                if(va[i].empty()){
                    gameover = true;
                    break;
                }
            }
            if(gameover) break;
        }
        return count;
    }

    int roundcnt(vector <int> tree, vector <int> A, vector <int> B){
        n = tree.size()+1;
        connect.resize(n);
        for(int i=0; i<n-1; i++){
            connect[i+1].push_back(tree[i]);
            connect[tree[i]].push_back(i+1);
        }
        vector< set<int> > va;
        va.resize(A.size());
        for(int i=0; i<A.size(); i++) va[i].insert(A[i]);
        set<int> sb(B.begin(), B.end());
        return count(va, sb);
    }


    // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0,3,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(3, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,3,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(4, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0,0,0,3,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(5, Arg3, roundcnt(Arg0, Arg1, Arg2)); }

    // END CUT HERE

};

// BEGIN CUT HERE
int main(){
    Treestrat test;
    int n;
    cout << "test number: ";
    cin >> n;
    test.run_test(n);
}
// END CUT HERE
