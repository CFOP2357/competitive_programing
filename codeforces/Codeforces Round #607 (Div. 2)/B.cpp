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
    string s, c;
    cin>>s;
    cin>>c;

    for(int i = 0; i < s.size() and i < c.size(); i++){
        for(int j = i; j < s.size(); j++)
                if(s[j] < c[i]){
                    swap(s[i], s[j]);
                    cout<<s<<"\n";
                    return;
                }

        if(c[i] < s[i])
            break;
    }

    for(int i = 0; i < s.size() and i < c.size(); i++){
        if(c[i] < s[i]){
            for(int j = s.size()-1; j >= i; j--)
                    if(s[j] == c[i]){
                        swap(s[i], s[j]);
                        if(s < c)
                            cout<<s<<"\n";
                        else
                            cout<<"---\n";
                        return;
                    }
        }
    }

    if(s < c)
        cout<<s<<"\n";
    else
        cout<<"---\n";

}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

