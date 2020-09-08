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

#define MAX 1000100
#define MOD 1000000007

int ans[MAX];
ull n;

void solve(){
    cin>>n;

    if(n==1){
        cout<<"! 1"<<endl;
        return;
    }

    int x, y;
    int last = 1;

    for(int i=2; i<=n; i++){
        cout<<"? "<<last<<" "<<i<<endl;
        cin>>y;
        if(y==-1) return;
        cout<<"? "<<i<<" "<<last<<endl;
        cin>>x;
        if(x==-1) return;

        if(y>x){
            ans[last] = y;
            last = i;
        }
        else {
            ans[i] = x;
        }
    }

    cout<<"! ";
    ans[last] = n;
    for(int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; t=1;
    while(t--){
        solve();
    }
    return 0;
}

