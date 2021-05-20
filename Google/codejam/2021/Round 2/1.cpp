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

#include <time.h>

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

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

int min_query(int i, int j){
    cout<<"M "<<i<<" "<<j<<endl;
    int resp; cin>>resp;
    if(resp<0)
        exit(0);
    return resp;
}

void swap_query(int i, int j){
    cout<<"S "<<i<<" "<<j<<endl;
    int resp; cin>>resp;
    if(resp<0)
        exit(0);
}

void ans_query(){
    cout<<"D "<<endl;
    int resp; cin>>resp;
    if(resp<0)
        exit(0);
}

void solve(){
    for(int i=1; i<n; i++){
        int j = min_query(i, n);
        if(j>i)
            swap_query(i, j);
    }
    ans_query();
}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t>>n;
    while(t--){
        solve();
        T++;
    }

    return 0;
}


