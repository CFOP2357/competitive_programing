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
typedef long long ll;
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
    cin>>s;

    vector<int> R;
    vector<int> Y;
    vector<int> B;

    for(char color : s){
        if(color == 'B' or color == 'P' or color == 'G' or color == 'A')
            B.push_back(1);
        else
            B.push_back(0);

        if(color == 'Y' or color == 'O' or color == 'G' or color == 'A')
            Y.push_back(1);
        else
            Y.push_back(0);

        if(color == 'R' or color == 'O' or color == 'P' or color == 'A')
            R.push_back(1);
        else
            R.push_back(0);
    }


    ll ans = 0;
    for(int i = 1; i < n; i++)
        if(R[i-1] == 1 and R[i] == 0)
            ans++;
    if(R.back() == 1)
        ans++;

    for(int i = 1; i < n; i++)
        if(Y[i-1] == 1 and Y[i] == 0)
            ans++;
    if(Y.back() == 1)
        ans++;

    for(int i = 1; i < n; i++)
        if(B[i-1] == 1 and B[i] == 0)
            ans++;
    if(B.back() == 1)
        ans++;

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


