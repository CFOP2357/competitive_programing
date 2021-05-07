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

int query(int t, int i, int j, int x){
    i++, j++;

    cout<<"? "<<t<<" "<<i<<" "<<j<<" "<<x<<endl;
    int resp; cin>>resp;
    if(resp == -1)
        exit(0);

    return resp;
}

void solve(){
    cin>>n;
    vector<int> ans(n);

    int onePos = 0;
    for(int i=0; i<n; i+=2){ //3+(n/2) queries
        if(i==n-1)
            i--;
        int resp = query(2, i, i+1, 1);
        if(resp == 1){
            onePos = i;
            break;
        }
        if(resp == 2){
            resp = query(2, i+1, i, 1);
            if(resp == 1){
                onePos = i+1;
                break;
            }
        }
    }

    ans[onePos] = 1;
    for(int i=0; i<n; i++){ //n queries
        if(onePos == i)
            continue;
        ans[i] = query(1, onePos, i, n-1);
    }


    cout<<"! ";
    for(auto a : ans)
        cout<<a<<" ";
    cout<<endl;
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

