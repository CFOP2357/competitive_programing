#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef int ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    cin>>n; a.clear();
    ull sum = 0;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
        sum+=z;
    }

    if(*max_element(a.begin(), a.end()) > sum/2)
        cout<<"T\n";
    else if(sum%2)
        cout<<"T\n";
    else cout<<"HL\n";
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

