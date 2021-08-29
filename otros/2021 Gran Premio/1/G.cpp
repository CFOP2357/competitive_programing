//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>

#include <map>
#include <set>

#include <stack>
#include <queue>

#include <unordered_map>
#include <unordered_set>

#include <cmath>
#include <climits>
#include <ctime>
#include <cassert>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

const int MAX = 1000100; //10^6
const int MOD = 1000000007;

/////////////////importado de KACTL/////////////////
// Fuente: https://github.com/kth-competitive-programming/kactl
// Pegar aqui cosas de katl necesarias



///////////////////////////////////////////////////

vector<ll> a;
vector<ll> b;
ll n, m, k, q;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n>>m;
    ll bits_sz = 0;

    ll k = n;
    while(k){
        if(k%2)
            bits_sz++;
        k/=2;
    }

    if(bits_sz%2){
        cout<<"Free snacks!\n";
    }
    else {
        if(n%2 == 0)
            cout<<"Free snacks!\n";
        else{
            ll bits_sz = 0;

            ll k = n;
            while(k){
                if(k%2)
                    bits_sz++;
                else break;
                k/=2;
            }

            if(k%2 == 0)
                cout<<"Free snacks!\n";
            else{
                if(m > 1 and n>1)
                    cout<<"Free snacks!\n";
                else if(n-m <= 0)
                    cout<<"Free snacks!\n";
                else
                    cout<<"Pay the bill\n";
            }
        }
    }
}


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    // revisa que el input tenga sentido,
    // si no arroja el error cin.failbit
    cin.exceptions(cin.failbit);

    //srand (time(nullptr));

    int t=1; //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
