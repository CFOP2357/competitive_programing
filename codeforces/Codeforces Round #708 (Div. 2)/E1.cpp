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

#define MAX 20001000
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m, k;
string s;

ull D[MAX];

void solve(){
    a.clear(); b.clear();
    cin>>n>>k;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    ull ans = 1;
    map<ull, bool> selected;

    for(ull num : a){

        map<ull, ull> d;

        while(num>1){
            d[D[num]]++;
            num /= D[num];
        }

        ull toBan = 1;
        for(auto element : d){
            if(element.second%2)
                toBan*=element.first;
        }

        if(selected[toBan]){
            ans++;
            selected.clear();
        }


        selected[toBan] = true;

    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    for(ull i=2; i<MAX; i++){
        if(D[i])
            continue;
        for(ull j=i; j<MAX; j+=i){
            D[j]=i;
        }
    }


    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

