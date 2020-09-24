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
#define rep(i, a, b) for(int i =a; i< (b); ++i)

typedef long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 300100
#define MOD 998244353

typedef ull ll;

ll euclid(ll a, ll b, ll &x, ll &y){
    if(b) {ll d = euclid(b, a%b, y, x);
            return y -= a/b * x, d;}
    return x=1, y=0, a;
}

struct Mod{
    ll x;
    Mod(ll xx):x(xx){}
    Mod operator+ (Mod b){return Mod((x+b.x)%MOD);}
    Mod operator- (Mod b){return Mod((x-b.x+MOD)%MOD);}
    Mod operator* (Mod b){return Mod((x*b.x)%MOD);}
    Mod operator/ (Mod b){return *this * invert(b);}

    Mod invert(Mod a){
        ll x, y, q = euclid(a.x, MOD, x, y);
        return Mod((x+MOD)%MOD);
    }
};

vector<ull> a;
vector<ull> b;
ull n, k;

vector<Mod> fact(MAX, Mod(0));

void solve(){
    a.clear(); b.clear();
    cin>>n>>k;
    vector<pii> nxt;
    for(int i=0; i<n; i++){
        int l, r; cin>>l>>r;
        nxt.push_back({l, 1});
        nxt.push_back({r, 2});
    }

    sort(all(nxt));

    fact[1] = Mod(1);
    fact[0] = Mod(1);
    for(int i=2; i<MAX; i++){
        fact[i] = fact[i-1]*i;
    }

    Mod ans(0);
    Mod sz(0);
    for(auto p : nxt){
        //cout<<sz.x<<"\n";
        if(p.second == 2){
            sz = sz-1;
        }
        else {
            if(sz.x>=k-1){
                //cout<<"#";
                ans = ans + (fact[sz.x])/(fact[sz.x - (k-1)]*fact[k-1]);
            }

            sz = sz+1;
        }
    }

    cout<<ans.x<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

