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

ull x, y;
string s;

void solve(){

    cin>>x>>y;
    cin>>s;

    vector<vector<ull>> dp(s.size(), vector<ull>(250, INT_MAX));

    if(s[0]=='?')
        dp[0]['J']=dp[0]['C']=0;
    dp[0][s[0]]=0;

    for(int i=0; i<s.size()-1; i++){

        if(s[i+1] == '?'){

            dp[i+1]['J'] = min(dp[i+1]['J'], dp[i]['J']);
            dp[i+1]['J'] = min(dp[i+1]['J'], dp[i]['C']+x);

            dp[i+1]['C'] = min(dp[i+1]['C'], dp[i]['C']);
            dp[i+1]['C'] = min(dp[i+1]['C'], dp[i]['J']+y);

        }
        else if(s[i+1]=='J'){
            dp[i+1]['J'] = min(dp[i+1]['J'], dp[i]['J']);
            dp[i+1]['J'] = min(dp[i+1]['J'], dp[i]['C']+x);
        }
        else{
            dp[i+1]['C'] = min(dp[i+1]['C'], dp[i]['C']);
            dp[i+1]['C'] = min(dp[i+1]['C'], dp[i]['J']+y);
        }

    }

    cout<<min(dp[s.size()-1]['C'], dp[s.size()-1]['J'])<<"\n";

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


