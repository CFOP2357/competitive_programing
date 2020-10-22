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
ull c1,c2,c3,c4,c5,c6;
ull x, y;

void solve(){
    a.clear(); b.clear();
    cin>>x>>y;
    cin>>c1>>c2>>c3>>c4>>c5>>c6;

    ull ans = 0;

    if(x>0)
        ans += c6*x;
    else ans += c3*(-x);

    if(y>0)
        ans += c2*y;
    else ans += c5*(-y);

    //cout<<ans<<"\n";


    {
        ull tmp =  0;
        if((x-y)>0)
            tmp += c6*(x-y);
        else tmp += c3*(y-x);
        if(y>0)
            tmp += c1*y;
        else tmp += c4*(-y);

        ans = min(ans, tmp);
        //cout<<tmp<<"\n";
    }

    {
        ull tmp =  0;
        if(x>0)
            tmp += c1*x;
        else tmp += c4*(-x);
        //cout<<tmp<<"\n";
        if((x-y)>0)
            tmp += c5*(x-y);
        else tmp += c2*(y-x);

        //cout<<x-y<<"\n";

        ans = min(ans, tmp);

        //cout<<tmp<<"\n";

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

/*
1
0 -9
16 7 12 26 25 30
*/
