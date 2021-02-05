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

#define MAX 1010
#define MOD 1000000007


ull n, m;

char adj[MAX][MAX];

void solve(){

    map<pair<ull, char>, ull> toConnect; //{endsOn, edge} = from

    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>adj[i][j];

            if(i!=j)
                toConnect[{j, adj[i][j]}] = i;
        }
    }

    if(m%2){
        cout<<"YES\n";
        for(int i=0; i<=m; i++)
            cout<<(i%2)+1<<" ";
        cout<<"\n";
        return;
    }

    vector<ull> ans(4, 0);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            if(i==j)
                continue;
            if(adj[i][j] == adj[j][i]){
                ans[0] = i;
                ans[1] = j;
                ans[2] = ans[3] = 0;
            }
            if(m%3==0 && toConnect[{i, adj[i][j]}] &&  (!ans[0])){
                ans[0] = i;
                ans[1] = j;
                ans[2] = toConnect[{i, adj[i][j]}];
                ans[3] = 0;
            }
            if(m%4==0 && toConnect[{i, adj[i][j]}] &&  (!ans[0])){
                ans[0] = i;
                ans[1] = j;
                ans[3] = toConnect[{i, adj[i][j]}];
                //1->2 == 2->3

                for(int k = 1; k<=n; k++)
                    if(ans[1]!=k && ans[3]!=k)
                    if(adj[ans[1]][k]==adj[k][ans[3]])
                        ans[2] = k;
            }
        }

    while(ans.back() == 0)
        ans.pop_back();

    if(!ans.size()){
        cout<<"NO\n";
        return;
    }

    if(m%(ans.size()-1)){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";
    for(int i =0; i<=m; i++)
        cout<<ans[i%ans.size()]<<" ";

    cout<<"\n";
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
3 6
*ab
b*b
aa*
*/
