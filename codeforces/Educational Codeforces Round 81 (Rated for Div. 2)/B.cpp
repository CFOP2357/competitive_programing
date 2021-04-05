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
ull n, m, x;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n>>x;
    cin>>s;

    ull k = 0;
    for(char c : s){
        if(c=='0')
            k++;
        else
            k--;

        b.push_back(k);
    }

    ull ans = 0;
    if(!x)
        ans++;

    if(k){

        for(ull bi : b){

            ull d = x-bi;
            if(!(d%k) && d/k>=0){
                ans++;
            }

        }

    }
    else {
        for(ull bi : b)
            if(bi==x){
                ans = -1;
            }

    }


    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

