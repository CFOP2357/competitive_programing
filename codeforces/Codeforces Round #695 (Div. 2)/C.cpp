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

vector<ull> a[3];
vector<ull> b;
ull n[3];

void solve(){

    for(int i=0; i<3; i++) cin>>n[i];

    ull sum = 0;
    for(int j=0; j<3; j++)
        for(int i=0; i<n[j]; i++){
            ull z; cin>>z;
            a[j].push_back(z);
            sum+=z;
        }

    for(int j=0; j<3; j++) sort(all(a[j]));

    //cout<<sum<<"#\n";

    ull ans = LLONG_MIN;
    for(int i = 0; i<3; i++)
        for(int j = 0; j<3; j++){
                ull possibleAns = sum;

                if(i!=j){
                    possibleAns -= a[i][0]*2;
                    possibleAns-=a[j][0]*2;
                }
                else {
                    for(ull k : a[i])
                        possibleAns -= k*2;
                }

                ans = max(possibleAns, ans);
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

