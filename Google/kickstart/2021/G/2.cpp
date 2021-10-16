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
typedef long long ll;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

struct ObjectPlace{
    int x1;
    int y1;
    int x2;
    int y2;
};

vector<ObjectPlace> object_place;
ll k;

ll distance_to(ObjectPlace object_place, int x, int y){
    ll distance = 0;

    if(y > object_place.y2)
        distance += y - object_place.y2;
    if(y < object_place.y1)
        distance += object_place.y1 - y;

    if(x > object_place.x2)
        distance += x - object_place.x2;
    if(x < object_place.x1)
        distance += object_place.x1 - x;

    return distance;
}

void solve(){
    object_place.clear();
    cin>>k;

    if(k > 30){
        cout<<"0 0\n";
        return;
    }


    for(int i = 0; i < k; i++){
        int x1, y1;
        int x2, y2;
        cin>>x1>>y1>>x2>>y2;

        object_place.push_back({x1, y1, x2, y2});
    }

    ll min_distance = LLONG_MAX;
    int x_ans(0), y_ans(0);
    for(int x = -105; x <= 105; x++)
        for(int y = -105; y <= 105; y++){
            ll distance = 0;
            for(auto &object_place : ::object_place)
                distance += distance_to(object_place, x, y);

            if(distance < min_distance){
                min_distance = distance;
                x_ans = x;
                y_ans = y;
            }
        }

    cout<<x_ans<<" "<<y_ans<<"\n";
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


