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

ull n;

void solve(){

    cin>>n;
    string s; cin>>s;

    for(int i=0; i<=n; i++){
        char charToDelete = '0', posToDelete = -1;

        for(int i=0; i<s.size(); i++){
            if(s[i]>=charToDelete && ( (i>0 && s[i-1]==s[i]-1) || (i<s.size()-1 && s[i+1]==s[i]-1) ) ){
                charToDelete = s[i];
                posToDelete = i;
            }
        }

        if(posToDelete>=0){
                s = s.substr(0, posToDelete) + s.substr(posToDelete+1);
        }
    }

    cout<<n-s.size()<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

