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

void change(string &a, int i){
    string b = a.substr(0, i);
    for(char &c : b)
        if(c=='1')
            c='0';
        else c='1';
    reverse(b.begin(), b.end());
    //cout<<b<<"%\n";
    a = b + a.substr(i);
}

void solve(){
    string a, b;
    cin>>n;
    cin>>a>>b;

    vector<int> ans;
    for(int i=n-1; i>0; i--){
        if(a[i]!=b[i]){
            if(a[0] != a[i]){
                ans.push_back(1);
                a[i] = a[i];
            }
            ans.push_back(i+1);
            change(a, i+1);
            //cout<<a<<"#\n";
        }
    }
    if(a[0]!=b[0])
        ans.push_back(1);

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
