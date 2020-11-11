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
ull n;

ull brute(ull l, ull r, ull a, ull b){
    //cout<<l<<" "<<r<<" "<<a<<" "<<b<<"#\n";
    ull ans = 0;
    for(ull i = l; i<=r; i++)
        if( (i%a)%b != (i%b)%a )
            ans++;
    return ans;
}

void solve(){
    ull a, b, q; cin>>a>>b>>q;

    if(b>a)
        swap(a, b);

    ull d = a*__gcd(a, b);
    if(__gcd(a, b)==1)
        d=a*b;
    //ull inc = ;

    while(q--){
        ull l, r; cin>>l>>r;
        cout<<brute(l, r, a, b)<<" ";
        if(a%b == 0)
            cout<<0<<" ";
        else {

            ull ans = 0;
            while(l<=r &&  l%a){
                if( (l%a)%b != (l%b)%a )
                    ans++;
                l++;
            }

            //cout<<ans<<"#\n";

            while(l<=r &&  (r+1)%a){
                if( (r%a)%b != (r%b)%a )
                    ans++;
                r--;
            }

            //cout<<ans<<"#\n";

            while(l<=r && (l%a)%b != (l%b)%a ){
                ans += a;
                l += a;
                //cout<<ans<<" ";
            } //cout<<"#\n";

            if(l<=r){
                ull sz = (r-l + 1);
                ans += sz - a*(sz/d + (ull)((bool)(sz%d)));
            }

            cout<<ans<<" ";

        }
    }

    cout<<"\n";

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
3 7 1
1 30

3
3 7 3
1 32
1 100
7 30
2 10 3
1 100
2 10
1 1
3 10 3
1 1
1 100
10 30
*/

