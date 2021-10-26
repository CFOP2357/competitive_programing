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
char c;
string s;

void solve(){
    cin>>n>>c;
    cin>>s;

    s = ' ' + s;

    bool all_c = true;
    for(int i = 1; i <= n; i++)
        if(s[i] != c)
            all_c = false;
    if(all_c){
        cout<<"0\n";
        return;
    }

    for(int i = 1; i <= n; i++){
        if(s[i] == c){
            bool is_ans = true;
            for(int j = i; j <= n; j += i)
                if(s[j] != c)
                    is_ans = false;

            if(is_ans){
                cout<<"1\n";
                cout<<i<<"\n";
                return;
            }
        }
    }

    cout<<"2\n";
    cout<<n-1<<" "<<n<<"\n";
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

