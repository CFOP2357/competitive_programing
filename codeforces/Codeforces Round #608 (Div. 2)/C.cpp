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

vector<ll> a;
vector<ll> b;
ll n, m;
string s;

void solve(){
    ll n, sx, sy;
    cin>>n>>sx>>sy;

    ll up_students = 0;
    ll down_students = 0;
    ll right_students = 0;
    ll left_students = 0;

    while(n--){
        ll x, y; cin>>x>>y;

        if(x > sx)
            right_students++;
        if(x < sx)
            left_students++;

        if(y > sy)
            up_students++;
        if(y < sy)
            down_students++;
    }

    ll max_students = max({right_students, left_students, up_students, down_students});
    cout<<max_students<<"\n";

    if(max_students == right_students)
        cout<<sx+1<<" "<<sy<<"\n";
    else if(max_students == left_students)
        cout<<sx-1<<" "<<sy<<"\n";
    else if(max_students == down_students)
        cout<<sx<<" "<<sy-1<<"\n";
    else if(max_students == up_students)
        cout<<sx<<" "<<sy+1<<"\n";

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

