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

typedef unsigned long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 30000000000000000
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

ull cost(pii a, pii b){
    return max(a.first, b.first)-min(a.first, b.first) + max(a.second, b.second)-min(a.second, b.second);
}

void solve(){
    ull x0, y0, ax, ay, bx, by;
    cin>>x0>>y0>>ax>>ay>>bx>>by;

    ull xs, ys, t; cin>>xs>>ys>>t;

    ull ans = 0;

    vector<pii> points;

    ull x=x0, y=y0;
    while(x<=MAX && y<=MAX){
        points.push_back({x, y});
        x = ax*x + bx;
        y = ay*y + by;
    }
    points.push_back({x, y});

    pii toFind = {xs, ys};
    int current = lower_bound(all(points), toFind) - points.begin();

    /*cout<<current<<"\n";
    cout<<points[current-1].first<<" "<<points[current-1].second<<" "<<cost(points[current-1], {xs, ys})<<"\n";
    cout<<points[current-2].first<<" "<<points[current-2].second<<" "<<cost(points[current-2], {xs, ys})<<"\n";*/

    // <-
    for(int current = 0; current<=points.size(); current++){
        if(cost(points[current], {xs, ys}) <= t){
            ull ans1 = 0;
            ull currentCost = 0;
            ull x = xs, y = ys;

            int i = current;
            for(; i>=0 && currentCost <= t; i--){
                currentCost += cost(points[i], {x, y});

                if( currentCost <= t )
                    ans1++;

                x = points[i].first; y=points[i].second;
            } i++;

            for(int i=1; i<points.size() && currentCost <= t; i++){
                currentCost += cost(points[i], {x, y});
                if(currentCost<=t && i>current)
                    ans1++;

                x = points[i].first; y=points[i].second;
            }

            ans = max(ans, ans1);
        }

        if(cost(points[current], {xs, ys}) <= t){
            ull ans1 = 0;
            ull currentCost = 0;
            ull x = xs, y = ys;

            int i = current;
            for(; i<points.size() && currentCost <= t; i++){
                if(currentCost + cost(points[i], {x, y}) <=t){
                    ans1++;
                    currentCost += cost(points[i], {x, y});
                    x = points[i].first; y=points[i].second;
                }
            }

            if(x != xs && y!=ys)
                x = points[current].first, y = points[current].second;
            i = current-1;
            for(; i>=0 && currentCost <= t; i--){
                currentCost += 2*cost(points[i], {x, y});

                if( currentCost <= t )
                    ans1++;
            }

            ans = max(ans, ans1);
        }
    }

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

