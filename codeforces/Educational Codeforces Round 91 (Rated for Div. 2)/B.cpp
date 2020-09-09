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

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    a.clear(); b.clear();
    string S; cin>>S;

    int r(0), s(0), p(0);
    for(char c :  S)
        if(c=='R') r++;
        else if(c=='S') s++;
        else p++;

    char ans;
    if(s>=p && s>=r)
        ans = 'R';
    else if(s<=p && p>=r)
        ans = 'S';
    else if(r>=p && s<=r)
        ans = 'P';

    for(int i=0; i<S.size(); i++)
        cout<<ans;
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

