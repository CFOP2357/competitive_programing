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
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }


    int p = 0, k = 1;
    int max_height = 0;
    int last_element = INT_MAX;

    for(int i=1; i<n; i++){
        //cout<<max_height<<"\n";
        if(a[i]<last_element){
            if(p){
                p--;
                k++;
            }
            else {
                p = k;
                k = 0;
                p--;
                k++;
                max_height++;
            }
            last_element  = a[i];
        }
        else {
            last_element  = a[i];
            k++;
        }
    }

    cout<<max_height<<"\n";

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
11
1 31 19 44 36 25 3 27 39 41 14
*/
