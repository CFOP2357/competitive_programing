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

#define MAX 200100
#define MOD 1000000007

ull n;

ull seg[MAX];


void solve(){

    cin>>n;
    ull s = 0;
    map<ull, ull> pos; //sum, pos
    int finded = 0;
    int zero = 0;
    ull ans = 0;
    for(int i=1; i<=n; i++){
        ull z; cin>>z;
        s += z;
        if(s==0 && !zero)
            zero = i;
        if(pos[s]){
            if(!finded) finded = pos[s]+1;
            seg[pos[s]+1] = i;
        }
        pos[s] = i;
        //cout<<s<<" ";
    }//cout<<"\n";

    /*for(int i=1; i<=n; i++)
        cout<<seg[i]<<" ";
    cout<<"\n";*/

    ull last = 0;
    for(int i=1; i<=n; i++){
        if(seg[i]){
            if(last > i)
                last = min(last, seg[i]);
            else {
                ans++;
                last = seg[i];
            }

        }
    }

    //cout<<finded<<" "<<zero<<"\n";
    if(zero && (finded>=zero || !finded)) ans++;

    cout<<ans<<"\n";
}

/*
10
1 2 3 -3 -2 -1 4 5 -5 -4

11
1 2 3 -3 -2 -1 4 5 -5 -4 -1
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

