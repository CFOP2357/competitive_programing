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

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    string s; cin>>s;
    int odd(0), even(0);

    if(n==1){
        if((s[0]-'0')%2)
            cout<<"1\n";
        else cout<<"2\n";
        return;
    }

    if(n%2){ //Raze last
        for(int i=0; i<n; i+=2)
            if((s[i]-'0')%2)
                odd++;
            else even++;
        if(odd)
            cout<<"1\n";
        else cout<<"2\n";
    }
    else {
        for(int i=1; i<n; i+=2)
            if((s[i]-'0')%2)
                odd++;
            else even++;
        if(even)
            cout<<"2\n";
        else cout<<"1\n";
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

