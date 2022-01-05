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
typedef long long ll;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s, f;

void solve(){
    cin>>s>>f;

    map<char, bool> is_favorite;
    for(auto character : f)
        is_favorite[character] = true;

    ll ans = 0;
    for(auto character : s){
        ll current_ans = 30;
        if(is_favorite[character])
            current_ans = 0;

        for(ll c = character+1, j = 1; c != character; j++){
            if(c == 'z'+1)
                c = 'a';

            if(is_favorite[c])
                current_ans = min(current_ans, j);

            if(c == 'z')
                c = 'a';
            else c++;
        }

        for(ll c = character-1, j = 1; c != character; j++){
            if(c == 'a'-1)
                c = 'z';

            if(is_favorite[c])
                current_ans = min(current_ans, j);

            if(c == 'a')
                c = 'z';
            else c--;
        }

        ans += current_ans;
    }

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}


