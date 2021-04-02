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
ull n, m, k;
string s;

vector<pair<int, string>> ans;

void solve(){
    a.clear(); b.clear();
    cin>>n>>m>>k;

    /*if(k > 4*n*m -2*n - 2*m){
        cout<<"NO\n";
        exit(0);
    }

    cout<<"YES\n";*/

    ull d = min(k, m-1); k-=d;
    ans.push_back({d, "R"}); //1 - 1
    if(!k)
        return;

    d = min(k, m-1); k-=d;
    ans.push_back({d, "L"}); //1 - 2
    if(!k)
        return;

    bool toRight = true;
    for(int i=1; i<n; i++, toRight = !toRight){
        ans.push_back({1, "D"}); k--; //499 - 501
        if(!k)
        return;

        d = min(k/3, (m-1));

        if(!d){
            if(toRight)
                ans.push_back({k, "R"});
            else
                ans.push_back({k, "L"});
            k=0;
        }
        else { //499 - 1000
            k -= d*3;
            if(toRight)
                ans.push_back({d, "RUD"});
            else
                ans.push_back({d, "LUD"});
        }

        if(!k)
            return;
    }

    for(int i=n-1; i>0; i--, toRight = !toRight){
        d = min(k, (m-1));
        k -= d;

        if(toRight) //499 -1499
            ans.push_back({d, "R"});
        else
            ans.push_back({d, "L"});

        if(!k)
            return;

        ans.push_back({1, "U"}); k--; //499 - 1998
        if(!k)
        return;
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();

        if(k){
            cout<<"NO\n";
            return 0;
        }
        cout<<"YES\n";
        ull p = 0;

        cout<<ans.size()<<"\n";
        for(auto step : ans) //p += step.first*step.second.size();
            cout<<step.first<<" "<<step.second<<"\n";


        //cout<<p<<"\n";

    }

    return 0;
}

/*
3 3 25

3 3 24

5 5 80

500 500 998000

500 500 997998

*/
