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

#include <assert.h>

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

typedef int ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
vector<int> p;
ull n, m;
string s;

vector<int> one;

vector<bool> selected;
ull calculate(int current_one, int i, int sz = 1){
    if(selected[i])
        return 0;

    //cout<<i<<" "<<sz<<"\n";
    if(sz == n){
        return 1;
    }

    selected[i] = true;

    ull ans = 0;

    int nxt;
    int nxt_sz = INT_MAX;
    if(current_one==one.size()-1){
        for(int j = i-1; j>=0; j--){
            if(!selected[j] && a[j]<nxt_sz){
                nxt_sz = a[j];
                nxt = j;
            }
            if(a[j]==1){
                if(nxt_sz < INT_MAX)
                    ans += calculate(current_one, nxt, sz+1);
                nxt_sz = INT_MAX;
            }
        }
        if(nxt_sz < INT_MAX)
                    ans += calculate(current_one, nxt, sz+1);
    }
    else {
        ans += calculate(current_one+1, one[current_one+1], sz+1);
    }


    nxt_sz = INT_MAX;
    for(int j = n-1; j>i; j--){
        if(!selected[j] && a[j]<nxt_sz){
            nxt_sz = a[j];
            nxt = j;
        }
    }
    if(nxt_sz < INT_MAX)
        ans += calculate(current_one, nxt, sz+1);

    selected[i] = false;

    return ans;
}

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    assert(n<=13);

    for(int i=0; i<n; i++){
        if(a[i]>a[i-1]+1){
            cout<<"0\n";
            return;
        }

    }

    for(int i=n-1;i>=0; i--)
        if(a[i]==1)
            one.push_back(i);
    selected.assign(n, false);

    ull ans = calculate(0, one[0]);

    cout<<ans<<"\n";
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
4
1 2 2 1
*/
