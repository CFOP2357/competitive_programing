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

#include <time.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define all(a) a.begin(), a.end()

typedef long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m, l, r;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n>>l>>r;

    unordered_map<int, int> left_stocks, right_stocks;
    for(int i=0; i<l; i++){
        ull z; cin>>z;
        left_stocks[z]++;
    }
    for(int i=0; i<r; i++){
        ull z; cin>>z;
        right_stocks[z]++;
    }

    for(auto [color, frecuency] : left_stocks){
        ull min_frecuency = min(frecuency, right_stocks[color]);
        left_stocks[color] -= min_frecuency;
        right_stocks[color] -= min_frecuency;
        l -= min_frecuency, r -= min_frecuency;
    }

    ull ans = 0;
    if(l>r){
        for(auto &[color, frecuency] : left_stocks){
            while(l>r && frecuency>1){
                ans++;
                frecuency-=2, l-=2;
            }
        }
        for(auto &[color, frecuency] : left_stocks){
            while(l>r && frecuency){
                ans++;
                frecuency--, l--, r++;
            }
        }
    }
    else if(r>l){
        for(auto &[color, frecuency] : right_stocks){
            while(r>l && frecuency>1){
                ans++;
                frecuency-=2, r-=2;
            }
        }
        for(auto &[color, frecuency] : right_stocks){
            while(r>l && frecuency){
                ans++;
                frecuency--, r--, l++;
            }
        }
    }

    ans += l;
    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

