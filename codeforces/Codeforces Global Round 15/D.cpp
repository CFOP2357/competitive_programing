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
ll n, m;
unordered_map<int, int> to_complete;

bool f(int i=0, int sum1=0, int sum2=0){
    if(to_complete[sum1+sum2] or to_complete[sum1-sum2] or to_complete[sum2-sum1] or to_complete[sum2] or to_complete[sum1])
        return true;
    if(i>=n)
        return false;
    to_complete[a[i]]--;
    if(f(i+1, sum1+a[i], sum2))
        return true;
    if(f(i+1, sum1, sum2+a[i]))
        return true;
    if(f(i+1, sum1, sum2))
        return true;
    to_complete[a[i]]++;
    return false;
}

void solve(){
    a.clear(); to_complete.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ll z; cin>>z;
        a.push_back(abs(z));
        to_complete[abs(z)]++;
    }
    for(int i=0; i<n; i++){
        if(f()){
            cout<<"YES\n";
            return;
        }
    }

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

