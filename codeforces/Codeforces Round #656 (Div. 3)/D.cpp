#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

vector<ull> a;
vector<ull> b;
ull n;
int m = INT_MAX;

int solve(string s, char c = 'a'){
    if(s.size()==1){
        return c!=s[0];
    }

    int ans1 = 0;
    for(int i=0; i<s.size()/2; i++)
        ans1 += s[i]!=c;
    ans1 += solve(s.substr(s.size()/2), c+1);

    int ans2 = 0;
    for(int i=s.size()/2; i<s.size(); i++)
        ans2 += s[i]!=c;
    ans2 += solve(s.substr(0, s.size()/2), c+1);

    return min(ans1, ans2);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        cout<<solve(s)<<"\n";
    }
    return 0;
}
