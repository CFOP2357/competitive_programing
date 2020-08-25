#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

inline ull subMod(ull a, ull b){
    return ((a+MOD)-b)%MOD;
}

vector <ull> a;
vector <ull> b;

void solve(){
    string s; cin>>s;
    int x; cin>> x;

    //formar w
    string w(s.size(), '1');
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0'){
            if(i+x<s.size()) w[i+x] = '0';
            if(i-x>=0) w[i-x] = '0';
        }
    }

    //checar w
    for(int i=0; i<s.size(); i++){
        if(s[i]=='1'){
            if(i+x<s.size() &&  w[i+x]=='1') continue;
            if(i-x>=0 && w[i-x]=='1')  continue;
            cout<<-1<<"\n";
            return;
        }
    }

    //imprimir w (si esta bien)
    cout<<w<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
}
