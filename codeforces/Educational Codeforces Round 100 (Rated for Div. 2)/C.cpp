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

vector<ull> t;
vector<ull> x;
ull n;

void solve(){
    t.clear(); x.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull ti, xi; cin>>ti>>xi;
        t.push_back(ti);
        x.push_back(xi);
    }

    ull last_time = 0;
    ull finish_time = 0;
    ull lastPosition = 0;
    ull position = 0;
    ull ans = 0;
    for(int i=0; i<n; i++){


        if(finish_time>t[i]){

            ull timeToArrive = abs(x[i]-lastPosition) + last_time;

            if(timeToArrive>=t[i] && (i==n-1 || timeToArrive<=t[i+1])){
                if(position >= lastPosition && x[i]>=lastPosition && x[i]<=position)
                    ans++;
                else if(position < lastPosition && x[i]<=lastPosition && x[i]>=position)
                    ans++;
            }

        }
        else {

            last_time = t[i];
            finish_time = t[i] + abs(position-x[i]);
            lastPosition = position;
            position = x[i];

            if(finish_time>=t[i] && (i==n-1 || finish_time<=t[i+1]))
                ans++;
        }
    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
1
3
1 5
3 0
6 4
*/

