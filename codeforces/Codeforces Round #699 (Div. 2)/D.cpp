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

int T, tc;

void solve(){
    tc++;

    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>adj[i][j];
        }
    }

    /*if(T==168 && tc == 75){
        cout<<n<<" "<<m<<"\n";
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout<<adj[i][j];
            }
            cout<<"\n";
        }
        exit(0);
    }
    if(T==168)
        return;*/

    if(m%2){
        cout<<"YES\n";
        for(int i=0; i<=m; i++)
            cout<<(i%2)+1<<" ";
        cout<<"\n";
        return;
    }

    vector<ull> ans;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            if(i==j)
                continue;
            if(adj[i][j]==adj[j][i]){
                ans.push_back(i);
                ans.push_back(j);

                cout<<"YES\n";
                for(int k=0; k<=m; k++)
                    cout<<ans[k%2]<<" ";
                cout<<"\n";

                return;
            }
        }

    for(int i=1; i<=n; i++){
        ans.clear();
        for(int j=1; j<=n; j++){
            if(i==j)
                continue;

            if(ans.size()<2 && (!ans.size() || adj[i][ans.back()]!=adj[i][j]))
                ans.push_back(j);
        }
        ans.push_back(i);

        /*if(i==1){
            cout<<ans.size()<<"#\n";
            for(int k : ans)
                cout<<k<<" ";
            cout<<"\n";
        }*/

        if(ans.size()==3){
            cout<<"YES\n";

            swap(ans[0], ans[2]);
            if((m/2)%2)
                swap(ans[1], ans[0]);

            for(int k = 0; k<=m/2; k++){
                cout<<ans[k%2]<<" ";
            }

            if((m/2)%2)
                swap(ans[1], ans[0]);
            swap(ans[1], ans[2]);
            if(m%4 == 0)
                swap(ans[1], ans[0]);
            for(int k = m/2; k<m; k++){
                cout<<ans[k%2]<<" ";
            }
            cout<<"\n";
            return;
        }
    }

    cout<<"NO\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    T=t;
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


1
5 98
*abba
b*aab
ab*ab
abb*a
baab*
*/
