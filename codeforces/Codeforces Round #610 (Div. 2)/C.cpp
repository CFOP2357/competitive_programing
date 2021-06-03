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
ull n, m, T, easy_cost, hard_cost;
string s;

void solve(){
    a.clear();
    cin>>n>>T>>easy_cost>>hard_cost;

    ull hard_problems = 0, easy_problems = 0;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        if(z)
            hard_problems++;
        else
            easy_problems++;
    }

    map<ull, ull> easy; //time, frecuency
    map<ull, ull> hard;
    set<ull> times;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        times.insert(z);
        if(a[i])
            hard[z]++;
        else
            easy[z]++;
    }

    ull ans = 0;
    ull time_needed = 0;
    ull problems_solved = 0;

    bool more_time = true;
    for(auto time : times){
        ull d = time-1-time_needed;
        if(d>=0){
            ull p = problems_solved;
            ull current_easy = min(easy_problems, d/easy_cost);
            d -= current_easy*easy_cost;
            ull current_hard = min(hard_problems, d/hard_cost);
            p += current_easy + current_hard;
            ans = max(ans, p);
        }


        problems_solved += easy[time] + hard[time];
        time_needed += easy[time]*easy_cost + hard[time]*hard_cost;
        d = time-time_needed;
        easy_problems -= easy[time];
        hard_problems -= hard[time];
        if(d>=0){
            ull p = problems_solved;
            ull current_easy = min(easy_problems, d/easy_cost);
            d -= current_easy*easy_cost;
            ull current_hard = min(hard_problems, d/hard_cost);
            p += current_easy + current_hard;
            ans = max(ans, p);
        }

        if(time == T)
            more_time = false;
    }

    if(more_time){
        ull d = T-time_needed;
        if(d>=0){
            ull p = problems_solved;
            ull current_easy = min(easy_problems, d/easy_cost);
            d -= current_easy*easy_cost;
            ull current_hard = min(hard_problems, d/hard_cost);
            p += current_easy + current_hard;
            ans = max(ans, p);
        }
    }

    cout<<ans<<"\n";

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

