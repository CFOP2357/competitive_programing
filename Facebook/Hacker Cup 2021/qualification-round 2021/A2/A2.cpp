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

ll n, m, k;
string s;

ll cost[200][200];
unordered_map<char, vector<char>> adj;

void update_cost_from(const char initial_letter){
    unordered_map<char, bool> visited;

    queue<pair<char, int>> nxt; //letter, cost
    nxt.push({initial_letter, 0});

    while(nxt.size()){
        auto [letter, cost] = nxt.front();
        nxt.pop();

        if(visited[letter])
            continue;
        visited[letter] = true;

        ::cost[initial_letter][letter] = cost;

        for(auto nb : adj[letter])
            nxt.push({nb, cost+1});
    }
}

void solve(){
    adj.clear();

    fin>>s;
    fin>>k;

    while(k--){
        string edge;
        fin>>edge;

        adj[edge[0]].push_back(edge[1]);
    }

    for(char letter = 'A'; letter <= 'Z'; letter++){
        fill(all(cost[letter]), LLONG_MAX);
        update_cost_from(letter);
    }

    ll ans = LLONG_MAX;
    for(char goal = 'A'; goal <= 'Z'; goal++){
        ll current_ans = 0;

        for(char letter : s){
            if(cost[letter][goal] == LLONG_MAX){
                current_ans = -1;
                break;
            }

            current_ans += cost[letter][goal];
        }

        if(current_ans >= 0)
            ans = min(current_ans, ans);
    }

    if(ans < LLONG_MAX)
        fout<<ans<<"\n";
    else
        fout<<"-1\n";

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

