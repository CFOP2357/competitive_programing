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

ull p, q;

void solve(){
    cin>>p>>q;

    vector<ull> fact;

    ull Q = q;
    for(int i=2; i*i<=Q && i<=q; i++){
        while(q%i==0){
            q/=i;
            fact.push_back(i);
        }
    }
    if(q>1){
        fact.push_back(q);
    }
    sort(all(fact));

    ull x = p;

    if(x%Q==0){
        x = 1;
        int i = 0, j = 1;
        int t = 1;
        ull act = fact[0];
        while(i<fact.size()){
            if(j==fact.size() || fact[i]!=fact[j]){
                if(t>1)
                    act/=fact[i];
                else act = 1;
                ull ans = p;
                while(ans%fact[i]==0)
                    ans/=fact[i];
                x = max(x, ans * act);
                i=j;
                j++;
                t = 1;
                if(i<fact.size())
                    act = fact[i];
            }
            else {
                t++;
                j++;
                act*=fact[i];
            }
        }

    }

    cout<<x<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);



    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

