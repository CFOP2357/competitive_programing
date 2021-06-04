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

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

void solve(){
    cin>>s;
    n = s.size();
    s = '#' + s;

    vector<int> dp0(n+1, 0);
    vector<int> dp1(n+1, 0);

    ull ans = 0;
    for(int i=1; i<=n; i++){
        int p = s[i]-'0';
        if(i%2){ //invert
            p = !p;
        }

        if(s[i]=='?'){
            dp0[i] = dp0[i-1]+1;
            dp1[i] = dp1[i-1]+1;
        }
        else {
            if(p)
                dp1[i] = dp1[i-1]+1;
            else
                dp0[i] = dp0[i-1]+1;
        }

        ans += max(dp0[i], dp1[i]);
    }

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

