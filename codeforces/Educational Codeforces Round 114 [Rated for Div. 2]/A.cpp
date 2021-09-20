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

int to_print = 0;

void print_brackets(int to_open, int to_close, string &current){
    if(not to_print)
        return;

    if(not to_open and not to_close){
        to_print--;
        cout<<current<<"\n";
        return;
    }

    if(to_open){
        current.push_back('(');
        print_brackets(to_open-1, to_close+1, current);
        current.pop_back();
    }
    if(not to_print)
        return;

    if(to_close){
        current.push_back(')');
        print_brackets(to_open, to_close-1, current);
        current.pop_back();
    }
    if(not to_print)
        return;
}

void solve(){
    a.clear(); b.clear();
    cin>>to_print;
    string current = "";
    print_brackets(to_print, 0, current);
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

