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
typedef int ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000010
#define MOD 1000000007

///////////////////////////////////////////////

typedef uint64_t ull;
static ll C; // initialized below

// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<ll M, class B>
struct A {
	int x; B b; A(ll x=0) : x(x), b(x) {}
	A(int x, B b) : x(x), b(b) {}
	A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() { return x ^ (ull) b << 21; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

H hashString(const vector<ll>& s){H h{}; for(ll c:s) h=h*C+c;return h;}

#include <sys/time.h>
///////////////////////////////////////////////

class MyHashFunction {
public:

    // Use sum of lengths of first and last names
    // as hash function.
    size_t operator()(const vector<ll> &p) const
    {
        return hashString(p).x;
    }
};

struct ToProcess{
    ll value;
    vector<int> build_positions;

    bool operator <(const ToProcess &to_compare) const{
        return value < to_compare.value;
    }
};

ll n, m;
vector<vector<ll>> a;
unordered_map<vector<ll>, bool, MyHashFunction> build_banned;
unordered_map<vector<ll>, bool, MyHashFunction> visited;

ll get_build_value(const vector<int> &build_positions){
    ll value = 0;
    for(int i = 0; i < n; i++)
        value += a[i][build_positions[i]];
    return value;
}

vector<ll> get_build(const vector<int> &build_positions){
    vector<ll> build;
    for(int i = 0; i < n; i++)
        build.push_back(a[i][build_positions[i]]);
    return build;
}


void solve(){
    cin>>n;
    for(int i = 0; i < n; i++){
        int c; cin>>c;
        a.push_back(vector<ll>());
        while(c--){
            ll p; cin>>p;
            a.back().push_back(p);
        }
    }

    cin>>m;
    for(int i = 0; i < m; i++){
        vector<ll> build;
        for(int i = 0; i < n; i++){
            ll z; cin>>z;
            build.push_back(z-1);
        }

        build_banned[build] = true;
    }

    vector<int> first_build;
    for(int i = 0; i < n; i++)
        first_build.push_back(a[i].size() - 1);

    priority_queue<ToProcess> nxt;
    nxt.push({get_build_value(first_build), first_build});

    while(nxt.size()){
        auto build_positions = nxt.top().build_positions;
        nxt.pop();

        if(not build_banned[build_positions]){

            for(auto c : build_positions)
                cout<<c+1<<" ";
            cout<<"\n";

            return;
        }

        //if(nxt.size() <= MAX)
            for(int i = 0; i < n; i++){
                if(build_positions[i] == 0)
                    continue;

                auto new_build_positions = build_positions;
                new_build_positions[i]--;

                if(not visited[new_build_positions]){
                    nxt.push({get_build_value(new_build_positions), new_build_positions});
                    visited[new_build_positions] = true;
                }
            }
    }

    assert(false);
}


int main(){
    timeval tp;
	gettimeofday(&tp, 0);
	C = (int)tp.tv_usec; // (less than modulo)

    //cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

