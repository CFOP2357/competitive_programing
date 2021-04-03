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

    cin>>n;

    vector<pii> one;
    vector<pii> two;

    bool isOne = true;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(isOne){
                one.push_back({i, j});
            }
            else{
                two.push_back({i, j});
            }
            isOne = !isOne;
        }
        if(!(n%2))
            isOne = !isOne;
    }

    for(int i=0; i<n*n; i++){
        int a; cin>>a;

        if(a!=2){
            if(two.size()){
                cout<<"2 "<<two.back().first<<" "<<two.back().second<<endl;
                two.pop_back();
            }
            else {
                int ans = 1;
                if(a==1)
                    ans = 3;
                cout<<ans<<" "<<one.back().first<<" "<<one.back().second<<endl;
                one.pop_back();

            }
        }
        else {
            if(one.size()){
                cout<<"1 "<<one.back().first<<" "<<one.back().second<<endl;
                one.pop_back();
            }
            else {
                cout<<"3 "<<two.back().first<<" "<<two.back().second<<endl;
                two.pop_back();
            }
        }

        //cout.flush();
    }
}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

