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

vector<ull> value;
multiset<pair<ull, int>, greater<pair<ull, int>>> element; //value, id
set<int> deleted;
ull n;
bool apart[MAX];

void solve(){
    value.clear();
    cin>>n;
    ull ans = 0;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        value.push_back(z);
    }

    for(int d=0; d<n; d++){
        element.insert({value[d], d});
    }


    /*if(n==3){
        int d = element.begin()->second;
        element.erase(element.begin());
        ans+=value[d];
        apart[d]=true;
        d = element.begin()->second;
        element.erase(element.begin());
        ans+=value[d];
        apart[d]=true;
    }*/
    while(element.size()){
        int d = element.begin()->second;
        element.erase(element.begin());
        int a = (d+1)%n, b = d-1<0?n-1:d-1;
        if(!apart[a] || !apart[b]){
            ans+=value[d];
            apart[d]=true;
        }
    }

    cout<<ans<<"\n";


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

