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
typedef int ll;
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
    a.clear(); b.clear();
    cin>>n>>m;

    vector<ll> dp(n+1, 0);
    vector<ll> acum_(n+1, 0);
    dp[n] = 1;

    ll ans = 0;
    ll acum = 0;
    ll last = n;
    for(ll x = n; x >= 1; x--){
        acum += acum_[x];
        acum %= m;

        dp[x] += acum;
        dp[x] %= m;

        dp[x] += acum[2*x];

        ll i = 2;
        while(i<=x){
            ll value = x/i;
            /*if(n/i == last){
                ans += last-1;
                break;
            }*/
            dp[value] += dp[x];
            dp[value] %= m;

            if(x/i != x/(i+1)){
                i++;
                ans++;
            }
            else {
                ll j = x/(value) + 1;

                dp[value] += (j-i-1)*dp[x];
                dp[value] %= m;

                //if(x==n)
                    //cout<<value<<" "<<i<<" "<<j<<"\n";

                i = j;
            }

        }

        acum += dp[x];
        acum %= m;
    }

    cout<<dp[1]<<"\n";

}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

/*
4000000 998244353
*/
