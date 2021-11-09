
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
string ans = "Z";

ll t = 0;

unordered_map<ll, unordered_map<ll, bool>> selected;
bool finded = false;

void find_ans(ll current, ll b){
    if(current == n){
        reverse(all(s));
        ans = min(ans, s);
        reverse(all(s));

        finded = true;
        return;
    }

    if(selected[current][b]){
        return;
    }
    selected[current][b] = true;

    /*reverse(all(s));
    ANS[{current, b}] = s;
    reverse(all(s));*/


    if(current > n)
        return;

    if(s.back() == 'B'){
        s.push_back('A');
        find_ans(current+b, current);
        s.pop_back();
    }
    else {
        if(n%current == 0){
            s.push_back('B');
            find_ans(current, current);
            s.pop_back();
        }

        s.push_back('A');
        find_ans(current+b, current);
        s.pop_back();
    }
}

void solve(){
    cin>>n;

    ans = "IMPOSSIBLE";

    selected.clear();
    finded = false;
    s = "B";
    find_ans(1, 1);

    cout<<ans<<"\n";
}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

//1000000000000000
//1000000000000
