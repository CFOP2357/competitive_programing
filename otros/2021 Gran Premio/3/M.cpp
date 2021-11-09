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

int current_king = 0;
int next_id = 1;

vector<int> next_brother;
vector<int> last_child;
vector<int> first_child;
vector<int> dad;

vector<bool> is_dead;
ll Q;

void update_king(){
    while(is_dead[current_king]){
        int to_visit = -1;

        if(first_child[current_king] != -1){
            to_visit = first_child[current_king];
            first_child[current_king] = -1;
        }
        else if(next_brother[current_king] != -1){
            to_visit = next_brother[current_king];
            next_brother[current_king] = -1;
        }
        else {
            to_visit = dad[current_king];
        }

        assert(to_visit != -1);
        current_king = to_visit;
    }
}

void solve(){
    cin>>Q;

    next_brother.push_back(-1);
    last_child.push_back(-1);
    first_child.push_back(-1);
    dad.push_back(-1);
    is_dead.push_back(false);

    while(Q--){
        int t, x; cin>>t>>x; x--;

        if(t == 1){
            next_brother.push_back(-1);
            last_child.push_back(-1);
            first_child.push_back(-1);
            dad.push_back(x);
            is_dead.push_back(false);

            if(first_child[x] == -1){ //no tiene hijos
                last_child[x] = first_child[x] = next_id;
            }
            else {
                next_brother[last_child[x]] = next_id;
                last_child[x] = next_id;
            }

            next_id++;
        }
        else {
            is_dead[x] = true;
            update_king();
            cout<<current_king+1<<"\n";
        }
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

