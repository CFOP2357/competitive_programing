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
ull n, m, k, q;
ull games;
string s;

vector<ull> dad;

vector<ull> game;
void simulate(int g){
    if(dad[g]==-1)
        return;
    //cout<<g<<"\n";
    ull result = 0;
    if(s[g/2] == '?')
        result = game[g] + game[g+1];
    else
        result = game[g + (s[g/2]-'0')];

    game[2*dad[g] + (g/2)%2] = result;
    simulate(2*dad[g]);
}

void solve(){
    a.clear(); b.clear();
    cin>>k;
    n = pow(2, k);
    games = n-1;
    cin>>s;
    cin>>q;

    game.assign(2*games+1, 1);


    dad.assign(2*games+1, -1);
    //cout<<games<<"#\n";
    for(ull i=0, e = n/2, N = n/2; N; e+=N/2, N/=2)
        for(ull h=0; h<N; h++, i++){
            dad[i*2] = dad[i*2+1] = e + h/2;
        }

    for(ull j = 0; j<n; j+=2)
        simulate(j);
    /*for(auto x : game)
        cout<<x<<" ";
    cout<<"\n";*/


    for(int i=0; i<q; i++){
        ull p; char c; cin>>p>>c;
        s[p-1] = c;
        simulate(2*(p-1));
        cout<<game.back()<<"\n";
    }

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

/*
4
???????????????
2
1 1
1 0

1
?
2
1 0
1 ?

*/

