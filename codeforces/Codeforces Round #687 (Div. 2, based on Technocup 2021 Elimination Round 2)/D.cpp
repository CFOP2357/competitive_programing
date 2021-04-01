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

#include <time.h>

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
ull n, m;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    for(int i=2; i<n; i++){
        if((a[i]^a[i-1])<a[i-2]){
            cout<<"1\n";
            return;
        }
    }


    ull ans = 500;

    for(ull i=1; i<n; i++){
        ull acum1 = 0, acum2 = 0;

        for(ull j=i; j<n; j++){
            acum1 ^= a[j];
            acum2 = 0;

            for(ull k=i-1; k>=0; k--){
                acum2 ^= a[k];

                if(acum1 < acum2){
                    ans = min(ans, j-i + i-k-1);
                }

            }

        }
    }

    if(ans == 500)
        cout<<"-1\n";
    else
        cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

