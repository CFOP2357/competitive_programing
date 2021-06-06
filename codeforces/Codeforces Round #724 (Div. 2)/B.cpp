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

unordered_set<string> is_on;

bool find_ans(string &current, int i=0){
    if(i==current.size()){
        if(is_on.find(current)==is_on.end()){
            cout<<current<<"\n";
            return true;
        }
        return false;
    }
    for(char c = 'a'; c<='z'; c++){
        current[i]=c;
        if(find_ans(current, i+1))
            return true;
    }
    return false;
}

void solve(){
    a.clear(); b.clear();
    cin>>n;
    cin>>s;

    is_on.clear();

    for(int i = 0; i<n; i++)
        is_on.insert(string{s[i]});

    for(int i = 1; i<n; i++)
        is_on.insert(string{s[i-1], s[i]});

    for(int i = 2; i<n; i++)
        is_on.insert(string{s[i-2], s[i-1], s[i]});

    for(char ans = 'a'; ans<='z'; ans++)
        if(is_on.find(string{ans})==is_on.end()){
            cout<<ans<<"\n";
            return;
        }

    string current = "aa";
    if(find_ans(current))
        return;
    current="aaa";
    find_ans(current);


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

