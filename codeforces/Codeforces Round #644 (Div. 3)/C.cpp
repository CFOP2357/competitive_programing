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

    int even = 0, odd = 0;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);

        even += !(z%2);
        odd += z%2;
    }

    sort(all(a));

    int seq = 0;
    for(int i=1; i<n; i++)
        seq += a[i]==a[i-1]+1;

    //cout<<even<<" "<<odd<<"\n";

    if(even%2 == odd%2 && even%2 == 0)
        cout<<"YES\n";
    else if(even%2 == odd%2 && even%2 == 1 && seq)
        cout<<"YES\n";
    else cout<<"NO\n";


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

