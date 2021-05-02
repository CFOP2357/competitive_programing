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
string S, E;
unordered_map<string, ull> min_dist;

string notOperator(string s){
    for(char &c : s)
        if(c=='1')
            c='0';
        else
            c = '1';

    int last = 0;
    for(int i=0; i<s.size()-1 && s[i]=='0'; i++) last = i;

    if(s[last]=='0')
        s = s.substr(last+1);
    if(!s.size())
        s="0";
    return s;
}

void find_(){
    min_dist.clear();
    queue<pair<string, ull>> bfs;
    bfs.push({S, 0});

    while(bfs.size()){
        string s = bfs.front().first;
        ull d = bfs.front().second;
        bfs.pop();
        if(min_dist.find(s)!=min_dist.end())
            continue;
        min_dist[s] = d;

        bfs.push({notOperator(s), d+1});
        if(s.size()<19 && s[0]!='0')
            bfs.push({s+"0", d+1});
    }
}

void solve(){
    cin>>S>>E;
    if(S.size()>8 || E.size()>8)
        exit(-1);
    find_();
    if(min_dist.find(E)==min_dist.end())
        cout<<"IMPOSSIBLE\n";
    else
        cout<<min_dist[E]<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}


