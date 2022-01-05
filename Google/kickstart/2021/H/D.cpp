//#include <bits/stdc++.h>
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

#include <assert.h>

//#include <time.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef int64_t ll;
typedef uint64_t ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
#define MOD 1000000007

char cube[5][5][5][5][5];
char value;

bool line_is_win(const vector<int> &first_coord, const vector<int> &direction){
    char last = value;
    if(last == 0)
        return false;

    bool is_moving = false;
    vector<int> current_coord = first_coord;
    for(int d = 0; d < direction.size(); d++){
        if(direction[d] != 0)
            is_moving = true;
        if(direction[d] < 0)
            current_coord[d] = 4;
        if(direction[d] > 0)
            current_coord[d] = 0;
    }

    if(not is_moving)
        return false;

    for(int i = 1; i <= 5; i++){
        char current_value = cube[current_coord[0]][current_coord[1]][current_coord[2]][current_coord[3]][current_coord[4]];
        if(current_value != last)
            return false;

        for(int d = 0; d < direction.size(); d++)
            current_coord[d] += direction[d];
    }

    return true;
}

bool is_win(const vector<int> &first_coord, vector<int> &direction, int dimension = 0){
    if(dimension >= 5)
        return line_is_win(first_coord, direction);

    direction[dimension] = -1;
    if(is_win(first_coord, direction, dimension+1))
        return true;

    direction[dimension] = 1;
    if(is_win(first_coord, direction, dimension+1))
        return true;

    direction[dimension] = 0;
    if(is_win(first_coord, direction, dimension+1))
        return true;

    return false;
}

char ans1 = 0;
int ans2 = 0;
void solve(){
    int n;
    cin>>n;
    vector<int> coord(5);
    vector<int> direction(5, 0);


    for(int t = 1; t <= n; t++){
        for(int d = 0; d < 5; d++)
            cin>>coord[d];
        cin>>value;

        cube[coord[0]][coord[1]][coord[2]][coord[3]][coord[4]] = value;

        if(is_win(coord, direction) and not ans1){
            ans1 = value, ans2 = t;
        }
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
        if(ans1)
            cout<<ans1<<" "<<ans2<<"\n";
        else
            cout<<"DRAW\n";
    }

    return 0;
}

