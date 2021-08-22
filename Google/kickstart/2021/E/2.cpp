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
typedef long long ll;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
ll R, C, k;
ll r1, c1, r2, c2;
string s;

void solve(){
    cin>>R>>C>>k;
    cin>>r1>>c1>>r2>>c2;

    ll r = r2-r1+1;
    ll c = c2-c1+1;

    ll cost = LLONG_MAX;

    {
        ll current = 0;
        current += r2/k;
        if(r2%k)
            current++;
        current += r/k;
        if(r%k)
            current++;
        current += 2 * (c/k);
        if(c%k)
            current += 2;

        cost = min(cost, current);
    }

    {
        ll current = 0;
        current += (R-r1+1)/k;
        if((R-r1+1)%k)
            current++;
        current += r/k;
        if(r%k)
            current++;
        current += 2 * (c/k);
        if(c%k)
            current += 2;

        cost = min(cost, current);
    }

    {
        ll current = 0;
        current += (C-c1+1)/k;
        if((C-c1+1)%k)
            current++;
        current += c/k;
        if(c%k)
            current++;
        current += 2 * (r/k);
        if(r%k)
            current += 2;

        cost = min(cost, current);
    }

    {
        ll current = 0;
        current += c2/k;
        if(c2%k)
            current++;
        current += c/k;
        if(c%k)
            current++;
        current += 2 * (r/k);
        if(r%k)
            current += 2;

        cost = min(cost, current);
    }

    if(r1 == 1){
        cost -= c/k;
        if(c%k)
            cost--;
    }
    if(r2 == R){
        cost -= c/k;
        if(c%k)
            cost--;
    }
    if(c1 == 1){
        cost -= r/k;
        if(r%k)
            cost--;
    }
    if(c2 == C){
        cost -= r/k;
        if(r%k)
            cost--;
    }

    //cout<<cost<<"#\n";
    ll cost1 = (r-1)*c + (r/k)*(c-1);
    if(r%k)
        cost1 += (c-1);

    ll cost2 = (c-1)*r + (c/k)*(r-1);
    if(c%k)
        cost2 += (r-1);

    cost += min(cost1, cost2);

    cout<<cost<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}

/*
1
7 7 3
3 2 5 4

1
7 5 3
2 2 5 5

4
7 5 3
2 2 4 5
7 5 3
1 2 4 4
7 5 3
4 1 6 4
7 5 3
4 2 7 4

1
10 10 3
1 1 4 4

1
4 4 3
1 1 4 4

2
100000 99999 997
1 1 100000 99999
99999 100000 997
1 1 99999 100000

2
100000 99999 997
2 2 555 776
100000 99999 997
12 12 565 786
*/

