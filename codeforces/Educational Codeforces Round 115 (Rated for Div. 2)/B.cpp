//#include <bits/stdc++.h>
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

#include <assert.h>

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
typedef int64_t ll;
typedef uint64_t ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
#define MOD 1000000007

ll n;
vector<vector<bool>> has_day;

bool is_possible(int day1, int day2){
    int on_day1(0), on_day2(0), on_both(0);

    for(int student = 0; student < n; student++){
        if(has_day[student][day1] and has_day[student][day2])
            on_both++;
        else if(has_day[student][day1])
            on_day1++;
        else if(has_day[student][day2])
            on_day2++;
        else
            return false;
    }

    return (on_day1 <= n/2 and on_day2 <= n/2
            and on_day1+on_day2+on_both == n);
}

void solve(){
    has_day.clear();

    cin>>n;
    for(int i = 0; i < n; i++){
        vector<bool> current_has_day(5);
        for(int d = 0; d < 5; d++){
            bool a; cin>>a;

            current_has_day[d] = (bool)a;
        }

        has_day.push_back(current_has_day);
    }

    for(int day1 = 0; day1 < 5; day1++)
        for(int day2 = day1+1; day2 < 5; day2++){
            if(is_possible(day1, day2)){
                cout<<"YES\n";
                return;
            }
        }

    cout<<"NO\n";
}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

