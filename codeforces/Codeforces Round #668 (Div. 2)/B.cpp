#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

map<int, ull, greater<int>> a; // position, ai
map<int, ull, greater<int>> b;
//b -> negative, a -> positive
ull n;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        if(z>0)
            b[i]=z;
        if(z<0)
            a[i]=z;
    }

    ull ans = 0;

    //b<a increment a
    for(auto p : a){
        ull t = p.second;
        while(t){
            auto k = b.upper_bound((int)p.first);
            ull d;
            if(k != b.end()){
                d = min(k->second, -t);

            }
            else {
                k = b.begin();
                d = min(k->second, -t);
                ans += d;
                //cout<<"$";
            }
            //cout<<t<<" "<<k->second<<" "<<d<<"\n";
            t += d;
            k->second -= d;
            //cout<<t<<" "<<k->second<<" "<<d<<"#\n";
            if(!k->second)
                b.erase(k);

        }
    }

    cout<<ans<<"\n";
}

/*
1
4
-3 5 -3 1

7
4
-3 5 -3 1
2
1 -1
4
-3 2 -3 4
4
-1 1 1 -1
7
-5 7 -6 -4 17 -13 4
6
-1000000000 -1000000000 -1000000000 1000000000 1000000000 1000000000
1
0
*/


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

