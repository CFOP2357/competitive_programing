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

vector<ull> a;

ull n, q;

set<ull> possible;

bool areEqual(int i, int j){
    for(int k=i+1; i<=j; k++)
        if(a[k]!=a[k-1])
            return false;
    return true;
}

ull get_sum(int i, int j){
    ull ans = 0;
    for(;i<=j; i++)
        ans+=a[i];
    return ans;
}

void print(int i, int j){
    for(int k=i;k<=j; k++)
        cout<<a[k]<<" ";
    cout<<"| "<<get_sum(i, j)<<"\n";
}

void op(int i, int j, int last_i=-1, int last_j=-1){
    //print(i, j);

    possible.insert(get_sum(i, j));

    if(i>=j || j>=n || i<0 || areEqual(i, j))
        return;

    if(i==last_i && j==last_j)
        return;

    ull mid = (*max_element(a.begin()+i, a.begin()+j+1)+*min_element(a.begin()+i, a.begin()+j+1))/2;

    int m = upper_bound(all(a), mid) - a.begin();

    op(m, j, i, j);
    op(i, m-1, i, j);

}

void solve(){
    a.clear(); possible.clear();

    cin>>n>>q;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }
    sort(all(a));

    op(0, n-1);

    while(q--){
        ull s; cin>>s;
        if(possible.find(s)!=possible.end())
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
1
5 5
1 2 3 4 5
1
8
9
12
6

1
5 5
3 1 3 1 3
1
2
3
9
11
*/
