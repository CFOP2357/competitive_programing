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

#define MAX 100
#define MOD 1000000007

vector<ll> a;
vector<ll> b;
ll n, m;
string s;

char grid[MAX][MAX];

int column_cost(int column){
    int cost = 0;
    for(int row = 0; row < n; row++)
        if(grid[row][column] == '.')
            cost++;
    return cost;
}

int row_cost(int row){
    int cost = 0;
    for(int column = 0; column < n; column++)
        if(grid[row][column] == '.')
            cost++;
    return cost;
}

bool row_solvable(int row){
    for(int column = 0; column < n; column++)
        if(grid[row][column] == 'O')
            return false;
    return true;
}

bool column_solvable(int column){
    for(int row = 0; row < n; row++)
        if(grid[row][column] == 'O')
            return false;
    if(column_cost(column) == 1){
        for(int row = 0; row < n; row++)
            if(grid[row][column] == '.'){
                if(row_cost(row) == 1 and row_solvable(row))
                    return false;
            }
    }
    return true;
}



void solve(){
    a.clear(); b.clear();
    fin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            fin>>grid[i][j];
    }

    map<int, int> ans;
    for(int i = 0; i < n; i++){
        if(column_solvable(i))
            ans[column_cost(i)]++;
        if(row_solvable(i))
            ans[row_cost(i)]++;
    }

    if(ans.empty())
        fout<<"Impossible\n";
    else{
        auto [additional, sets] = *ans.begin();
        fout<<additional<<" "<<sets<<"\n";
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

