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

deque<ull> a;
vector<ull> b;
ull n;

void solve(){

    a.clear();

    cin>>n;
    string s; cin>>s;

    a.push_back(1);
    for(int i=1; i<n; i++){
        if(s[i]==s[i-1])
            a.back()++;
        else
            a.push_back(1);
    }

    int j = 0;

    int ans = 0;
    for(int i = 0; i<a.size(); i++){
        ans++;
        j = max(j, i);
        while(j<a.size() && a[j]==1)j++;

        //cout<<j<<" "<<i<<" "<<ans<<"\n";

        if(j<a.size())
            a[j]--;
        else
            i++;

    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

