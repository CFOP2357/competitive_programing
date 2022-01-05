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
    cin>>n;
    cin>>s;

    for(int l = 2; l < 10; l++){
        for(int i = l-1; i < n; i++){
            int a_frecuency = 0;
            int b_frecuency = 0;
            int c_frecuency = 0;

            for(int j = 0; j < l; j++)
                if(s[i-j] == 'a')
                    a_frecuency++;

            for(int j = 0; j < l; j++)
                if(s[i-j] == 'b')
                    b_frecuency++;

            for(int j = 0; j < l; j++)
                if(s[i-j] == 'c')
                    c_frecuency++;

            if(a_frecuency > b_frecuency and a_frecuency > c_frecuency){
                cout<<l<<"\n";
                return;
            }
        }
    }

    cout<<"-1\n";

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

