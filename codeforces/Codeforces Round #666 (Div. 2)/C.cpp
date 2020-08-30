#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
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

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    a.clear();
    cin>>n;

    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    if(n>1){
        cout<<1<<" "<<n-1<<"\n";
        for(ull i = 0; i<n-1; i++){
            if(a[i]==0){
                cout<<0<<" ";
            }
            else {
                if(a[i]%n == 0){
                    cout<< 0 <<" ";
                }
                else {
                    cout<< (n-1)*(a[i]%n) << " ";
                    a[i] += (n-1)*(a[i]%n);
                }
            }
        }
        cout<<"\n";
    }
    else {
        cout<<1<<" "<<1<<"\n";
        cout<<0<<"\n";
    }
    cout<<n<<" "<<n<<"\n";
    cout<<-(a[n-1]%n);
    a[n-1] -= a[n-1]%n;
    cout<<"\n";

    cout<<1<<" "<<n<<"\n";
    for(ull i = 0; i<n; i++){
        if(a[i]==0){
            cout<<0<<" ";
        }
        else {
            cout<< -(a[i]/n)*n <<" ";
        }
    }
    cout<<"\n";

    /*for(int k : a)
        cout<<k<<" ";*/


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
