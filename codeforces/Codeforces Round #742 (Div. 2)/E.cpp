//#include <bits/stdc++.h>
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

//#include <time.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
#define MOD 1000000007

struct Segment{
    ll left = 0;
    ll right = 0;
    ll ans = 0;
    bool divided = false;
};

ll gauss(ll n){
    return (n*(n+1))/(ll)2;
}

template<typename T> struct ST{
    int l, r;
    T acum;

    ST *left, *right;

    T none = {0, 0, 0, 0};

    T operation(T a, T b){
        Segment s;
        if(a.divided and b.divided){
            s.ans += gauss(a.right + b.left);
        }
        else if(a.divided and !b.divided){
            s.right = a.right + b.right + b.left;
        }
        else if(!a.divided and b.divided){
            s.left = a.left + a.right + b.left;
        }
        else {
            s.left = a.left + a.right + b.right + b.left;
        }

        s.divided = (a.divided or b.divided);


        return s;
    }

    ST(int l, int r, vector<T> &arr): l(l), r(r){
        if(l >= arr.size())
            acum = none;
        else if(l==r)
            acum = arr[r];
        else {
            int m = (l+r)/2;
            left = new ST(l, m, arr);
            right = new ST(m+1, r, arr);
            acum = operation(left->acum,  right->acum);
        }
    }

    T get(int l, int r){
        if(this->l > r || this->r < l)
            return none;
        if(this->l >= l && this->r <= r)
            return acum;
        int m = (l+r)/2;
        return operation(left->get(l, r), right->get(l, r));
    }

    T update(int i, T v){

        if(i>=l && i<=r){
            if(l==r)
                return acum = v;
            acum = operation(left->update(i, v), right->update(i, v));
        }
        return acum;
    }

};


vector<ll> a;
vector<ll> b;
ll n, m;
string s;

void solve(){
    ll n, q; cin>>n>>q;

    vector<Segment> init(n+1);
    ST<Segment> st(0, init.size()-1, init);

    a.push_back(LLONG_MAX);
    for(int i = 1; i <= n; i++){
        ll z; cin>>z;
        a.push_back(z);

        if(a[i] >= a[i-1])
            st.update(i, {1, 0, 0, 0});
        else
            st.update(i, {0, 0, 0, 1});
    }

    while(q--){
        int t; cin>>t;
        if(t==1){
            int i, y; cin>>i>>y;
            a[i] = y;

            if(a[i] >= a[i-1])
            st.update(i, {1, 0, 0, 0});
            else
                st.update(i, {0, 0, 0, 1});
        }
        else {
            int l, r; cin>>l>>r;
            auto s = st.get(l+1, r+1);

            ll ans = 0;
            if(s.divided){
                ans += gauss(s.left) + gauss(s.right);
            }
            else {
                ans += s.left + s.right;
                ans = gauss(ans);
            }

            ans += s.ans;
            cout<<ans<<"\n";
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

