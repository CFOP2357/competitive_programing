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

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    ull sum = 0;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        sum += z;
    }

    if(sum%n){
        cout<<"-1\n";
        return;
    }

    vector<ull> I, J, X;

    for(int i=1; i<n; i++){
        int r = (i+1) - a[i]%(i+1);

        if(a[i]%(i+1) == 0) r =0;

        I.push_back(1);
        J.push_back(i+1);
        X.push_back(r);

        a[i] += r;
        a[0] -= r;

        I.push_back(i+1);
        J.push_back(1);
        X.push_back(a[i]/(i+1));

        a[0] += a[i];
        a[i] -= a[i];
    }

    /*for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";*/

    int x = sum/n;
    for(int i=1; i<n; i++){

        I.push_back(1);
        J.push_back(i+1);
        X.push_back(x);

        a[0] -= x;
        a[i] += x;

    }

    /*for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";*/

    cout<<I.size()<<"\n";
    for(int i=0; i<I.size(); i++)
        cout<<I[i]<<" "<<J[i]<<" "<<X[i]<<"\n";


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
3
4
2 16 4 18
6
1 2 3 4 5 6
5
11 19 1 1 3
*/
