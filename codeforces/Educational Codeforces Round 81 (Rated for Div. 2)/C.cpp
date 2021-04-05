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
string s,t;

void solve(){
    cin>>s>>t;

    unordered_map<char, vector<int>> position;
    for(int i=0; i<s.size(); i++)
        position[s[i]].push_back(i);

    for(char c : t)
        if(!position[c].size()){
            cout<<"-1\n";
            return;
        }

    ull ans = 1;
    int i=0;
    for(char c : t){

        auto nxt = lower_bound(all(position[c]), i);

        if(nxt == position[c].end()){
            ans++;
            i=position[c][0]+1;
        }
        else {
            i = *nxt + 1;
        }

    }


    cout<<ans<<"\n";

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

