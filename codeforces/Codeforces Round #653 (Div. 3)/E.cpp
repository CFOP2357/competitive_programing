#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define findOrd find_by_order
#define findkwy order_of_key
*/

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

inline ull subMod(ull a, ull b){
    return ((a+MOD)-b)%MOD;
}

vector <ull> a;
vector <ull> b;
vector <ull> c;

void solve(){
    int n, k; cin>>n>>k;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        bool A, B; cin>>A>>B;

        if(A&&B)
            c.push_back(z);
        else if(A)
            a.push_back(z);
        else if(B)
            b.push_back(z);
    }

    if(c.size()+a.size() < k || c.size()+b.size() < k){
        cout<<"-1\n";
        return;
    }

    sort(a.begin(), a.end(), greater<ull>());
    sort(b.begin(), b.end(), greater<ull>());
    sort(c.begin(), c.end(), greater<ull>());

    ull ans = 0;
    while(k--){
        if(c.size() && a.size() && b.size()){
            if(a.back() + b.back() < c.back()){
                ans += a.back() + b.back();
                a.pop_back();
                b.pop_back();
            }
            else {
                ans += c.back();
                c.pop_back();
            }
        }
        else if(c.size()){
            ans += c.back();
            c.pop_back();
        }
        else {
            ans += a.back() + b.back();
            a.pop_back();
            b.pop_back();
        }
    }


    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}

