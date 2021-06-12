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
ull n, m;
string s;

struct Square{
    ull x;
    ull y;
    bool operator <(Square s){
        if(x!=s.x)
            return x < s.x;
        return y<s.y;
    }
};

void solve(){
    ull r, c;
    ull k;
    cin>>r>>c>>k;

    vector<Square> squares;
    for(ull y=1; y<=r; y++)
        for(ull x=1; x<=c; x++){
            char b; cin>>b;
            if(b=='#')
                squares.push_back({x, y});
        }
    sort(all(squares));

    for(auto square : squares){
        cout<<square.x<<" "<<square.y<<"\n";
    }

    ull ans = ((ull)squares.size())*(2*k+1)*(2*k+1);
    ull d = 2*k+1;

    vector<ull> row_min(r+1, LLONG_MAX), row_max(r+1, LLONG_MIN);
    vector<ull> column_min(c+1, LLONG_MAX), column_max(c+1, LLONG_MIN);

    for(int i=1; i<squares.size(); i++){
        row_min[squares[i].y] = min(row_min[squares[i].y], squares[i].x-k);
        row_max[squares[i].y] = max(row_max[squares[i].y], squares[i].x+k);
        column_min[squares[i].x] = min(column_min[squares[i].y], squares[i].x-k);
        column_max[squares[i].x] = max(column_max[squares[i].y], squares[i].x+k);
    }

    for(int i=1; i<squares.size(); i++)
        for(int j=0; j<i; j++){
            if(squares[j].y<=squares[i].y
               and abs(squares[j].y-squares[i].y)<d
               and abs(squares[j].x-squares[i].x)<d){
                cout<<(squares[j].y+d-squares[i].y)*(squares[j].x+d-squares[i].x)<<"$\n";
                ans -= (squares[j].y+d-squares[i].y)*(squares[j].x+d-squares[i].x);
            }
            if(squares[j].y>squares[i].y
               and abs(squares[j].y-(squares[i].y+d))<d
               and abs(squares[j].x-squares[i].x)<d){
                cout<<"?";
                ans -= (squares[i].y+d-squares[j].y)*(squares[j].x+d-squares[i].x);
            }
        }

    cout<<ans<<"\n";
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

