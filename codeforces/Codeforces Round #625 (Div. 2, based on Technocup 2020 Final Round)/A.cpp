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

vector<ull> r;
vector<ull> b;
ull n;

void solve(){
    r.clear(); b.clear();
    cin>>n;

    for(int i=0; i<n; i++){
        ull z; cin>>z;
        r.push_back(z);
    }

    for(int i=0; i<n; i++){
        ull z; cin>>z;
        b.push_back(z);
    }

    ull rc = 0, bs = 0;

    for(int i=0; i<n; i++){

        if(r[i]!=b[i]){

            if(r[i])
                rc++;
            else
                bs++;

        }

    }

    if(!rc)
        cout<<"-1\n";
    else if(rc>bs)
        cout<<"1\n";
    else
        cout<< (bs+1)/rc + (ull)(bool)((bs+1)%rc) <<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

