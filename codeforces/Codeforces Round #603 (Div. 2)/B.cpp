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

vector<string> a;
vector<ll> b;
ll n, m;
string s;

void solve(){
    a.clear(); b.clear();
    map<string, int> selected;
    cin>>n;
    for(int i = 0; i < n; i++){
        string z; cin>>z;
        a.push_back(z);

        selected[z]++;
    }

    ll ans = 0;
    for(auto &[pin, frecuency] : selected)
        ans += frecuency - 1;

    cout<<ans<<"\n";
    for(auto pin : a){
        if(selected[pin] == 1)
            cout<<pin<<"\n";
        else{
            selected[pin]--;

            bool solved = false;
            for(int d = 0; d <= 3 and not solved; d++){
                for(char c = '0'; c <= '9' and not solved; c++){
                    string new_pin = pin;
                    new_pin[d] = c;

                    if(selected[new_pin] == 0){
                        solved = true;
                        pin = new_pin;
                    }
                }
            }

            selected[pin]++;
            cout<<pin<<"\n";
        }
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

