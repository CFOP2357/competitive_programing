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

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define all(a) a.begin(), a.end()

typedef long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 2100
#define MOD 1000000007


vector<string> number( {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"} );

bool dp[MAX][MAX];
vector<int> cost[MAX];
vector<string> score;
ull n, k;

int calculate_cost(string &s, int d){
    int ans = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0' && number[d][i]=='1'){
            ans++;
        }
        else if(s[i]=='1' && number[d][i]=='0'){
            return -1;
        }
    }
    return ans;
}

void backtraking(int i, int k){
    if(i==0)
        return;
    for(int d = 9; d>=0; d--){
        if(cost[i-1][d]>-1 && dp[i-1][k+cost[i-1][d]]){
            cout<<d;
            backtraking(i-1, k+cost[i-1][d]);
            return;
        }
    }
}

void solve(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        string z; cin>>z;
        score.push_back(z);
    }
    reverse(all(score));

    for(int i=0; i<n; i++){
        for(int d=0; d<=9; d++){
            cost[i].push_back(calculate_cost(score[i], d));
        }
    }

    dp[0][k] = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++){

            if(!dp[i][j])continue;

            for(int d = 0; d<=9; d++){

                int c = cost[i][d];
                if(c==-1 || c>j) continue;

                dp[i+1][j-c] = true;

            }

        }

    }

    if(dp[n][0]){
        backtraking(n, 0);
    }
    else {
        cout<<-1<<"\n";
    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

