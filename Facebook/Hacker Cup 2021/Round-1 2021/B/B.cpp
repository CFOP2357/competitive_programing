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
typedef int ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ofstream fout ("out.txt");
ifstream fin ("in.txt");


#define MAX 1000100
#define MOD 1000000007

ll n, m, a, b;
string s;

void solve(){
    fin>>n>>m>>a>>b;

    vector<vector<ll>> grid(n, vector<ll>(m, 1));
    a -= (n + m - 1);
    b -= (n + m - 1);

    if(a < 0 or b < 0){
        fout<<"Impossible\n";
        return;
    }

    grid[0][0] += a;
    grid[0].back() += b;


    fout<<"Possible\n";

    for(int row = 0; row < n; row++){
        for(int column = 0; column < m-1; column++){
                fout<<grid[row][column]<<" ";
        }
        fout<<grid[row][m-1]<<"\n";
    }

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

