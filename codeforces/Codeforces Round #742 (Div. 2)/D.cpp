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


void solve(){
    ll s, n;
    cin>>s>>n;

    priority_queue<ll, vector<ll>, greater<ll>> ans;

    ll p = 1;
    while(s){
        for(int i = 0; i < s%10; i++)
            ans.push(p);

        s /= 10;
        p *= 10;
    }

    ll units = 0;
    while(ans.size() and ans.top() == 1){
        units++;
        ans.pop();
    }

    while(ans.size()+units < n){
        ll x = ans.top();
        ans.pop();

        ll p = pow(10, to_string(x).size() - 1);
        p /= 10;

        if(p == 1){
            units += 10;
        }
        else {
            for(int i = 0; i < 10; i++)
                ans.push(p);
        }
    }

    for(int k = 0; k < units; k++){
        ans.push(1);
    }

    while(ans.size() > n){
        ll x = ans.top();
        ans.pop();

        x += ans.top();
        ans.pop();

        ans.push(x);
    }


    while(ans.size()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<"\n";
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

