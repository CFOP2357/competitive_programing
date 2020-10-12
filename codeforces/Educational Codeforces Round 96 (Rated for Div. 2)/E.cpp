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

template<typename T> struct ST{
    int l, r;
    T acum;

    ST *left, *right;

    T none = 0;

    T operation(T a, T b){
        return a+b;
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
    string s; cin>>s;
    string r; r = s;
    reverse(all(r));

    stack<int> pos[200];
    for(int i = n-1; i>=0; i--){
        pos[s[i]].push(i);
    }
    //cout<<r<<"\n";

    a.assign(n, -1);
    for(int i = 0; i<n; i++){
        a[i] = pos[r[i]].top();
        pos[r[i]].pop();
    }

    vector<ull> b(n, 0);
    ST<ull> st(0, n-1, b);

    ull ans = 0;
    st.update(a[0], 1);
    //cout<<a[0]<<" ";
    for(int i=1; i<n; i++){
        //cout<<a[i]<<" ";
        ans += st.get(a[i], n-1);
        st.update(a[i], 1);
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

