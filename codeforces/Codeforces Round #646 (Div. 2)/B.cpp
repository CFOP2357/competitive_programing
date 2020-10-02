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
ull n;

void solve(){
    a.clear();
    string s; cin>>s;

    int n = s.size();

    vector<int> one, zero;

    for(int i=0; i<s.size(); i++){
        a.push_back(s[i]-'0');
        one.push_back(a[i]);
        zero.push_back(!a[i]);
        //cout<<a[i]<<"$\n";
    }

    for(int i=1; i<n; i++)
        one[i] += one[i-1], zero[i] += zero[i-1];

    int ans = n;

    for(int i=0; i<n; i++){

        int d = one[n-1]-one[i];
        d += zero[i];
        ans = min(ans, d);

        d = zero[n-1]-zero[i];
        d += one[i];
        ans = min(ans, d);

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

