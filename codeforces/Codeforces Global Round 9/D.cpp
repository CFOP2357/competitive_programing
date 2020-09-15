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

    map<int, int> times;

    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
        times[z]++;
    }

    vector<int> ans;

    for(int i=0; i<=n; i++){
        for(int j=0; j<n; j++){
            if(!times[j]){
                times[a[j]]--;
                a[j]=j;
                times[j]++;
                ans.push_back(j+1);
                //cout<<j<<" ";
                break;
            }
        }
    }

    /*for(int k : a)
            cout<<k<<" ";
    cout<<"\n";*/

    int r = n;
    for(int i=0; i<n; i++){
        if(a[i]!=i){
            int t = -1;
            for(int j = 0; j<n; j++){
                if(a[j]==i){
                    t = j;
                }
            }

            if(t>=0){
                a[t] = r;
                ans.push_back(t+1);
            }


            r = a[i];
            a[i] = i;
            ans.push_back(i+1);
        }
    }

    cout<<ans.size()<<"\n";
    for(int k : ans)
            cout<<k<<" ";
    cout<<"\n";
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

/*
1
9
2 0 1 1 2 4 4 2 0
*/
