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

ll n, k;
string s;

void solve(){
    vector<pii> chords;
    cin>>n>>k;

    int ab = 2*n;
    vector<bool> selected(2*n+1, false);
    for(int i=0; i<k; i++){
        int x, y; cin>>x>>y;
        x--; y--;
        if(y<x)
            swap(x, y);
        chords.push_back({x, y});
        selected[x] = selected[y] = true;
        ab -= 2;
    }

    for(int x=0; x<2*n; x++){
        if(selected[x])
            continue;
        int y;
        for(int p = 0, j = x; p<ab/2; j = (j+1)%(2*n)){
            if(!selected[j]){
                p++;
                y = j;
            }
        }
        selected[x] = selected[y] = true;
        chords.push_back({min(x, y), max(x, y)});
        ab -= 2;
    }

    ll ans = 0;
    for(auto chord : chords){
        for(auto chord2 : chords){
            if(chord == chord2)
                continue;
            if(((chord.first < chord2.second and chord2.second < chord.second) and !(chord.first < chord2.first and chord2.first < chord.second))
               or ((chord2.first < chord.second and chord.second < chord2.second) and !(chord2.first < chord.first and chord.first < chord2.second)))
               ans++;
        }
    }

    cout<<ans/2<<"\n";

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

