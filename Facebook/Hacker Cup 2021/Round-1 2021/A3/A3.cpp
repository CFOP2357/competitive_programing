//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

#include <map>
#include <set>

#include <stack>
#include <queue>

#include <unordered_map>
#include <unordered_set>

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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ofstream fout ("out.txt");
ifstream fin ("in.txt");


#define MAX 1000100
#define MOD 1000000007

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

const ll mod = MOD; // change to something else
struct Mod {
	ll x;
	Mod(ll xx) : x(xx) {}
	Mod() : x(0) {}
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
	Mod operator/(Mod b) { return *this * invert(b); }
	Mod invert(Mod a) {
		ll x, y, g = euclid(a.x, mod, x, y);
		return Mod((x + mod) % mod);
	}
	Mod operator^(ll e) {
		if (!e) return Mod(1);
		Mod r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};

vector<ll> a;
vector<ll> b;
ll n, m, k;
string s;

void solve(){
    a.clear(); b.clear(); n = 0;
    fin>>k;
    fin>>s;

    Mod ans;

    int first_O = 0;
    int first_X = 0;

    int last_O_idx = 0;
    int last_X_idx = 0;
    Mod sum_X(0);
    Mod sum_O(0);

    ll idx = 1;
    char current_hand = 'O';
    for(auto letter : s){
        if(letter != 'F' and letter != '.')
            current_hand = letter;

        if(letter == '.'){
            ans = ans + ans;

            if(first_X and (first_X < first_O or not first_O)){
                last_X_idx = first_X + last_O_idx;
                sum_X = Mod(last_O_idx) + sum_O;
                ans = ans + sum_X;

                ans = ans + (Mod(last_X_idx) + sum_X);
            }
            else if(first_O){

            }
        }
        else if(current_hand == 'O'){
            idx++;
            ans = ans + (Mod(last_X_idx) + sum_X);

            if(letter != 'F'){
                last_O_idx = idx;
                sum_O = (Mod(last_X_idx) + sum_X);

                if(not first_O)
                    first_O = idx;
            }
        }
        else {
            idx++;
            ans = ans + (Mod(last_O_idx) + sum_O);

            if(letter != 'F'){
                last_X_idx = idx;
                sum_X = (Mod(last_O_idx) + sum_O);

                if(not first_X)
                    first_X = idx;
            }
        }
    }

    fout<<ans.x<<"\n";
}


int main(){
    //srand (time(NULL));

    ull T = 1;
    int t=1; fin>>t;
    while(t--){
        fout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}

