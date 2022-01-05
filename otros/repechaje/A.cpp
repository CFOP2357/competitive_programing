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
ll n, m;
string s;

void solve(){
    getline(cin, s);
    //cout<<s<<"\n";

    for(auto &c : s){
        if(c == '0')
            c = 'O';
        else if(c == '1')
            c = 'I';
        else if(c == '2')
            c = 'Z';
        else if(c == '3')
            c = 'E';
        else if(c == '4')
            c = 'A';
        else if(c == '5')
            c = 'S';
        else if(c == '6')
            c = 'G';
        else if(c == '7')
            c = 'T';
        else if(c == '8')
            c = 'B';
        else if(c == '9')
            c = 'P';
    }

    cout<<s<<"\n";
}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1; cin>>t; getline(cin, s);
    while(t--){
        solve();
    }

    return 0;
}

