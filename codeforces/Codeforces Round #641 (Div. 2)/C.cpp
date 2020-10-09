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

template<typename T = ull> struct ST{
    int l, r;
    T acum;

    ST *left, *right;

    T none = -1;

    T operation(T a, T b){
        if(b == -1)
            return a;
        if(a == -1)
            return b;
        return __gcd(a, b);
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
        //cout<<this->l<<" "<<this->r<<" "<<this->acum<<"\n";
        if(this->l >= l && this->r <= r)
            return acum;
        int m = (l+r)/2;
        return operation(left->get(l, r), right->get(l, r));
    }

    T update(int i, T v){
        if(i > r || i < l)
            return acum;

        if(i>=l && i<=r){
            if(l==r)
                return acum = v;
            acum = operation(left->update(i, v), right->update(i, v));
        }
        return acum;
    }

};

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    a.clear(); b.clear();
    cin>>n;

    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    ST<ull> st(0, n-1, a);

    b.push_back(st.get(1, n-1));
    for(int i=1; i<n-1; i++)
        b.push_back(__gcd(st.get(0, i-1), st.get(i+1, n-1)));
    b.push_back(st.get(0, n-2));

    ull ans = st.get(0, n-1);

    //cout<<st.get(0, n+2)<<"\n";

    for(ull mult : b){
        ans = (ans*mult)/__gcd(ans, mult);
        //cout<<mult<<" ";
    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

