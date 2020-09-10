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

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;
string r = "abacaba";
string s;

bool check(string s, int i){

    if(i+r.size()-1 >= s.size())
        return false;

    for(int j=0; j<r.size(); j++){
        if(s[j+i]=='?'){
            s[j+i] = r[j];
        }
        if(s[j+i]!=r[j]){
            return false;
        }
    }

    for(char &c : s)
        if(c=='?')
            c = 'z';

    int times = 0;
    for(int i=0; i<n; i++){
        if(s.substr(i, r.size()) == r)
            times++;
    }

    if(times > 1)
        return false;

    ::s=s;


    return true;

}

void solve(){
    cin>>n;
    cin>>s;
    //s = '?'+r+'?'+r.substr(0, r.size()-1);
    //n=s.size();

    int times = 0;
    for(int i=0; i<n; i++){
        if(s.substr(i, r.size()) == r)
            times++;
    }

    if(times>1){
        cout<<"No\n";
        return;
    }

    if(times == 1){
        for(char &c : s)
        if(c=='?')
            c = 'z';
        cout<<"Yes\n";
        cout<<s<<"\n";
        return;
    }

    for(int i=0; i<n; i++){
        if( (s[i] == 'a' || s[i] == '?') && check(s, i)){
            cout<<"Yes\n";
            cout<<s<<"\n";
            return;
        }
    }

    cout<<"No\n";
}


int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

/*
1
8
a??acaba

1
8
a??acaba

1
13
abac?b?bacaba
*/
