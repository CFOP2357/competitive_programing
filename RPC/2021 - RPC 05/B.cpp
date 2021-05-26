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

vector<ull> a;
vector<ull> b;
ull n, m;
string s;


void solve(){
    a.clear(); b.clear();

    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }
    sort(all(a));

    ull ans = 0;
    int min_possible = 0;
    for(int i = 0; i<n; i++){
      for(int j=i+1; j<n; j++){
        ull d = 0;
        for(int k=j+1; k<n; k++)
          if(a[i]+a[j]>a[k])
            d++;
        ull current_ans = 1;
        for(ull k=d; k>=1; k--){
          current_ans *= k;
          current_ans /= (d-k+1);
          ans += current_ans;
        }
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

