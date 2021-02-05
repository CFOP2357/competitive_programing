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
ull x, y;

void solve(){

    ull realX(0), realY(0);
    ull r(0), l(0), u(0), d(0);

    cin>>x>>y;
    string s; cin>>s;

    for(char c : s){
        switch(c){
            case 'R':
                r++;
                realX++;
            break;
            case 'L':
                l++;
                realX--;
            break;
            case 'U':
                u++;
                realY++;
            break;
            case 'D':
                d++;
                realY--;
            break;
        }
    }

    if(realX > x && r < abs(realX-x)){
        cout<<"NO\n";
        return;
    }
    if(realX < x && l < abs(realX-x)){
        cout<<"NO\n";
        return;
    }

    if(realY > y && u < abs(realY-y)){
        cout<<"NO\n";
        return;
    }
    if(realY < y && d < abs(realY-y)){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

