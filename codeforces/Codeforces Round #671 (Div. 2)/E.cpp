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

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    a.clear(); b.clear();

    cin>>n;


    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            a.push_back(i);
            if(i*i!=n)
                a.push_back(n/i);
        }
    }

    sort(all(a));

    vector<int> primes;
    map<int, bool> selected;

    for(int k : a){
        if(selected[k])
            continue;
        primes.push_back(k);
        selected[k] = true;
        for(int p : a){
            if(p%k == 0)
                selected[p] = true;
        }
    }

    selected.clear();
    bool in = false;
    for(int i = 0; i<primes.size(); i++){
        cout<<primes[i]<<" ";
        selected[primes[i]] = true;

        for(int k : a){
            if(selected[k] || (i+1<primes.size() && k==primes[i]*primes[i+1]) )
                continue;

            if(k%primes[i] == 0){
                selected[k] = true;
                cout<<k<<" ";
            }
        }

        if(i+1<primes.size()){
            if(primes[i]*primes[i+1] != n){
                cout<<primes[i]*primes[i+1]<<" ";
                selected[primes[i]*primes[i+1]] = true;
            }
            else in = true;
        }
    }

    cout<<n<<"\n";

    cout<<in<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

