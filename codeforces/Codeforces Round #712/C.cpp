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

bool itsOk(string &ans){
    int open = 0;

    for(char c : ans){
        if(c == '(')
            open++;
        else {
            if(!open)
                return false;
            open--;
        }
    }

    if(open)
        return false;
    return true;
}

void solve(){
    cin>>n;
    cin>>s;

    vector<int> nextOne;
    for(int i=0; i<n; i++){
        if(s[i]=='1')
            nextOne.push_back(i);
    }

    if(s[0]=='0' || s.back()=='0' || nextOne.size()%2){
        cout<<"NO\n";
        return;
    }

    string ans1(n, ')'), ans2(n, ')');

    for(int j=0; j<(nextOne.size()/2); j++){
        int i = nextOne[j];
        ans1[i] = '(';
        ans2[i] = '(';
    }

    bool isOpen = true;
    for(int i = 0; i<n; i++){
        if(s[i]=='0'){
            if(isOpen)
                ans1[i] = '(';
            else
                ans2[i] = '(';
            isOpen = !isOpen;
        }
    }

    if(itsOk(ans1) && itsOk(ans2)){
        cout<<"YES\n";
        cout<<ans1<<"\n";
        cout<<ans2<<"\n";
    }
    else
        cout<<"NO\n";

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

