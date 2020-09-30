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
vector<ull> c;
ull n;

void solve(){
    a.clear(); b.clear(); c.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        b.push_back(z);
    }
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        c.push_back(z);
    }

    cout<<a[0]<<" ";
    int last = a[0];
    for(int i=1; i<n-1; i++){
        if(a[i]==last){
            cout<<b[i]<<" ";
            last = b[i];
        }
        else{
            cout<<a[i]<<" ";
            last = a[i];
        }
    }
    if(a[n-1]!=last && a[n-1]!=a[0])
        cout<<a[n-1];
    else if(b[n-1]!=last && b[n-1]!=a[0])
        cout<<b[n-1];
    else cout<<c[n-1];
    cout<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

