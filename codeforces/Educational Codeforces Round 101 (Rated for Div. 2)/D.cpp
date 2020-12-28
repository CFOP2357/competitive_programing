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

vector<ull> a;
vector<ull> b;
ull n;



void solve(){
    cin>>n;

    vector<int> selected(n+1, false);

    ull p = 10;
    ull d = n;

    while(d>2){

        //cout<<d<<" "<<d/p<<"\n";

        p = sqrt(d);
        selected[d] = max(d/p, (ull)2);
        if(d>2)
            d = selected[d];
        else d = 1;

    }
    vector<pii> ans;
    for(int i = 3; i<n; i++)
        if(!selected[d]){
            ans.push_back({i, n});
        }

    d = n;
    while(d>2){
        p = max(selected[d], 2);
        ull k = d;
        while(k>1){
            if(k%p) k+=p;
            k /= p;
            ans.push_back({d, p});
        }
        d = selected[d];
    }


    cout<<ans.size()<<"\n";
    /*for(auto a : ans)
        cout<<a.first<<" "<<a.second<<"\n";*/

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
1
200000
*/

