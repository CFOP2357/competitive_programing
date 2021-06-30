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
    string p, h;
    cin>>p>>h;

    map<char, ull> p_frecuency;
    for(char c : p)
        p_frecuency[c]++;

    for(int i=0; i<h.size(); i++){
        map<char, ull> current_frecuency;
        for(int j=0; j<p.size() and i+j<h.size(); j++)
            current_frecuency[h[i+j]]++;

        bool is_ans = true;
        for(char c = 'a'; c<='z'; c++)
            if(current_frecuency[c]!=p_frecuency[c])
                is_ans = false;
        if(is_ans){
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";

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

