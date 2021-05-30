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
ull n, m, p;
vector<string> s;
string ans;
vector<int> toCheck;

void BB(int i, string current){

    ull p = 0;
    for(int j = 0; j<m; j++){
        if(current[j] == '1'){
            if(z[k] == '1')
        }
    }

    if(i==toCheck.size()){
        if(count(all(current), '1')>count(all(ans), '1'))
            ans = current;
        return;
    }

    current[toCheck[i]] = '1';
    BB(i+1, current);
    current[toCheck[i]] = '0';
    BB(i+1, current);

}

void solve(){
    a.clear(); b.clear();
    cin>>n>>m>>p;
    vector<ull> f(m, 0);
    for(int i=0; i<n; i++){
        string z; cin>>z;
        s.push_back(z);
        for(int j=0; j<m; j++)
            if(z[j]=='1')
                f[j]++;
    }


    for(int j=0; j<m; j++)
        if(f[j]>=(n+1)/2){
            toCheck.push_back(j);
        }

    ans = string(m, '0');
    string current = string(m, '0');
    BB(0, current);

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

