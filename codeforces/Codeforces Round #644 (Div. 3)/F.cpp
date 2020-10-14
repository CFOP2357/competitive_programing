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

ull n, m;
vector<string> s;

bool compare(string ans){
    for(string s : ::s){
        int d = 0;
        for(int i = 0; i<m; i++)
            d += s[i]!=ans[i];
        if(d>1)
            return false;
    }
    return true;
}

void solve(){
    s.clear();
    cin>>n>>m;

    string ans = "-1";
    for(int i=0; i<n; i++){
        string z; cin>>z;
        s.push_back(z);
    }

    for(int j = 0; j <n; j++){
        string actual = "";
        if(compare(s[j]))
            ans = s[j];

        for(int i=0; i<m; i++){
            for(string s : ::s){
                if(compare(actual + s.substr(i)))
                    ans = actual + s.substr(i);
            }
            actual.push_back(s[j][i]);
        }
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

