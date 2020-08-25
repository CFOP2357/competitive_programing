#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

inline ull subMod(ull a, ull b){
    return ((a+MOD)-b)%MOD;
}


void solve(){
    ull p, f;
    cin>>p>>f;
    ull cs, cw;
    cin>>cs>>cw;
    ull s, w;
    cin>>s>>w;

    if(p>f) swap(f, p);
    if(w>s){
        swap(w, s);
        swap(cs, cw);
    }

    ull ans = 0;
    for(ull i=0; i<=cw; i++){
        if(w*i <= p){
            ull a = 0;
            ull p_=p, f_=f;
            ull cs_=cs, cw_=cw;

            a += i;
            p_ -= i*w;
            a += min(p_/s, cs_);
            cs_ -= min(p_/s, cs_);
            cw_ -= i;

            a += min(f_/w, cw_);
            f_ -= min(f_/w, cw_)*w;
            a += min(f_/s, cs_);

            ans = max(ans, a);
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
}
