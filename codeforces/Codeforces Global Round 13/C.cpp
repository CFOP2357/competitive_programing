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

bool allOne(){

    for(auto& k : a)
        k = max(k, (ull)1);

    for(auto& k : a){
        if(k>1)
            return false;
    }
    return true;
}

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    /*n = 1000;
    for(int i=0; i<n; i++)
        a.push_back(100);*/

    b.assign(n+10, 0);
    ull ans =0;
    while(!allOne()){

        ans++;
        ull i=0;
        ull j = -1;
        while(i<n){

            if( j == -1 && a[i] > 1){
                j=i;
                if(b[j]){
                    ans--;
                    b[j]--;
                }
            }

            i += a[i]--;

        }

        if(a[j] > n-j){
            ans += a[j] - (n-j);
            a[j] = n-j;
            ans -= min(b[j], a[j] - (n-j));
            b[j] -= min(b[j], a[j] - (n-j));
            if(b[j]>0 && a[j] == 1)
                b[j+1] += b[j];
        }
        else if(a[j]>1){
            ans += a[j] - 1;
            ans -= min(b[j], a[j]-1);

            for(int k = j+2; k<=j+a[j] && k<n; k++){
                b[k]++;
               b[j]--;
            }

            if(b[j]>0)
                b[j+1] += b[j];


            a[j] = 1;
        }
        else b[j+1] += b[j];



    }


    //cout<<b[n]<<" ";

    cout<<ans-b[n]<<"\n";

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
10
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000

1 4 2 2 2 2 2
1 3 2 2 2 1 2 = 1
1 1 2 2 2 1 2 = 3
1 1 1 2 1 1 1 = 4
1 1 1 2 1 1 1 = 3

1
1000
100 100 ...
= 5049
*/
