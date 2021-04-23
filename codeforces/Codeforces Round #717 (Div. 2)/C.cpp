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

typedef int ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n;

    priority_queue<pii> nxt;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        nxt.push({z, i+1});
    }


    vector<int> ans;
    unordered_map<int, bool> selected; selected[0]=true;
    while(nxt.size()){
        int k = nxt.top().first; int i = nxt.top().second;
        nxt.pop();

        bool possible = true;
        unordered_map<int, bool> currentSelected;
        for(auto p : selected){
            int x = p.first + k;
            if(selected[x] || currentSelected[x]){
                cout<<k<<" "<<x<<"\n";
                possible=false;
                break;
            }
            currentSelected[x] = true;
        }

        if(possible){
            for(auto p : currentSelected)
                if(p.second)
                    selected[p.first] = true;
        }
        else ans.push_back(i);
    }

    sort(all(ans));
    cout<<ans.size()<<"\n";
    for(int k : ans)
        cout<<k<<" ";
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

/*
6
1 2 7 9 10 12
*/
