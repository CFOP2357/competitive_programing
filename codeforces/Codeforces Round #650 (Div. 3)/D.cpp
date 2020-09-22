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

vector<ull> b;
ull m;

void solve(){
    b.clear();

    string s; cin>>s;
    cin>>m;
    vector<int> d(300, 0);
    for(int i=0; i<m; i++){
        ull z; cin>>z;
        b.push_back(z);
    }
    for(char c : s) d[c]++;

    string ans(m, ' ');

    int j = 0;
    char p = 'z';

    while(j<m){
        vector<int> nxt;
        for(int i =0; i<m; i++){
            if(!b[i]){
                nxt.push_back(i);
                b[i] = -1;
                j++;
            }
        }

        while(d[p]<nxt.size()) p--;
        for(int k : nxt){
            ans[k] = p;
        }
        d[p]-=nxt.size(); p--;

        for(int i =0; i<m; i++){
            if(b[i] > 0){
                for(int k : nxt){
                    b[i] -= abs(i-k);
                }
            }
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

/*
1
abac
3
2 1 0

1
ecoosdcefr
10
38 13 24 14 11 5 3 24 17 0
*/

