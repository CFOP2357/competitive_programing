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
    a.clear(); b.clear();
    cin>>n;
    cin>>s;

    for(int i = 1; i < n; i++)
        if(s[i] == '?'){
            if(s[i-1] == 'R')
                s[i] = 'B';
            else if(s[i-1] == 'B')
                s[i] = 'R';
        }

    for(int i = n-1; i >= 0; i--)
        if(s[i] == '?'){
            if(s[i+1] == 'R')
                s[i] = 'B';
            else if(s[i+1] == 'B')
                s[i] = 'R';
        }

    for(int i=0; i<n; i++)
        if(s[i] == '?'){
            if(i%2)
                s[i] = 'R';
            else
                s[i] = 'B';
        }

    cout<<s<<"\n";

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

