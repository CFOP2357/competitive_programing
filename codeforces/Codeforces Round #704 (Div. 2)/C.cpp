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

    int n, m; cin>>n>>m;
    string s, t; cin>>s>>t;

    vector<ull> leftSequence, rightSequence;

    int j = 0;
    for(int i=0; i<n; i++){

        if(s[i]==t[j]){
            leftSequence.push_back(i);
            j++;
        }

        if(j==m)
            break;
    }

    j = m-1;
    for(int i=n-1; i>=0; i--){

        if(s[i]==t[j]){
            rightSequence.push_back(i);
            j--;
        }

        if(j<0)
            break;
    }
    reverse(all(rightSequence));


    ull ans = 0;
    for(int i=0; i<m-1; i++)
        ans = max(ans, rightSequence[i+1]-leftSequence[i]);

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

