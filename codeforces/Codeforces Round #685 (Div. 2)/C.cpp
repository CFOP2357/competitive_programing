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

ull n, k;
string a, b;

void solve(){
    cin>>n>>k;
    cin>>a;
    cin>>b;

    map<int, int> times_;

    for(char c : a)
        times_[c]++;
    for(char c : b){
        times_[c]--;
    }

    int toChange = 0;
    for(auto &p : times_){
        if(p.second < 0){
            toChange -= abs(p.second);
            p.second = 0;
        }
        else {
            if(p.second%k){
                cout<<"No\n";
                return;
            }
            toChange += p.second;
        }

        if(toChange < 0 || toChange%k){
            cout<<"No\n";
            return;
        }


    }

    cout<<"Yes\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

