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


ull q, d;
map<ull, ull> minToMod;

void solve(){

    cin>>q>>d;

    minToMod.clear();

    for(int i=0; i<=9; i++){
        ull k = i*10+d;
        if(minToMod[k%d]==0)
            minToMod[k%d]=k;
        minToMod[k%d]=min(minToMod[k%d], k);
    }

    for(int i=0; i<=9; i++){
        ull k = d*10+i;
        if(minToMod[k%d]==0)
            minToMod[k%d]=k;
        minToMod[k%d]=min(minToMod[k%d], k);
    }

    vector<ull> r;
    for(auto k : minToMod)
        r.push_back(k.second);

    for(ull z : r)
        for(ull p : r){
            ull k = z+p;
            if(minToMod[k%d]==0)
                minToMod[k%d]=k;
            minToMod[k%d]=min(minToMod[k%d], k);
        }

    r.clear();
    for(auto k : minToMod)
        r.push_back(k.second);

    for(ull z : r)
        for(ull p : r){
            ull k = z+p;
            if(minToMod[k%d]==0)
                minToMod[k%d]=k;
            minToMod[k%d]=min(minToMod[k%d], k);
        }

    while(q--){
        ull a; cin>>a;
        if(minToMod[a%d]<=a)
            cout<<"YES\n";
        else cout<<"NO\n";
    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

