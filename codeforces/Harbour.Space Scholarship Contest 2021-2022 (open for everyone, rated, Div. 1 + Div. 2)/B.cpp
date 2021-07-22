//#include <bits/stdc++.h>
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

//#include <time.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
#define MOD 1000000007

vector<ll> a;
vector<ll> b;
ll n, m;
string s;

void solve(){
    string s, t;
    cin>>s;
    cin>>t;
    vector<ll> dp(s.size(), 0);

    for(int i=0; i<s.size(); i++){
        if(t[0]==s[i])
            dp[i] = 1;
    }

    int j = 1;
    bool p = true;
    for(;j<t.size() and p; j++){
        p=false;
        vector<ll> last_dp = dp;
        for(int i=1; i<s.size(); i++){
            if(last_dp[i-1]==j and t[j]==s[i]){
                dp[i] = j+1;
                p=true;
            }
        }
    }



    if(!p){
        j--;
        p=true;
        for(;j<t.size() and p; j++){
            p=false;
            vector<ll> last_dp = dp;
            for(int i=0; i<s.size()-1; i++){
                if(last_dp[i+1]==j and t[j]==s[i]){
                    dp[i] = j+1;
                    p=true;
                }
            }
        }
    }

    if(*max_element(all(dp)) == t.size())
        cout<<"YES\n";
    else
        cout<<"NO\n";
}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
1
abcdef
cdedcb

*/
