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
string s;

struct Block{
    string type;
    ull sz;
    ull definer;
    bool operator <(Block b){
        if(b.definer != definer)
            return definer < b.definer;
        if(type=="cube")
            return false;
        return true;
    }
};

void solve(){
    vector<Block> blocks;
    cin>>n;
    for(int i=0; i<n; i++){
        string s; ull sz;
        cin>>s>>sz;
        ull definer;
        if(s=="cube")
            definer=sz;
        else
            definer=sz*2;
        blocks.push_back({s, sz, definer});
    }
    sort(all(blocks));

    for(int i=1; i<n; i++){
        if(blocks[i].type == "cylinder" && blocks[i-1].type == "cube" ){
            ull d = blocks[i].definer;
            ull a = blocks[i-1].definer;

            if(d*d < 2*(a*a)){
                cout<<"impossible\n";
                return;
            }
        }
    }

    for(auto block : blocks){
        cout<<block.type<<" "<<block.sz<<"\n";
    }

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

