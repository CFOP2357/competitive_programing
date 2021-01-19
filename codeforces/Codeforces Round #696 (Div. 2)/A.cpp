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

ull n;

void solve(){

    cin>>n;
    string b; cin>>b;

    string a = "";
    char last = '0';

    a.push_back('1');
    if(b[0]=='1'){
        last = '2';
    }
    else {
        last = '1';
    }

    for(int i=1; i<n; i++){
        if(b[i]=='1'){
            if(last == '2'){
                last = '1';
                a.push_back('0');
            }
            else {
                last = '2';
                a.push_back('1');
            }
        }
        else {
            if(last == '1'){
                last = '0';
                a.push_back('0');
            }
            else {
                last = '1';
                a.push_back('1');
            }
        }
    }

    cout<<a<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

