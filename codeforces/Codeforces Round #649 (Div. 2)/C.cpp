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
ull n;

bool d[MAX];

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        d[z] = true;
    }

    int m = 0;
    while(d[m]) m++;

    queue<ull> nxt;

    for(int i=0; i<n; i++){
        if(a[i]<m && !nxt.size()){
            b.push_back(m++);
            while(d[m]) m++;
            nxt.push(a[i]);
        }
        else if(a[i]>m && a[i]==m+1 && !nxt.size()){
            b.push_back(m++);
            while(d[m]) m++;
            nxt.push(a[i]);
        }
        else if(nxt.size()){
            if(nxt.front()!=a[i]){
                b.push_back(nxt.front()); nxt.pop();
                if(nxt.size() && nxt.front() < a[i]){
                    cout<<"-1\n";
                    return;
                }
                nxt.push(a[i]);
            }
            else {
                b.push_back(m++);
                while(d[m]) m++;
            }
        }
        else{
            cout<<"-1\n";
            return;
        }
    }

    for(int ans : b) cout<<ans<<" ";
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

