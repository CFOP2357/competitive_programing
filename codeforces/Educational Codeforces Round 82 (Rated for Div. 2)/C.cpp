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

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    string s; cin>>s;
    string ans = string(1, s[0]);
    s = s.substr(1);

    map<char, bool> selected;
    selected[ans[0]]=true;

    ull i = 0;
    for(char c : s){

        //cout<<c<<" "<<ans<<"#\n";

        if(i+1 < ans.size() && ans[i+1] == c){
            i++;
        }
        else if(i > 0 && ans[i-1] == c){
            i--;
        }
        else if(!selected[c] && i==0){
            ans = c + ans;
            selected[c] = true;
        }
        else if(!selected[c] && i == ans.size()-1){
            i++;
            ans += c;
            selected[c] = true;
        }
        else {
            cout<<"NO\n";
            return;
        }

    }

    for(char c = 'a'; c<='z'; c++){
        if(!selected[c])
            ans += c;
    }

    cout<<"YES\n";
    cout<<ans<<"\n";

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
1
ababa
*/

