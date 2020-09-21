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
    cin>>n;

    string s = "codeforces";
    vector<int> times (s.size(), 1);

    ull sum = 1;
    int p = 2;
    while(sum<n){
        for(int i = 0; i<s.size() && sum < n; i++){
            sum/=times[i];
            sum*=p;
            times[i] = p;
        }
        p++;
    }

    for(int i=0; i<s.size(); i++)
        for(int j=0; j<times[i]; j++)
            cout<<s[i];
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

