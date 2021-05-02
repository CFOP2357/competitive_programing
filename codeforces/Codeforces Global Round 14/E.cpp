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

#define MAX 500
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

bool state[MAX];
ull simulate(int current_computer, set<int> &turned_off){
    if(state[current_computer])
        return 0;
    state[current_computer] = true;
    turned_off.erase(current_computer);

    vector<int> automatic;
    for(int i=2; i<n; i++)
        if(!state[i] && state[i-1] && state[i+1]){
            state[i] = true;
            automatic.push_back(i);
            turned_off.erase(i);
        }

    ull ans = 0;
    if(!turned_off.size())
        ans = 1;

    set<int> try_ = turned_off;
    for(auto computer : try_){
        ans += simulate(computer, turned_off);
        ans %= m;
    }

    for(auto computer : automatic){
        state[computer] = false;
        turned_off.insert(computer);
    }
    turned_off.insert(current_computer);
    state[current_computer] = false;

    return ans;
}

void solve(){
    a.clear(); b.clear();
    cin>>n>>m;

    ull ans = 0;
    set<int> turned_off;
    for(int i=1; i<=n; i++)
        turned_off.insert(i);
    for(int i=1; i<=n; i++){
        ans += simulate(i, turned_off);
        ans %= m;
    }

    cout<<ans%m<<"\n";

}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

/*
2
13423521

4 100000007

7 100000007
*/
