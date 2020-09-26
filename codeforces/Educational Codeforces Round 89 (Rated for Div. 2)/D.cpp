#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
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
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;

        vector<int> d;
        for(int i=2; i*i<=z && z>1; i++){
            if(z%i==0){
                d.push_back(i);
                while(z%i==0)z/=i;
            }
        }
        if(z>1) d.push_back(z);

        int p(0),r(0);

        map<int, int> cong;
        for(int u :

        if(!p || !r){
            a.push_back(-1);
            b.push_back(-1);
        }
        else {
            a.push_back(p);
            b.push_back(r);
        }

    }

    for(int ans : a) cout<<ans<<" ";
    cout<<"\n";

    for(int ans : b) cout<<ans<<" ";
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

