#include <iostream>
#include <vector>
#include <algorithm>

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

ull n, m, k;
string s;

vector<int> arr;

void solve(){
    arr.clear();

    cin>>n>>k;
    if(k>30)
        exit(-1);
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        arr.push_back(z);
    }
    sort(all(arr));

    double ans = 0;
    int a, b;
    a = arr[0]-1;
    b = k-arr.back();
    if(b>a)
        swap(a, b);
    for(int i=1; i<arr.size(); i++){
        ans = max(ans, ((double)(arr[i]-arr[i-1]-1))/((double)k));
        b = max(b, (arr[i]-arr[i-1])/2);
        if(b>a)
            swap(a, b);
    }
    ans = max(ans, ((double)(a+b))/((double)k));

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));
    //cout.precision(10000000);

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}

