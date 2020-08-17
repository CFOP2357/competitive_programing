#include <bits/stdc++.h>
using namespace std;

#define MAX 500100
#define MOD 1000000007

typedef long long ull;

inline ull subMod(ull a, ull b){
    return ((a+MOD)-b)%MOD;
}

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    s+=s;
    ull ans=0;
    vector <ull> b;

    b.push_back(0);
    char last=s[0];

    while(n && s[n-1]==last){
        n--;
        b.back()++;
    }
    if(!n){
        ans++;
        b.back()--;
        b.push_back(1);
    }

    for(int i=0; i<n; i++){

        if(s[i]==last){
            b.back()++;
        }
        else {
            b.push_back(1);
            last =s[i];
        }

    }

    for(ull i : b)
        ans += i/3;

    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
}

/*
1
129
LLLLLRRRRRRRRRLLLLLLLLLLRRRRRRRRRLRRRRRRRRRRLLLLLLLRRLLLLLLLRRRRLLLLLLLRRRRRRRRRLLLLLLRRLLLLLLLRRLLRRRRRRLLLLRRRRRRRRRRLLRRRRLLLR

LRLRLRLRLRLRLRLRLLLLLLLLRRRRRRRRRLRRRRRRRRRRLLLLLLLRRLLLLLLLRRRRLLLLLLLRRRRRRRRRLLLLLLRRLLLLLLLRRLLRRRRRRLLLLRRRRRRRRRRLLRRRRLLLR


*/

