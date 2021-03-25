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
ull n, m, k;
string s;

ull getPenalty(ull repetitions){
    return (k - repetitions%k)%k;
}

void solve(){
    cin>>n>>k;
    cin>>s;

    map<char, ull> timesChar;
    for(char c : s)
        timesChar[c]++;

    if(n%k){
        cout<<"-1\n";
        return;
    }

    ull penalty = 0;
    for(auto c : timesChar){
        penalty += getPenalty(c.second);
    }

    if(!penalty){
        cout<<s<<"\n";
        return;
    }

    for(int i=n-1; i>=0; i--, s.pop_back()){

        penalty -= getPenalty(timesChar[s[i]]);
        timesChar[s[i]]--;
        penalty += getPenalty(timesChar[s[i]]);

        for(char c = s[i] + 1; c<='z'; c++){
            penalty -= getPenalty(timesChar[c]);
            timesChar[c]++;
            penalty += getPenalty(timesChar[c]);

            s[i] = c;
            if( penalty <= (n-i-1) && !((n-i-1-penalty)%k) ){

                s += string(n-i-1-penalty, 'a');

                for(auto c : timesChar){
                    s += string(getPenalty(c.second), c.first);
                }

                cout<<s<<"\n";
                return;

            }

            penalty -= getPenalty(timesChar[c]);
            timesChar[c]--;
            penalty += getPenalty(timesChar[c]);
        }
    }

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

