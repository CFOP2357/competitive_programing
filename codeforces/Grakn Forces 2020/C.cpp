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
ull n, sz;

double getTime(double t, double d1, double d2, double v){
    return (d2-d1)/v + t;
}

void solve(){
    a.clear(); b.clear();
    cin>>n>>sz;

    a.push_back(0);
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }
    a.push_back(sz);

    int l(0), r(n+1);
    double pos1=0, pos2=a[n-1];
    double t1=0, t2=0;
    double v1=1, v2=1;
    //cout<<r<<"\n";
    while(l+1<r){
        //cout<<a[r-1]<<"& ";
        if(getTime(t1, a[l], a[l+1], v1) < getTime(t2, a[r-1], a[r], v2)){
            //cout<<1<<"% ";
            t1 = getTime(t1, a[l], a[l+1], v1);
            l++; v1++;
        }
        else {
            //cout<<2<<"% ";
            t2 = getTime(t2, a[r-1], a[r], v2);
            r--; v2++;
        }

        //cout<<t1<<" "<<t2<<" # ";
        //cout<<l<<" "<<r<<"\n";
    }

    if(t1 < t2){
        pos1 = a[l] + v1*(t2-t1);
        pos2 = a[r];
        t1 = t2;
    }
    else {
        pos2 = a[r] - v2*(t1-t2);
        pos1 = a[l];
        t2 = t1;
    }


    double ans = t1 + (pos2-pos1)/(v1+v2);
    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cout.precision(100);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
/*
1
2 10
1 9

1
5 7
1 2 3 4 6
*/
