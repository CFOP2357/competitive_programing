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

    vector<int> bitTimes(50);
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);

        int j =0;
        while(z){
            if(z%2)
                bitTimes[j]++;
            z/=2;
            j++;
        }
    }

    ull ans = 0;
    int ind = 0;
    for(int i=0; i<n; i++){

        ull total = 0;

        ull z = a[i];
        int j =0;
        while(z){
            if(z%2 && bitTimes[j] == 1){
                total |= 1<<j;
            }
            j++; z/=2;
        }
        //cout<<total<<" ";

        if(total > ans){
            ind = i;
            ans = total;
        }

    }
    //cout<<"\n";

    swap(a[0], a[ind]);

    for(ull k : a)
        cout<<k<<" ";
    cout<<"\n";

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

/*
5
4 4 20 20 1
*/

