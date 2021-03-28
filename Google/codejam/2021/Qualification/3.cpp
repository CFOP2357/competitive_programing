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

#include <time.h>

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

ull n, c;

void solve(){

    cin>>n>>c;

    if(c < n-1){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    vector<int> ans;
    for(int i=1; i<=n; i++)
        ans.push_back(i);
    c-=n-1;

    for(int i=n-2; i>=0 && c; i--){
        int j = min(n-1, i+c);
        c -= j-i;

        reverse(ans.begin()+i, ans.begin()+j+1);
    }

    if(c){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    for(int k : ans)
        cout<<k<<" ";
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}

/*
1
7
1 2 3 5 7 6 4
*/


