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
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }
    sort(a.begin(), a.end(), greater<int>());

    int ans1=-1, ans2=-1;
    for(int i = 0; i<=101; i++){
        //cout<<i<<" "<<a.back()<<"$\n";
        if(a.empty() || a.back()!=i){
            if(ans1<0){
                ans1=i;
                ans2=i;
                break;
            }
            else {
                ans2=i;
                break;
            }
        }
        else {
            a.pop_back();
            if(a.empty() || a.back()!=i){
                if(ans1<0){
                    ans1=i;
                }
            }
            else {
                a.pop_back();
            }
        }
        while(a.size() && a.back()==i)a.pop_back();
    }

    cout<<ans1+ans2<<"\n";
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

