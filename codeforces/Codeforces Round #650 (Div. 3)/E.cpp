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

ull n, k;

int d[300];

void solve(){
    fill(d, d+300, 0);

    cin>>n>>k;
    string s; cin>>s;

    int ans = k>n?1:k;
    for(char c : s)
        d[c]++;


    vector<int> order;
    for(int i = n; i>1; i--){
        order.clear();
        vector<bool> visited(i+5, false);
        //cout<<i<<": \n";
        for(int j = 0; j<i; j++){
            if(!visited[j]){
                int l = j;
                int sz = 0;
                while(!visited[l]){ //cout<<l<<" ";
                    sz++;
                    visited[l] = true;
                    l = (l+k)%i;
                } //cout<<"\n";
                order.push_back(sz);
            }
        }

        sort(all(order), greater<int>());

        priority_queue<int> nxt;
        for(int j='a'; j<='z'; j++) nxt.push(d[j]);

        //if(i==5) cout<<order.size();

        bool ans = true;
        for(int e : order){
            if(nxt.top() < e){
                ans = false;
                break;
            }

            nxt.push( nxt.top() - e); nxt.pop();
        }

        if(ans){
            cout<<i<<"\n";
            return;
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
6 3
abcbac

1
7 1000
abczgyo
*/
