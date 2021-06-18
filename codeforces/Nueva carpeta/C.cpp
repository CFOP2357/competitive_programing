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
    sort(all(a));

    ull min_dist = LLONG_MAX;
    ull pos_min = -1;
    for(int i=1; i<n; i++){
        if(a[i]-a[i-1] < min_dist){
            min_dist = a[i]-a[i-1];
            pos_min = i;
        }
    }

    if(a[1]-a[0] == min_dist)
        pos_min = 1;
    else if(a[n-1]-a[n-2] == min_dist)
        pos_min = n-1;

    b.push_back(a[pos_min]);
    ull j = pos_min+1;
    j%=n;
    while(j!=pos_min){
        b.push_back(a[j]);

        j++;
        j%=n;
    }
    swap(b[0], b[n-1]);

    for(auto k : b)
        cout<<k<<" ";
    cout<<"\n";
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

