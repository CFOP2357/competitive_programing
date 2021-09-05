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

vector<ll> a;
vector<ll> b;
ll n, m;
string s;

bool is_consonant(char letter){
    return (letter == 'A' or letter == 'E' or letter == 'I'
            or letter == 'O' or letter == 'U');
}

void solve(){
    a.clear(); b.clear();
    fin>>s;

    ll ans = LLONG_MAX;
    for(char goal = 'A'; goal <= 'Z'; goal++){
        ll current_ans = 0;

        for(char letter : s){
            if(letter == goal)
                continue;

            if(is_consonant(letter) == is_consonant(goal))
                current_ans += 2;
            else
                current_ans++;

        }

        ans = min(current_ans, ans);
    }

    fout<<ans<<"\n";

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

