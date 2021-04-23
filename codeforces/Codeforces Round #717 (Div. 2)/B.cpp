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

typedef int ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

void solve(){
    a.clear(); b.clear();a.push_back(0);
    cin>>n;

    unordered_set<ull> totalXor;

    ull currentXor = 0;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        currentXor ^= z;
        totalXor.insert(currentXor);
    }

    unordered_map<ull, int> xorPosition;
    vector<int> sz(n+1, 0);
    for(int x : totalXor){
        xorPosition.clear(); xorPosition[0]=0;
        sz.assign(n+1, 0); sz[0] = 1;
        ull currentXor = 0;
        for(int i=1; i<=n; i++){
            currentXor ^= a[i];
            ull complement = x^currentXor;
            if(xorPosition.find(complement)!=xorPosition.end())
                if(sz[xorPosition[complement]])
                    sz[i] = max(sz[i], sz[xorPosition[complement]]+1);
            if(sz[i])
                xorPosition[currentXor] = i;
        }
        if(sz.back()>2){
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";
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

