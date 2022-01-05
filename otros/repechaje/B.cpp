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
    a.clear(); b.clear();
    cin>>s;

    vector<int> ans;
    vector<int> pot{1<<1, 1<<3, 1<<2, 1<<3, 1<<2, 1<<3};
    vector<int> mod{60, 60, 24};

    int i = 0;
    for(int k = 0; k < 6; k++){
        int d = 0;
        for(int p = pot[k]; p > 0; p /= 2){
            if(s[i+1] == '*'){
                d += p;
                i += 3;
            }
            else {
                i += 2;
            }
        }
        ans.push_back(d);
    }

    m = 0;
    for(int i = 5; i > 1; i--){
        ans[i-1] += ans[i]/10;
        ans[i] %= 10;
    }

    reverse(all(ans));
    vector<int> ans2{0, 0, 0};

    int m = 0;
    for(int i = 0; i < 6; i += 2){
        ans2.push_back(ans[i] + m);
        ans2.back() += ans[i+1]*10;

        m = ans2.back()/mod[i/2];
        ans2.back() %= mod[i/2];
    }
    reverse(all(ans2));

    for(int i = 0; i < 6; i += 2){
        ans[i] = ans2[i/2] / 10;
        ans[i+1] = ans2[i/2] % 10;
    }

    cout<<ans[0]<<ans[1]<<":"<<ans[2]<<ans[3]<<":"<<ans[4]<<ans[5]<<"\n";

}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1; cin>>t;
    int T = 1;
    while(t--){
        cout<<"Case "<<T<<": ";
        solve();
        T++;
    }

    return 0;
}

/*
1
(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)
*/
