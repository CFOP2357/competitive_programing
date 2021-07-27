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

vector<vector<int>> r;
ll n, m;

void solve(){
    r.clear();
    cin>>n;
    for(int j=0; j<n; j++){
        r.push_back(vector<int>());
        for(int i=0; i<5; i++){
            ll z; cin>>z;
            r.back().push_back(z);
        }
    }

    int candidate = 0;
    for(int i=1; i<n; i++){
        int score = 0;
        for(int j=0; j<5; j++){
            if(r[i][j]<r[candidate][j])
                score++;
        }
        if(score >= 3)
            candidate = i;
    }

    for(int i=0; i<n; i++){
        if(candidate == i)
            continue;
        int score = 0;
        for(int j=0; j<5; j++){
            if(r[i][j]<r[candidate][j])
                score++;
        }
        if(score >= 3){
            cout<<"-1\n";
            return;
        }
    }

    cout<<candidate+1<<"\n";

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
