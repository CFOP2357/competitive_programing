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

#include <assert.h>

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
typedef int64_t ll;
typedef uint64_t ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
#define MOD 1000000007

vector<ll> a;
vector<ll> b;
ll n, m, x;
string s;

void solve(){
    cin>>x;
    cin>>s;

    ll ans = 0;
    ll sum = s.size();
    for(int l = 0; l < x; l++){
        sum = ((sum+MOD) - 1)%MOD;

        if(s.size() < x){
            int n = s.size();
            for(int k = 0; k < s[l] - '0'; k++)
                for(int i = l+1; i < n; i++)
                    s.push_back(s[i]);
            sum = s.size() - l - 1;
        }
        else {
            sum += (s[l]-'0') * (l+1);
            sum %= MOD;
        }
    }

    ans += s.size();
    ans %= MOD;

    cout<<ans<<"\n";
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

