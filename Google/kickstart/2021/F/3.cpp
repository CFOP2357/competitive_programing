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

///////////////////////////* GEEKSFORGEEKS*/////////////////////////////////////////
double area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
   return abs((double)(x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

/* A function to check whether point P(x, y) lies inside the triangle formed
   by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool isInside(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x, ll y)
{
   /* Calculate area of triangle ABC */
   double A = area (x1, y1, x2, y2, x3, y3);

   /* Calculate area of triangle PBC */
   double A1 = area (x, y, x2, y2, x3, y3);

   /* Calculate area of triangle PAC */
   double A2 = area (x1, y1, x, y, x3, y3);

   /* Calculate area of triangle PAB */
   double A3 = area (x1, y1, x2, y2, x, y);

   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}
////////////////////////////////////////////////////////////////////////////////////

double dist(ll x1, ll y1, ll x2, ll y2){
    return sqrt((double)((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
}

bool inside_rect(ll x1, ll y1, ll x2, ll y2, ll x, ll y){
    if(dist(x1, y1, x, y) + dist(x2, y2, x, y) == dist(x1, y1, x2, y2))
        return true;
    return false;
}

vector<ull> X;
vector<ull> Y;
ull n, m;
string s;

void solve(){
    X.clear(); Y.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ll x, y; cin>>x>>y;
    }

    ll x, y; cin>>x>>y;

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


