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

#define MAX 10000007
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

int lp[MAX];

void solve(){
    a.clear(); b.clear();

    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        //cout<<z<<" ";
        ull k = z;

        int t = 0;

        vector<int> d;
        while(z>1){
                //cout<<z<<"\n";
                int j = lp[z];
                d.push_back(j);
                //cout<<j<<"#\n";
                while(z%j==0 && z>1){
                        z/=j;
                        t++;
                }
        }

        if(z>1) d.push_back(z);

        if(d.size()==1){
            a.push_back(-1);
            b.push_back(-1);
        }
        else {
            a.push_back(d[d.size()-2]);
            b.push_back(d.back());
        }

    }

    for(int ans : a) cout<<ans<<" ";
    cout<<"\n";

    for(int ans : b) cout<<ans<<" ";
    cout<<"\n";


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(long long i=2; i<MAX; i++)
        if(!lp[i]){
            lp[i] = i;
            //cout<<i<<"\n";
            for(long long j = i*i; j<MAX; j+=i){
                lp[j] = i;
                //cout<<j<<"\n";
            }
        }

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

