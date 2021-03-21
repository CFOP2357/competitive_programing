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
        b.push_back(i+1);
    }

    b.back()=0;

    queue<int> next;
    vector<int> ans;

    vector<bool> ban(n, false);

    for(int i=0; i<n; i++){

        if(ban[i]) continue;

        if(__gcd(a[b[i]], a[i]) == 1 ){
            ans.push_back(b[i]);
            b[i] = b[b[i]];
            ban[b[i]] = true;
        }

    }

    for(int i=0; i<n; i++){

        if(ban[i]) continue;

        if(__gcd(a[b[i]], a[i]) == 1 ){
            ans.push_back(b[i]);
            b[i] = b[b[i]];
            next.push(i);
            ban[b[i]] = true;
        }

    }

    cout<<"#\n";

    if(next.size()){

        int i = next.front();
        while(next.size() && b[i] != i){
            next.pop();

            if(ban[i]){
                    if(next.size())
                i=next.front();
                continue;
            }
            if(__gcd(a[b[i]], a[i]) == 1 ){
                ans.push_back(b[i]);
                b[i] = b[b[i]];
                next.push(i);
                ban[b[i]] = true;
            }

            if(next.size())
            i=next.front();
        }
    }


    cout<<ans.size()<<" ";
    for(int k : ans)
        cout<<k<<" ";
    cout<<"\n";
}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

