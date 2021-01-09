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

vector<pii> rook;
vector<set<ull>> cell;
vector<set<ull>> selected(5);
ull n, m;

void solve(){

    rook.clear();

    cin>>n>>m;
    cell.assign(n+1, set<ull>());
    selected.assign(5, set<ull>());
    for(int i=0; i<m; i++){
        ull x, y; cin>>x>>y;

        rook.push_back({x, y});

        cell[x].insert(i);
        cell[y].insert(i);
    }

    ull ans = 0, assigned = 0;
    for(int i=1; i<=n; i++){

        if(cell[i].size()==1 && rook[*cell[i].begin()].first == rook[*cell[i].begin()].second){
                assigned++;
                continue;
        }

        selected[cell[i].size()].insert(i);
    }



    while(assigned<m){
        ans++;
        assigned++;


        if(selected[1].size()){
            int c = *selected[1].begin(); selected[1].erase(c);

            //cout<<c<<"#\n";

            int r = *cell[c].begin();
            if(rook[r].first != c){
                selected[cell[rook[r].first].size()].erase(rook[r].first);
                cell[rook[r].first].erase(r);
                selected[cell[rook[r].first].size()].insert(rook[r].first);
            }
            if(rook[r].second != c){
                selected[cell[rook[r].second].size()].erase(rook[r].second);
                cell[rook[r].second].erase(r);
                selected[cell[rook[r].second].size()].insert(rook[r].second);
            }

        }
        else {
            int c = *selected[2].begin(); selected[2].erase(c);

            int r = *cell[c].begin();

            selected[cell[rook[r].first].size()].erase(rook[r].first);
            cell[rook[r].first].erase(r);
            selected[cell[rook[r].first].size()].insert(rook[r].first);

            selected[cell[rook[r].second].size()].erase(rook[r].second);
            cell[rook[r].second].erase(r);
            selected[cell[rook[r].second].size()].insert(rook[r].second);

            ans++;
        }

    }

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

