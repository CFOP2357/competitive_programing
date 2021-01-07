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

    int notMarriedDaughter = 0, kindomNotSelected = 1;
    set <int> selected;

    for(int i=0; i<n; i++){
        int k; cin>>k;
        vector<int> g;

        for(int j=0; j<k; j++){
            int z; cin>>z;
            g.push_back(z);
        }

        bool hasSelected = false;
        for(int gi : g){
            if(selected.find(gi) == selected.end()){
                selected.insert(gi);
                hasSelected = true;
                break;
            }
        }

        if(!hasSelected)
            notMarriedDaughter = i+1;

    }

    while(selected.find(kindomNotSelected) != selected.end())
            kindomNotSelected++;

    if(notMarriedDaughter){
        cout<<"IMPROVE\n";
        cout<<notMarriedDaughter<<" "<<kindomNotSelected<<"\n";
    }
    else cout<<"OPTIMAL\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

