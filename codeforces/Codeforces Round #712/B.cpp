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

ull n, m;
string s, a, b;

void invertSegment(int i, int j){
    for(;i<=j && i<n; i++){
        if(a[i]=='1')
            a[i]='0';
        else
            a[i]='1';
    }
}

bool equalSegment(int i, int j){
    for(;i<=j && i<n; i++)
        if(a[i]!=b[i])
            return false;
    return true;
}

void solve(){
    cin>>n;
    cin>>a>>b;

    vector<int> nextChange;
    int zero = 0, one=0;

    for(int i=0; i<n; i++){
        if(a[i]=='0')
            zero++;
        else
            one++;

        if(zero==one)
            nextChange.push_back(i);
    }

    int i=0;
    for(int j : nextChange){

        if(equalSegment(i, j)){
            i=j+1;
            continue;
        }

        invertSegment(i, j);

        if(equalSegment(i, j)){
            i=j+1;
            continue;
        }

        cout<<"NO\n";
        return;
    }

    if(i<n && !equalSegment(i, n-1)){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";

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

