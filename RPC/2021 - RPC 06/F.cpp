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
ull n, m, t, s;

void solve(){
    a.clear(); b.clear();
    cin>>t>>s>>n;
    ull up(0), down(s);
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    ull current_time = 0;
    int i = 0;
    while(current_time<t){
        //cout<<up<<" "<<down<<"\n";
        if(i<n && current_time==a[i]){
            //cout<<up<<" "<<down<<"\n";
            swap(up, down);
            i++;
            //cout<<up<<" "<<down<<"\n";
        }
        if(up){
            up--;
            down++;
        }
        current_time++;
    }
    cout<<up<<"\n";
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

