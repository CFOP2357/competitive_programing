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
ull n, m, N;
string s;

ull d[MAX];

void solve(){
    cin>>N;

    ull i;
    ull ans = 1;

    for(i = 3; i<=N; i++){
        if(!(N%i)){
            ull current = i;
            n = N;

            ull current_ans = 1;
            n-=current;
            while(current<n && !(n%current)){
                current_ans++;
                current *= d[n/current];
                n -= current;
            }

            ans = max(ans, current_ans);
        }
    }


    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    for(ull i = 2; i<MAX; i++){
        if(d[i])
            continue;
        for(ull j = i; j<MAX; j+=i){
            if(!d[j])
                d[j] = i;
        }
    }

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}


