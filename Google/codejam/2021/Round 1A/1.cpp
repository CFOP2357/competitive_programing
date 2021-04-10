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

vector<string> a;
vector<ull> b;
ull n, m;
string s;

ull complete(const string &top, string &down){

    bool e = true;

    for(int i = 0; i<down.size(); i++){
        if(down[i]>top[i]){
                ull ans = top.size()-down.size();
                down += string(ans, '0');
                return ans;
        }

        if(down[i]<top[i])
            e = false;
    }

    int j;
    for(j=top.size()-1; j>=down.size() && top[j]=='9'; j--);

    if(j<down.size())
        e=false;

    ull ans = top.size()-down.size();

    if(!e){
        ans++;
        down += string(ans, '0');
    }
    else {
        down += top.substr(down.size(), j-down.size());
        down += (char)(top[j]+1);
        down += string(top.size()-down.size(), '0');
    }

    //cout<<down<<"\n";
    return ans;

}


void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        string z; cin>>z;
        a.push_back(z);
    }

    ull ans = 0;
    for(int i=1; i<n; i++){
        if(a[i].size()>a[i-1].size() || (a[i].size() == a[i-1].size() && a[i]>a[i-1]))
            continue;

        ans += complete(a[i-1], a[i]);

    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}

/*
1
20
9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9
*/

