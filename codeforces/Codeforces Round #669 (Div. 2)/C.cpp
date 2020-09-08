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
    int actual;
    cout<<"? 1 2"<<endl;
    cin>>x;
    cout<<"? 2 1"<<endl;
    cin>>y;

    if(x>y){
        ans[1] = x;
        actual = 0;
    }
    else{
        ans[2] = y;
        x = y;
        actual = 1;
    }

    for(int i=3; i<=n; i++){
        cout<<"? "<<actual<<" "<<i<<endl;
        cin>>y;
        if(y<x){
            cout<<"? "<<i<<" "<<actual<<endl;
            cin>>ans[i];
        }
        else {

        }
    }

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

