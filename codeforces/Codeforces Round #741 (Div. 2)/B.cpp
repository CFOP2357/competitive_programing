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

ll n, m, k;
string s;

vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
vector<bool> is_prime;

void solve(){
    cin>>k;
    cin>>s;

    for(int i = 1; i <= 1000; i++){
        if(is_prime[i])
            continue;

        string goal = to_string(i);
        int current_goal = 0;
        for(int j = 0; j < k and current_goal < goal.size(); j++)
            if(s[j] == goal[current_goal])
                current_goal++;

        if(current_goal >= goal.size()){
            cout<<goal.size()<<"\n";
            cout<<goal<<"\n";
            return;
        }
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    is_prime.assign(101, false);
    for(auto prime : primes)
        is_prime[prime] = true;

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

