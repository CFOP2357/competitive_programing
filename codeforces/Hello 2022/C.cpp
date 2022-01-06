//#include <bits/stdc++.h>
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

#include <assert.h>

//#include <time.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef int64_t ll;
typedef uint64_t ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
#define MOD 1000000007

vector<ll> a;
vector<ll> b;
ll n, m;
string s;

int query(int k){
    cout<<"? "<<k<<endl;

    int ans;
    cin>>ans;
    return ans;
}

void solve(){
    cin>>n;

    vector<int> ans(n+1, 0);
    for(int i = 1; i <= n; i++){
        if(ans[i])
            continue;

        int first_value = query(i);
        int last = first_value;

        do{
            int value = query(i);
            ans[last] = value;

            last = value;
        }while(last != first_value);
    }


    cout<<"! ";
    for(int i = 1; i < n; i++)
        cout<<ans[i]<<" ";
    cout<<ans.back()<<endl;

}


int main(){
    //cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

