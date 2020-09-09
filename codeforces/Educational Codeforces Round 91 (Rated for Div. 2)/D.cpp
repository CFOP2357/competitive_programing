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

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define MAX 200100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;

ull n, m;
ull x, k, y;

ull destroy(int posible, int notPosible){
    //cout<<posible<<" "<<notPosible<<"\n";
    if(!notPosible && !posible) return 0;

    ull ans = LLONG_MAX;

    for(int i = notPosible?k:0; i<=posible+notPosible; i++){
        if(i%k) continue;
        ull cost = (i/k)*x + (posible+notPosible-i)*y;
        ans = min(cost, ans);
    }

    if(ans == LLONG_MAX)
        return -ans;
    return ans;

}

void solve(){
    a.clear(); b.clear();
    cin>>n>>m;
    cin>>x>>k>>y;

    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }
    for(int i=0; i<m; i++){
        int z; cin>>z;
        b.push_back(z);
    }

    int posible(0), notPosible(0);
    int j = 0;
    ull ans = 0;
    for(int i=0; i<n; i++){

        if(j<m && a[i]==b[j]){
            ans += destroy(posible, notPosible);
            //cout<<ans<<"\n";
            if(ans<0){
                cout<<"-1\n";
                return;
            }

            j++;
            posible=notPosible=0;

        }
        else {
            if(j<m && a[i]<b[j])
                posible++;
            else if(j>0 && a[i]<b[j-1])
                posible++;
            else notPosible++;
        }

    }
    ans += destroy(posible, notPosible);

    if(j<m || ans<0){
        cout<<"-1\n";
        return;
    }

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}

/*
10 3
5 3 3
1 4 7 9 10 2 3 5 6 8
1 10 8

5 2
5 2 3
3 1 4 5 2
3 5

2 1
2 1 1
1 2
1

4 3
5 2 1
1 2 3 4
1 2 3
*/
