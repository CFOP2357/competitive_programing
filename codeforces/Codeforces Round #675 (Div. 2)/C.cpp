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

#define MAX 100100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

ull dp[MAX];
ull p[MAX];

void solve(){
    string s; cin>>s;

    dp[0] = s[0]-'0';
    p[0] = 1; p[1] = 2;
    for(int i=1; i<s.size(); i++){

        //p[i] = p[i-1];
        p[i+1] = p[i]*2;
        p[i] %= MOD;

        dp[i] = dp[i-1] + (dp[i-1]*10)%MOD + ((s[i]-'0')*p[i])%MOD;
        dp[i] %= MOD;

        //p[i] += p[i];
        p[i] %= MOD;

        cout<<dp[i]<<"\n";


    }

    ull total = 0;
    for(int i=0; i<s.size(); i++){
        total *= 10;
        total += s[i]-'0';
        total %= MOD;
    }

    ull ans = dp[s.size()-1] + MOD;
    ans -= total;
    ans %= MOD;
    //cout<<total<<"\n";

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

