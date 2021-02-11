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
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    vector<ull> maxFromLeft;
    vector<ull> maxFromRight;
    stack<pii> currentState; //floor, size

    {

    ull currentAns = 0;
    for(int i=0; i<n; i++){

        ull sz = 1;
        while(currentState.size() && currentState.top().first >= a[i]){
            sz += currentState.top().second;
            currentAns -= currentState.top().first*currentState.top().second;
            currentState.pop();
        }

        currentAns += sz * a[i];
        currentState.push({a[i], sz});

        maxFromLeft.push_back(currentAns);

    }
    while(currentState.size()) currentState.pop();

    for(int i=n-1; i>=0; i--){

        ull sz = 1;
        while(currentState.size() && currentState.top().first >= a[i]){
            sz += currentState.top().second;
            currentAns -= currentState.top().first*currentState.top().second;
            currentState.pop();
        }

        currentAns += sz * a[i];
        currentState.push({a[i], sz});

        maxFromRight.push_back(currentAns);

    }
    while(currentState.size()) currentState.pop();
    reverse(all(maxFromRight));

    }

    int i;
    ull ans = 0;
    for(int j=0; j<n; j++){
        if(ans < (maxFromLeft[j]+maxFromRight[j]-a[j])){
            ans = (maxFromLeft[j]+maxFromRight[j]-a[j]);
            i = j;
        }
    }

    ull ans2 = 0;
    ull last = a[i];
    vector<ull> currentAns;

    for(int j=i; j>=0; j--){
        last = min(last, a[j]);
        if(j<=i){
            ans2 += last;
        }
        else{
            ans2 += min(a[j], last);
        }
        currentAns.push_back(last);
    }

    reverse(all(currentAns));

    last = a[i];
    for(int j=i+1; j<n; j++){
        last = min(last, a[j]);
        if(j<=i){
            ans2 += last;
        }
        else{
            ans2 += min(a[j], last);
        }
        currentAns.push_back(last);
    }


    for(ull k : currentAns)
        cout<<k<<" ";

    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

