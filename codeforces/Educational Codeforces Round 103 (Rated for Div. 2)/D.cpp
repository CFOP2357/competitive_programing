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
    a.clear(); b.clear();
    cin>>n;
    string s; cin>>s;

    vector<ull> fromLeftbyRight;
    vector<ull> fromLeftbyLeft;

    bool inverted = false;
    for(char c : s){
        if(inverted)
            c = c=='R'?'L':'R';

        if(c == 'L'){
            fromLeftbyRight.push_back(0);
            fromLeftbyLeft.push_back(1);
        }
        else {
            fromLeftbyRight.push_back(1);
            fromLeftbyLeft.push_back(0);
        }


        inverted = !inverted;
    }
    fromLeftbyLeft.push_back(0);
    fromLeftbyRight.push_back(0);

    ull last = n;
    for(int i = n; i>=0; i--){
        if(!fromLeftbyRight[i]){
            last = i;
        }
        fromLeftbyRight[i]=last;
    }

    last = n;
    for(int i = n; i>=0; i--){
        if(!fromLeftbyLeft[i]){
            last = i;
        }
        fromLeftbyLeft[i]=last;
    }

    vector<ull> ans(n+1, 0);

    inverted = false;
    for(int i=0; i<=n; i++){
        if(inverted){
            ans[i] += fromLeftbyLeft[i]-i;
        }
        else {
            ans[i] += fromLeftbyRight[i]-i;
        }

        inverted=!inverted;
    }

    vector<ull> fromRightbyRight;
    vector<ull> fromRightbyLeft;

    inverted = false;
    for(int i = n-1; i>=0; i--){
        char c = s[i];

        if(inverted)
            c = (c=='R')?'L':'R';

        if(c == 'R'){
            fromRightbyRight.push_back(1);
            fromRightbyLeft.push_back(0);
        }
        else {
            fromRightbyRight.push_back(0);
            fromRightbyLeft.push_back(1);
        }


        inverted = !inverted;
    }

    fromRightbyLeft.push_back(0);
    fromRightbyRight.push_back(0);

    last = n;
    for(int i = n; i>=0; i--){
        if(!fromRightbyRight[i]){
            last = i;
        }
        fromRightbyRight[i]=last;
    }

    last = n;
    for(int i = n; i>=0; i--){
        if(!fromRightbyLeft[i]){
            last = i;
        }
        fromRightbyLeft[i]=last;
    }


    inverted = false;
    for(int i=0; i<=n; i++){
        if(!inverted){
            ans[n-i] += fromRightbyLeft[i]-i;
        }
        else {
            ans[n-i] += fromRightbyRight[i]-i;
        }
        inverted=!inverted;
    }

    for(ull k : ans)
        cout<<k+1<<" ";
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

