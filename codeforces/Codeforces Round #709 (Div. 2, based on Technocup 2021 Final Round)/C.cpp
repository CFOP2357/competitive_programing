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

typedef long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n>>m;

    vector<vector<ull>> f;
    vector<ull> timesSelected(n+1, 0);
    vector<ull> timesPossible(n+1, 0);
    vector<ull> ans(m, 0);

    for(int i=0; i<m; i++){
        ull k; cin>>k;
        f.push_back(vector<ull>());

        while(k--){
            ull z; cin>>z;
            f.back().push_back(z);
            timesPossible[z]++;
        }
    }


    for(int i=0; i<m; i++)
        for(auto friendd : f[i]){
            if(timesPossible[friendd] <= (m+1)/2)
                ans[i] = friendd;
        }

    for(int i=0; i<m; i++){

        if(f[i].size()==1){
            ans[i] = f[i].back();
        }

    }

    for(int i=0; i<m; i++)
        if(ans[i])
            timesSelected[ans[i]]++;

    for(int i=0; i<m; i++){

        if(!ans[i]){ ///to show

            int toSelect = f[i].back();

            for(auto friendd : f[i]){
                if(timesSelected[friendd]<(m+1)/2)
                    toSelect = friendd;
            }


            for(auto friendd : f[i]){
                if(timesSelected[friendd]<timesSelected[toSelect])
                    toSelect = friendd;
            }

            ans[i] = toSelect;
            timesSelected[ans[i]]++;

        }

    }

    for(ull k : ans)
        if(!k || timesSelected[k]>(m+1)/2){
            cout<<"NO\n";
            return;
        }

    cout<<"YES\n";
    for(ull k : ans)
        cout<<k<<" ";
    cout<<"\n";

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

