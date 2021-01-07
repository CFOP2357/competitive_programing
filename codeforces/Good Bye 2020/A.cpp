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

vector<long double> x;
vector<ull> b;
ull n;

void solve(){
    x.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        long double z; cin>>z;
        x.push_back(z);
    }

    set<float> area;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(x[i]==x[j]) continue;

            long double a = abs(x[i]-x[j]);
            long double b = sqrt(1+x[i]*x[i]);
            long double c = sqrt(1+x[j]*x[j]);
            long double s = (a+b+c)/2;

            long double A = sqrt(s*(s-a)*(s-b)*(s-c));
            //if(a>0 && b>0 && c>0)cout<<A<<"\n";



            if(a>0 && b>0 && c>0)
                area.insert(A);
        }

    cout<<area.size()<<"\n";
    //for(auto k : area) cout<<k<<"\n";


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

