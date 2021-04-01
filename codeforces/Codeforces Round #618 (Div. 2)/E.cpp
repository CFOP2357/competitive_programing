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
typedef double ld;
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
    vector<ld> ans(n);
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        ans[i] = z;
    }

    int j = 0;
    ld acum = 0;
    for(int i=n-1; i>=0; i--){

        //cout<<acum<<" "<<j+1<<" "<<ans[i]<<"%\n";

        if((acum + ans[i]) / (ld)(j+1) <= ans[i] ){
            //cout<<"$$\n";
            acum += ans[i];
            j++;
        }
        else {
            ld avg = acum / (ld)j;
            //cout<<avg<<"#\n";
            for(int k=0; k<j; k++)
                ans[i+k+1]=avg;
            j = 1;
            acum = ans[i];
        }


    }

    ld avg = acum / (ld)j;
    for(int k=0; k<j; k++)
        ans[k]=avg;

    for(ld k : ans)
        cout<<k<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    cout.precision(1000);
    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

