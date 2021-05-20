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
    cin>>s;
    string rev = s;
    reverse(all(rev));

    int zeros = 0;
    for(char c : s)
        if(c=='0'){
            zeros++;
        }

    int asimetricZeros = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='0' && rev[i]=='1')
            asimetricZeros++;
    }

    if(rev == s){
        if(zeros>0){
            if(n%2 && s[n/2]=='0' && zeros>1) //Alice wins by 1
                cout<<"ALICE\n";
            else //BOB wins by 2 when 10...01 and by 1 when 11...101...11
                cout<<"BOB\n";
            return;
        }
    }
    else {
        if(zeros>0 && !(n%2 && s[n/2]=='0' && zeros==2)){
            cout<<"ALICE\n";
            return;
        }
    }
    cout<<"DRAW\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

