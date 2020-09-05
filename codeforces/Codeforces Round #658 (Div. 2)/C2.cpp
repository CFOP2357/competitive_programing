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

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

ull n;


void solve(){
    string a, b;
    cin>>n;
    cin>>a>>b;

    vector<int> ans;
    char actual = a[0];
    for(int i=0; i<a.size(); i++){
        if(a[i]!=actual){
            ans.push_back(i);
            actual = a[i];
        }
    }

    for(int i=n-1; i>=0; i--){
        if(actual != b[i]){
            ans.push_back(i+1);
            actual = b[i];
        }
    }


    cout<<ans.size()<<" ";
    for(int r : ans)
        cout<<r<<" ";
    cout<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

/*
1
2
01
10
*/
