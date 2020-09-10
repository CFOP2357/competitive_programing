#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define MAX 1000100
#define MOD 1000000007

ull n;
ull l, r, m;

void solve(){
    cin>>l>>r>>m;

    for(ull i = l; i<=r; i++){ // m = n*i + k
        ull k;
        ull n = m/i;


        if(!n && i-m <= r-l){
            k = i-m;
            cout<<i<<" "<<l<<" "<<l+k<<"\n";
            return;
        }
        else if(n &&  m%i <= r-l){
            k =  m%i;
            cout<<i<<" "<<l + k<<" "<<l<<"\n"; // k = b - c
            return;
        }
        else {
            n = (m+i)/i;
            k = (n*i) - m;
            if(k<=r-l){
                cout<<i<<" "<<l<<" "<<l+k<<"\n";
                return;
            }
        }

    }

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

/*
20
10 12 43
25 49 1
5 7 39
8 9 44
16 17 50
30 40 975
601 801 1000
100 102 909
599 799 1000
503 997 9
194 383 5
90000 100000 709999
75000 100000 124999
375000 499999 625001
375000 500000 624999
300000 400000 499999
250000 500000 1
70000 80000 2272770257
70000 80000 9999953344
90000 100000 9999955820

1
10 12 43
*/
