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

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define MAX 200100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
ull x, y, k;

bool posibleFire[MAX];
bool keep[MAX];
ull l[MAX], r[MAX];
ull dp[MAX];

void solve(){
    a.clear(); b.clear();
    cin>>n>>m;
    cin>>x>>k>>y;

    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }
    for(int i=0; i<m; i++){
        int z; cin>>z;
        b.push_back(z);
    }

    int j = m-1;
    int sz = 0;
    for(int i=n-1; i>=0; i--){
        if(j>=0 && a[i]==b[j]){
            keep[i] = true;
            sz = k;
            j--;
        }

        if(sz){
            sz--;
            posibleFire[i] = false;
        } else posibleFire[i] = true;
    }

    stack<int> last;

    l[0] = a[0];
    last.push(0);
    for(int i=1; i<n; i++){
       if(keep[i]){
            l[i] = i;
            while(last.size())last.pop();
       }
       else{
            while(last.size() && a[i]>=a[last.top()]) last.pop();
            if(last.size())l[i] = last.top();
            else l[i] = i;
            last.push(i);
       }
    }

    while(last.size())last.pop();
    r[n-1] = a[n-1];
    last.push(n-1);
    for(int i=n-1; i>=0; i--){
       if(keep[i]){
            r[i] = i;
            while(last.size())last.pop();
       }
       else{
            while(last.size() && a[i]>=a[last.top()]) last.pop();
            if(last.size())r[i] = last.top();
            else r[i] = i;
            last.push(i);
       }
    }

    for(int i = 0; i<n; i++) cout<<a[l[i]]<<" ";
    cout<<"\n";

    if(j>=0){
        cout<<"-1\n";
        return;
    }

    fill(dp, dp+n+1, LLONG_MAX);
    dp[0] = 0;
    for(int i=0; i<n; i++){
        if(keep[i]){
            dp[i+1] = min(dp[i], dp[i+1]);
        }
        else {
            if(i>0 && a[l[i]]>a[i] && dp[l[i]]!=LLONG_MAX)
                dp[i+1] = min(dp[l[i]]+y*(i-l[i]), dp[i+1]);
            if(i<n-1 && a[r[i]]>a[i])
                dp[r[i]+1] = min(dp[i]+y*(r[i]-i), dp[r[i]]+1);
            if(i+k-1<n && posibleFire[i])
                dp[i+k] = min(dp[i+k], dp[i]+x);
        }
    }

    /*for(int i=0; i<=n; i++)
        cout<<dp[i]<<" ";
    cout<<"\n";*/

    if(dp[n] == LLONG_MAX)
        cout<<"-1\n";
    else
        cout<<dp[n]<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}

/*
10 3
5 3 3
1 4 7 9 10 2 3 5 6 8
1 10 8
*/
