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


    map<int, ull> timesOnArray;
    for(int i=0; i<2*n; i++){
        ull z; cin>>z;
        a.push_back(z);
        timesOnArray[z]++;
    }

    sort(all(a), greater<ull>());

    vector<pii> ans;
    timesOnArray[a[0]]--;

    for(int i=1; i<2*n; i++){
        ans.clear();

        ull init = a[i] + a[0];
        timesOnArray[a[i]]--;

        ans.push_back({a[0], a[i]});
        bool isAns = true;

        ull actualSum = a[0];

        map<int, ull> selected;
        for(int j = 1; j<2*n; j++){
            if(selected[a[j]]>=timesOnArray[a[j]])
                continue;

            selected[a[j]]++;

            ull complement = actualSum - a[j];

            if(timesOnArray[complement] - selected[complement] <= 0 ){
                isAns = false;
                break;
            }

            ans.push_back({a[j], complement});
            actualSum = a[j];

            selected[complement]++;

        }

        if(isAns){
            cout<<"YES\n";
            cout<<init<<"\n";
            for(auto ansElement : ans)
                cout<<ansElement.first<<" "<<ansElement.second<<"\n";
            return;
        }

        timesOnArray[a[i]]++;
    }

    cout<<"NO\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

