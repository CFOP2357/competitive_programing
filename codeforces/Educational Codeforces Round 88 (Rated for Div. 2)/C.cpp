#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
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
ull h, c, t;

void solve(){

    cin>>h>>c>>t;

    if(t <= (h+c)/2){
        cout<<2<<"\n";
        return;
    }

    ull y = (t-h) / (h+c-2*t);

    if((t-h) % (h+c-2*t)){
        if( (double)((t-h) % (h+c-2*t)) /  (double)(h+c-2*t) > (double)0.5 )
            y++;
    }

    double k  = (double)((y+1)*h + y*c) / (double)(2*y + 1);
    double k2 = (double)((y+2)*h + (y+1)*c) / (double)(2*(y+1) + 1);
    double k3 = (double)((y)*h + (y-1)*c) / (double)(2*(y-1) + 1);

    if(y==0){
        if((double)abs(h-t) <= (double)abs((double)(h+c+h)/(double)3-(double)t))
            cout<<1<<"\n";
        else
            cout<<3<<"\n";
        return;
    }

    if(abs(k-t) <= abs(k2-t) && abs(k-t) < abs(k3-t))
        cout<<y+y+1<<"\n";
    else if(abs(k2-t) < abs(k-t) && abs(k2-t) < abs(k3-t))
        cout<<y+y+3<<"\n";
    else cout<<y+y-1<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
