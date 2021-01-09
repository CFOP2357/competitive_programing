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

vector<ull> a;
vector<ull> b;
int n;

void updateRate(const int i){
    for(int j = max(i-5, 1); j<=min(i+5, n-2); j++){
        if(a[j]>a[j-1] && a[j]>a[j+1])
            b[j]=1;
        else if(a[j]<a[j-1] && a[j]<a[j+1])
            b[j]=1;
        else
            b[j]=0;
    }
}

int getRate(const int i){
    int rate = 0;
    for(int j = max(i-5, 0);j<=min(i+5, n-1); j++){
        rate += b[j];
    }
    return rate;
}

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    int ans = 0;
    b.push_back(0);
    for(int i=1; i<n-1; i++){
        if(a[i]>a[i-1] && a[i]>a[i+1])
            b.push_back(1);
        else if(a[i]<a[i-1] && a[i]<a[i+1])
            b.push_back(1);
        else
            b.push_back(0);

        ans += b.back();
    }
    b.push_back(0);

    /*for(int k : b)
        cout<<k<<" ";
    cout<<"\n";*/

    int higherChange(0), t(0);

    for(int i=1; i<n-1; i++){

        const int realRate(getRate(i));
        //cout<<realRate<<"\n";


        const int realValue = a[i];
        int minRate = realRate;
        //cout<<realValue<<"\n";

        a[i] = a[i+1];
        updateRate(i);
        minRate = min(minRate, getRate(i));
        //cout<<getRate(i)<<"\n";

        a[i] = a[i-1];
        updateRate(i);
        minRate = min(minRate, getRate(i));
        //cout<<getRate(i)<<"\n";

        a[i] =  INT_MAX;
        updateRate(i);
        minRate = min(minRate, getRate(i));

        a[i] = INT_MIN;
        updateRate(i);
        minRate = min(minRate, getRate(i));

        a[i] = realValue;
        updateRate(i);

        higherChange = max(higherChange, realRate-minRate);

    }


    ans -= higherChange;

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
1
3
1 5 3
*/
