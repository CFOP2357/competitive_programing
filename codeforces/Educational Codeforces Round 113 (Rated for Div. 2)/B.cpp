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
    vector<vector<char>> grid(n, vector<char>(n, '='));
    cin>>s;
    for(int i = 0; i < n; i++){
        grid[i][i] = 'X';

        if(s[i] == '2')
            a.push_back(i);
    }

    if(0 < a.size() and a.size() <= 2){
        cout<<"NO\n";
        return;
    }

    for(int j = 1; j < a.size(); j++){
        grid[a[j]][a[j-1]] = '+';
        grid[a[j-1]][a[j]] = '-';
    }

    if(a.size()){
        grid[a[0]][a.back()] = '+';
        grid[a.back()][a[0]] = '-';
    }

    cout<<"YES\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }

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

