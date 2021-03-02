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

ull howManyBetween(vector<ull>& point, ull a, ull b){
    ull firstPosition = lower_bound(all(point), a) - point.begin();
    ull lastPosition = upper_bound(all(point), b) - point.begin();

    return lastPosition-firstPosition;
}

ull calculateMax(vector<ull>& box, vector<ull>& point){

    ull pointAtBegin  = 0;
    for(int i=0; i<box.size(); i++){
        if(lower_bound(all(point), box[i]) != point.end() && *lower_bound(all(point), box[i]) == box[i])
            pointAtBegin++;
    }

    int i = 0, j = 0;

    ull ans = pointAtBegin;
    while(i<box.size() || j<point.size()){

        if(j>=point.size() || (i<box.size() && box[i]<=point[j])){


            if(lower_bound(all(point), box[i]) != point.end() && *lower_bound(all(point), box[i]) == box[i])
                pointAtBegin--;

            ans = max(ans, howManyBetween(point, box[i]-i, box[i])+pointAtBegin);

            i++;
        }
        else {
            if(i)
                ans = max(ans, howManyBetween(point, point[j]-i+1, point[j])+pointAtBegin);
            j++;
        }

    }

    return ans;
}

void solve(){
    a.clear(); b.clear();
    cin>>n>>m;

    vector<ull> boxLessThanZero;
    vector<ull> boxMoreThanZero;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);

        if(z<0)
            boxLessThanZero.push_back(abs(z));
        else
            boxMoreThanZero.push_back(z);

    }
    sort(all(boxLessThanZero));
    sort(all(boxMoreThanZero));


    vector<ull> pointLessThanZero;
    vector<ull> pointMoreThanZero;
    for(int i=0; i<m; i++){
        ull z; cin>>z;
        b.push_back(z);

        if(z<0)
            pointLessThanZero.push_back(abs(z));
        else
            pointMoreThanZero.push_back(z);
    }
    sort(all(pointLessThanZero));
    sort(all(pointMoreThanZero));

    //cout<<a.end()-a.begin()<<"$\n";
    //cout<<howManyBetween(pointMoreThanZero, 8, 10)<<"%\n";;
    ull ans = calculateMax(boxLessThanZero, pointLessThanZero) + calculateMax(boxMoreThanZero, pointMoreThanZero);
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

/*
1
2 1
1 2
10

1
2 2
-1000000000 1000000000
-1 1


1
5 6
-1 1 5 11 15
-4 -3 -2 6 7 15

1
4 4
1 2 3 4
5 6 7 8

1
1 1
1
8
*/
