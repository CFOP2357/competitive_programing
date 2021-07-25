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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
#define MOD 1000000007

vector<vector<int>> r;
vector<pii> sum; //sum, id
vector<vector<pii>>R;
ll n, m;

void solve(){
    r.clear(); sum.clear();
    cin>>n;
    sum.assign(n, {0, 0});
    R.assign(5, vector<pii>());
    for(int j=0; j<n; j++){
        r.push_back(vector<int>());
        sum[j].second = j;
        for(int i=0; i<5; i++){
            ll z; cin>>z;
            r.back().push_back(z);
            R[i].push_back({z, j});
        }
    }

    for(int k=0; k<5; k++){
        sort(all(R[k]));
        for(int i=0; i<n; i++)
            sum[R[k][i].second].first += i;
    }
    sort(all(sum));

    vector<bool> selected(n, false);
    int i = sum[0].second;
    while(!selected[i]){
            selected[i] = true;
            bool is_ans = true;
            for(auto [ss, j] : sum){
                int h = 0;
                for(int k=0; k<5; k++)
                    if(r[i][k]<=r[j][k])
                        h++;
                if(h<3){
                    is_ans = false;
                    i = j;
                    break;
                }
            }
            if(is_ans){
                cout<<i+1<<"\n";
                return;
            }
        //}
    }

    cout<<"-1\n";

}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
