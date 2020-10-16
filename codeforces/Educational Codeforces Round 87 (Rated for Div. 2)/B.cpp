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
    string s; cin>>s;

    int one(-1), two(-1), three(-1);
    int ans = INT_MAX;

    for(char c : s){

        switch(c){
            case '1': one = 0; break;
            case '2': two = 0; break;
            case '3': three = 0; break;
        }

        if(one>=0 && two>=0 && three>=0){
            ans = min(ans, one+two+three);
        }

        one += one>=0;
        two += two>=0;
        three += three>=0;

    }


    if(ans == INT_MAX)
        cout<<"0\n";
    else cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

