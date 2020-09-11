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

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

void solve(){

    cin>>n;
    ull correct = 0;
    ull k = 0;
    ull p = 0;
    for(int i=1; i<=n; i++){
        int z; cin>>z;
        if(z==i){
            correct++;
            if(k) p++;
            k = 0;
        }
        else k++;
    }
    if(k) p++;


    if(correct == n)
        cout<<"0\n";
    else if(correct == 0 || p<=1)
        cout<<"1\n";
    else cout<<"2\n";

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

