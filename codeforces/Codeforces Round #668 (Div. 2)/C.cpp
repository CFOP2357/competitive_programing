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

#define MAX 300100
#define MOD 1000000007

ull n, k;
string s;

void solve(){
    cin>>n>>k;
    cin>>s;

    int one = 0, zero = 0, change = 0;

    for(int i = 0; i<k-1; i++)
        if(s[i]=='1')
            one++;
        else if(s[i]=='0')
            zero++;
        else change ++;

    for(int i = 0; i+k-1<n; i++){

        if(s[i+k-1]=='1')
            one++;
        else if(s[i+k-1]=='0')
            zero++;
        else change ++;

        //cout<<one<<" "<<zero<<" "<<change<<"\n";

        if(i+k <n){
            //cout<<i<<" ";
            if(s[i+k] != '?' && s[i+k] != s[i] && s[i]!='?'){
                cout<<"NO\n";
                return;
            }
            if(s[i+k] == '?')
                s[i+k] = s[i];
            if(s[i] == '?'){
                //cout<<";";
                change--;
                s[i] = s[i+k];
                if(s[i]=='1')one++;
                else if(s[i]=='0')zero++;
                else change++;
            }
            //cout<<"#\n";
        }


        if(abs(one-zero) > change){
            cout<<"NO\n";
            return;
        }

        if(s[i]=='1')
            one--;
        else if(s[i]=='0')
            zero--;
        else change --;

    }


    cout<<"YES\n";

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
        //cout<<s<<"\n";
        //return 0;
    }
    return 0;
}
/*
1
7 4
1?0??1?

1
6 2
????00

1
4 2
1??1
*/
