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
typedef int ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
#define MOD 1000000007

vector<ll> a;
vector<ll> b;
ll n, m;
string s;
string finish_s;
unordered_map<string, ll> comb;

ll calculate_time(const string &t){
    //cout<<t<<"$\n";
    if(comb[t])
        return comb[t];
    if(t == finish_s)
        return 0;

    ll k = 0;
    for(auto c : t)
        if(c == 'A')
            k++;

    string next_t = t;
    if(next_t[k-1] == 'A')
        next_t[k-1] = 'S';
    else
        next_t[k-1]  = 'A';

    comb[t] = calculate_time(next_t) + 1;
    //cout<<t<<" "<<comb[t]<<"\n";

    return comb[t];
}

void search_time(int i=0){
    if(i>=s.size()){
        //cout<<s<<"\n";
        comb[s] = calculate_time(s);
        //cout<<comb["A"]<<"//\n";
        return;
    }

    s[i] = 'A';
    search_time(i+1);
    s[i] = 'S';
    search_time(i+1);
}

void solve(){
    a.clear(); b.clear();
    comb.clear();
    //cin>>n;
    s.assign(n, 'S');
    finish_s = s;

    search_time();

   // cout<<comb["A"]<<"(\n";

    ll ans1 = comb.size();
    ll ans2 = 0;
    for(auto &[s, k] : comb){
        ans2 += k;
     //   cout<<s<<" "<<k<<"%\n";
    }

    cout<<ans2<<"\n";
    ll G = __gcd(ans1, ans2);
    ans1 /= G;
    ans2 /= G;

    cout<<ans2<<"/"<<ans1<<"\n";
}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1;
    while(t--){
        for(int i=1; i<=20; i++){
            n = i;
            solve();
        }
    }

    return 0;
}

