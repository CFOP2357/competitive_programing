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

bool primo(int n){
    for(int i=2; i*i<=n; i++)
        if(n%i == 0) return false;
    return true;
}

void solve(){
    cin>>n;

    if(n==1)
        cout<<"FastestFinger\n";
    else if(n%2 || n==2)
        cout<<"Ashishgup\n";
    else {
        int p = 0;
        while(n%2 == 0){
            n/=2;
            p++;
        }
        if(n==1)
            cout<<"FastestFinger\n";
        else if(p>1 || !primo(n))
            cout<<"Ashishgup\n";
        else
            cout<<"FastestFinger\n";
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

