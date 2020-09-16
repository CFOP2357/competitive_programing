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

#define MAX 500
#define MOD 1000000007

ull n, k;
int C[MAX];
int R[MAX];

void solve(){
    cin>>n>>k;
    if(k%n)
        cout<<"2\n";
    else cout<<"0\n";

    int sz = n - k/n; //cout<<k%n<<"\n";
    fill(C, C+MAX, sz);
    fill(R, R+MAX, sz);
    if(k%n){
        for(int i=0; i<k%n; i++){
            //cout<<i<<" ";
            C[i]--;
            R[i]--;
        }
    }


    for(int i=0; i<n; i++){
        cout<<R[i]<<"\n";
        for(int j=0; j<n; j++){
            if(C[j] && R[i]){
                C[j]--;
                R[i]--;
                cout<<0;
            }
            else cout<<1;
        }
        cout<<"\n";
    }


}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

