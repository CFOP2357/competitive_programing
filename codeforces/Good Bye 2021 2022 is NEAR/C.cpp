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

vector<double> a;
vector<double> b;
ll n, m;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i = 0; i < n; i++){
        double z; cin>>z;
        a.push_back(z);
    }

    ll ans = (n+1)/2;

    int j = n;
    for(int i = 2; i < n; i++){
        if((a[i] + a[i-2])/2 != a[i-1]){
            j = i;
            break;
        }
    }

    ll ans2 = 0;
    b = a;
    if(j < n){
        b[j-1] = (b[j] + b[j-2])/2;
        ans2++;
    }
    for(int i = j+1; i < n; i++){
        if((b[i] + b[i-2])/2 != b[i-1]){
            b[j] = b[j-1]*2 - b[j-2];
            ans2++;
        }
    }

    ll ans3 = 0;
    b = a;
    for(int i = j; i < n; i++){
        if((b[i] + b[i-2])/2 != b[i-1]){
            b[j] = b[j-1]*2 - b[j-2];
            ans3++;
        }
    }

    ll ans4 = 0;
    b = a;
    if(j < n){
        b[j-2] = b[j-1]*2 - b[j];
        ans4++;
    }
    for(int i = j+1; i < n; i++){
        if((b[i] + b[i-2])/2 != b[i-1]){
            b[j] = b[j-1]*2 - b[j-2];
            ans4++;
        }
    }

    cout<<min({ans, ans2, ans3, ans4})<<"\n";
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

