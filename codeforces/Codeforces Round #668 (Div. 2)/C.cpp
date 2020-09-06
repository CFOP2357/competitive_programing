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

int one[MAX];
int zero[MAX];
int change[MAX];
ull n, k;
string s;

void solve(){
    cin>>n>>k;
    cin>>s;
    s = ' '+s;
    fill(one, one+n, 0);
    fill(zero, zero+n, 0);
    fill(change, change+n, 0);

    queue<int> last;

    for(int i=1; i<=k; i++){
        one[i]=one[i-1];
        zero[i]=zero[i-1];
        change[i]=change[i-1];
        if(s[i]=='1')
            one[i]++;
        else if(s[i]=='0')
            zero[i]++;
        else{
            change[i]++;
            last.push(i);
        }
    }


    for(int i = 1; i+k-1<=n; i++){

        while(last.size() && last.front()<i) last.pop();

        one[i]=one[i-1];
        zero[i]=zero[i-1];
        change[i]=change[i-1];
        if(s[i]=='1')
            one[i]++;
        else if(s[i]=='0')
            zero[i]++;
        else
            change[i]++;

        one[i+k-1]=one[i+k-2];
        zero[i+k-1]=zero[i+k-2];
        change[i+k-1]=change[i+k-2];
        if(s[i+k-1]=='1')
            one[i+k-1]++;
        else if(s[i+k-1]=='0')
            zero[i+k-1]++;
        else{
            change[i+k-1]++;
            last.push(i+k-1);
        }

        int ones = one[i+k-1]-one[i-1];
        int zeros = zero[i+k-1]-zero[i-1];
        int changes = change[i+k-1]-change[i-1];

        //cout<<ones<<" "<<zeros<<" "<<changes<<"\n";

        if(ones == zeros){
            if(changes%2){
                cout<<"NO\n";
                return;
            }
        }
        else {
            if(abs(ones-zeros) > changes){
                cout<<"NO\n";
                return;
            }
            if(abs(ones-zeros) < changes && abs(abs(ones-zeros) - changes)%2){
                cout<<"NO\n";
                return;
            }
            while(abs(ones-zeros)){
                if(!last.size() || last.front() > i+k-1){
                    cout<<"NO\n";
                    return;
                }
                int j = last.front(); last.pop();
                if(ones>zeros){
                    zeros++;
                    zero[j]++;
                    s[j] = '0';
                    zero[i+k-1]++;
                }
                else {
                    ones++;
                    one[j]++;
                    s[j] = '1';
                    one[i+k-1]++;
                }
                change[i+k-1]--;
                change[j]--;
            }

        }

    }

    for(int i = 1; i+k-1<=n; i++){
        int ones = one[i+k-1]-one[i-1];
        int zeros = zero[i+k-1]-zero[i-1];
        int changes = change[i+k-1]-change[i-1];

        //cout<<ones<<" "<<zeros<<" "<<changes<<"\n";

        if(ones == zeros){
            if(changes%2){
                cout<<"NO\n";
                return;
            }
        }
        else {
            if(abs(ones-zeros) > changes){
                cout<<"NO\n";
                return;
            }
            if(abs(ones-zeros) < changes && abs(abs(ones-zeros) - changes)%2){
                cout<<"NO\n";
                return;
            }
        }

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
4 2
1??1
*/
