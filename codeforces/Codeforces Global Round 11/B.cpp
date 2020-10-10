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

vector<ull> a;
vector<ull> b;
ull n, k;

void solve(){
    a.clear(); b.clear();
    cin>>n>>k;
    string s; cin>>s;

    ull first=0, last=0;
    deque<ull> amount; amount.push_back(0);

    for(char c : s){

        if(c == 'W' && amount.back())
            amount.push_back(0);
        if(c == 'L')
            amount.back()++;

    }

    if(amount.size() == 1 && s[0]=='L' && s[s.size()-1]=='L'){
        if(k)
            cout<<k*2-1<<"\n";
        else cout<<0<<"\n";
        return;
    }

    if(s[0]=='L'){
        first = amount[0];
        amount.pop_front();
    }

    if(s[s.size()-1]=='L'){
        last = amount.back();
        amount.pop_back();
    }

    sort(all(amount));

    while(amount.size() && amount[0]==0)
        amount.pop_front();

    ull ans = 0;

    for(int i=0; i<n; i++){
        if(s[i]=='W'){
            ans++;
            if(i>0 && s[i-1]=='W')
                ans++;
        }
    }

    for(int e : amount){
        if(k>=e){
            ans += e*2 + 1;
            k -= e;
        }
        else if(k){
            ans += k*2;
            k = 0;
        }
    }

    if(k && first){
        ans += min(first, k)*2;
        k -= min(first, k);
    }

    if(k && last){
        ans += min(last, k)*2;
        k -= min(last, k);
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

