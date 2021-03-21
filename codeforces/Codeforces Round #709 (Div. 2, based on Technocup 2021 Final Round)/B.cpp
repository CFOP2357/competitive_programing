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

    ull d = 0;
    ull m = 0;
    bool hasIncrease = false;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);

        if(i>0 && a[i]>a[i-1]){
            hasIncrease = true;
            d = a[i]-a[i-1];
        }
        else if(i>0 && d){
            m = d+a[i-1]-a[i];
        }
    }

    for(int i=1; i<n; i++){
        if(a[i]>a[i-1]){
            hasIncrease = true;
            d = a[i]-a[i-1];
        }
        else if(d){
            m = d+a[i-1]-a[i];
        }
    }

    if(n==1){
        cout<<"0\n";
        return;
    }

    if(!hasIncrease){

        ull d = a[1]-a[0];

        for(int i=1; i<n; i++)
            if(a[i]-a[i-1] != d){
                cout<<"-1\n";
                return;
            }

        cout<<"0\n";
        return;

    }

    ull current = a[0];
    for(ull k : a){
        if(k!=current || (m && k>=m)){
            cout<<"-1\n";
            return;
        }
        current += d;
        if(m){
            current %= m;
        }
    }

    if(!m){
        cout<<"0\n";
        return;
    }

    cout<<m<<" "<<d<<"\n";


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

/*
1
5
0 5 10 15 20
*/

