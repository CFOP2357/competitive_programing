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
    ll W, H;
    ll x1, y1, x2, y2;
    ll w, h;

    cin>>W>>H;
    cin>>x1>>y1>>x2>>y2;
    cin>>w>>h;

    ll w1 = x2-x1;
    ll h1 = y2-y1;

    ll ans = LLONG_MAX;
    {
        ll x = x1, y = y1;
        if(x<w and y<h){
            if(h+h1<=H)
                ans = min(ans, h-y);
            if(w+w1<=W)
                ans = min(ans, w-x);
        }
        else ans = 0;
    }
    {
        ll x = x1, y = y2;
        if(x<w and y>(H-h)){
            if(h+h1<=H)
                ans = min(ans, y-(H-h));
            if(w+w1<=W)
                ans = min(ans, w-x);
        }
        else ans = 0;
    }
    {
        ll x = x2, y = y2;
        if(x>(W-w) and y>(H-h)){
            if(h+h1<=H)
                ans = min(ans, y-(H-h));
            if(w+w1<=W)
                ans = min(ans, x-(W-w));
        }
        else ans = 0;
    }
    {
        ll x = x2, y = y1;
        if(x>(W-w) and y<h){
            if(h+h1<=H)
                ans = min(ans, h-y);
            if(w+w1<=W)
                ans = min(ans, x-(W-w));
        }
        else ans = 0;
    }
    if(ans==LLONG_MAX)
        cout<<"-1\n";
    else
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

