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


#define MAX 1000100
#define MOD 1000000007

vector<ll> a;
vector<ll> b;
ll n, m, k;
string s;



ll or_query(int i, int j){
    i++,j++;
    cout<<"or "<<i<<" "<<j<<endl;
    ll x; cin>>x;
    return x;
}

ll and_query(int i, int j){
    i++,j++;
    cout<<"and "<<i<<" "<<j<<endl;
    ll x; cin>>x;
    return x;
}

void solve(){
    cin>>n>>k;
    a.assign(n, 0);

    vector<ll> and_{and_query(0, 1), and_query(1, 2), and_query(0, 2)};
    vector<ll> or_{or_query(0, 1), or_query(1, 2), or_query(0, 2)};

    ll OR = (or_[0] | (or_[1] | or_[2]));
    ll p = 1;
    while(p <= OR){
        if( (and_[0]&p)){
            a[0] |= p;
            a[1] |= p;
        }
        if( (and_[1]&p)){
            a[1] |= p;
            a[2] |= p;
        }

        if( !(and_[0]&p) and  (or_[0]&p)){
            if((and_[1]&p)){}
            else if(!(and_[1]&p)){
                a[0] |= p;
            }
            else { //0 1 0 1
                if((and_[2]&p)){
                    a[0] |= p;
                    a[2] |= p;
                }
                else
                    a[1] |= p;
            }
        }

         if( !(and_[1]&p) and  (or_[1]&p)){
            if((and_[0]&p)){}
            else if(!(and_[0]&p)){
                a[2] |= p;
            }
            else { //0 1 0 1
                if((and_[2]&p)){
                    a[0] |= p;
                    a[2] |= p;
                }
                else
                    a[1] |= p;
            }
        }

        p *= 2;
    }

    for(int i = 3; i < n; i++){
        ll or_ = or_query(0, i);
        ll and_ = and_query(0, i);

        ll p = 1;
        while(p <= or_){
            if((and_&p))
                a[i] |= p;
            else if((or_&p) and !(a[0]&p)){
                a[i] |= p;
            }
            p *= 2;
        }
    }

    sort(all(a));
    cout<<"finish "<<a[k-1]<<endl;
}


int main(){

    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

