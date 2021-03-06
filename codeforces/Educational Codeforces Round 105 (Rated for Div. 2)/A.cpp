#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>

#include <map>
#include <set>

#include <stack>
#include <queue>

#include <unordered_map>
#include <unordered_set>

#include <time.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define all(a) a.begin(), a.end()

typedef long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

void pre(){

}

void solve(){
    a.clear(); b.clear();
    cin>>s;

    if(s[0] == s.back()){
        cout<<"NO\n";
        return;
    }

    char openBraket = s[0];
    char closeBraket = s.back();

    bool possible = true;
    int balance = 0;
    for(char c : s){

        if(c == closeBraket){
            balance--;
        }
        else {
            balance++;
        }
        if(balance<0)
            possible=false;

    }

    if(!balance && possible){
        cout<<"YES\n";
        return;
    }

    possible = true;
    balance = 0;
    for(char c : s){

        if(c != openBraket){
            balance--;
        }
        else {
            balance++;
        }
        if(balance<0)
            possible=false;

    }

    if(!balance && possible){
        cout<<"YES\n";
        return;
    }

    cout<<"NO\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    pre();

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

