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

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

ull n;

void solve(){
    string s; cin>>s;

    int ans = INT_MAX;
    for(char a = '0'; a<='9'; a++)
        for(char b = '0'; b<='9'; b++){
            bool isA = false;
            int er = 0;
            int ss = 0;
            for(char c : s){
                if(isA){
                    if(c == a){
                        ss++;
                        isA = false;
                    }
                    else er++;
                }
                else {
                    if(c == b){
                        ss++;
                        isA = true;
                    }
                    else er++;
                }
            }
            if(a!=b)
                er += ss%2;
            ans = min(er, ans);
        }

    cout<<ans<<"\n";

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


