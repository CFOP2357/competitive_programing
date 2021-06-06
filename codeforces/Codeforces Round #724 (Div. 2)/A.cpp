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
    cin>>n;
    set<ull> ans;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        ans.insert(z);
    }

    for(int i=1; i<n; i++)
        for(int j=i-1; j>=0; j--){
            ull u = a[i], v=a[j];
            while(ans.size()<=300 and ans.find(abs(u-v)) == ans.end()){
                ans.insert(abs(u-v));
                n++;
                a.push_back(abs(u-v));
                u = abs(u-v);
                swap(u, v);
            }
        }

    if(ans.size()>300)
        cout<<"NO\n";
    else{
        cout<<"YES\n";
        cout<<ans.size()<<"\n";
        for(auto k : ans)
            cout<<k<<" ";
        cout<<"\n";
    }

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

