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
typedef long long ll;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

ll N, A;

void solve(){
    cin>>N>>A;

    if(N == 3){
        cout<<"POSSIBLE\n";
        cout<<"0 0\n";
        cout<<"1 0\n";
        cout<<"1 "<<A<<"\n";
    }
    else if(N == 4){
        if(N%2 == 0){
            cout<<"POSSIBLE\n";
            cout<<"0 0\n";
            cout<<"1 0\n";
            cout<<"1 "<<A/2<<"\n";
            cout<<"0 "<<A/2<<"\n";
        }
        else {
            if(A == 1)
                cout<<"IMPOSSIBLE\n";
            else{
                cout<<"POSSIBLE\n";
                cout<<"0 0\n";
                cout<<A-1<<"0 "<<"\n";
                cout<<"1 1\n";
                cout<<"0 1\n";
            }
        }
    }
    else if(N == 5){
        if(A%2 == 0 and A/2 >= 3){
            cout<<"POSSIBLE\n";
            cout<<"0 0\n";
            cout<<"2 0\n";
            cout<<"2 1\n";
            cout<<"1 "<<A/2 - 2<<"\n";
            cout<<"0 1\n";
            cout<<"0 0\n";
        }
        else cout<<"IMPOSSIBLE\n";
    }
    else cout<<"IMPOSSIBLE\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}


