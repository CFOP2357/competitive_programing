#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

inline ull subMod(ull a, ull b){
    return ((a+MOD)-b)%MOD;
}

vector <ull> a;
vector <ull> sum;

void solve(){
    a.clear();
    sum.clear();
    int n; cin>>n;
    string s; cin>>s;
    sum.push_back(0);
    a.push_back(0);
    int ans = 0;
    for(int i=0; i<n; i++){
        a.push_back(s[i]-'0');
        sum.push_back(sum.back()+a.back());
        if(a.back()==1)
            ans++;
    }

    int one = 0;
    vector<int> last;
    for(int i=1; i<=n; i++){
       if(a[i]==1){
            ans += one;
            one++;
       }
       else if(a[i]>0){
         int p = a[i];
         while(last.size() && last.back() == 0 && p>1){
            p--;
            last.pop_back();
         }
         if(p>1){
            last.push_back(p);
         }
         else {
            ans+=one;
            one=1;
         }
       }
       else {
        last.push_back(0);
       }
    }

    one = 0;
    last.clear();
    reverse(a.begin(), a.end());
    for(int i=1; i<=n; i++){
       if(a[i]==1){
            ans += one;
            one++;
       }
       else if(a[i]>0){
         int p = a[i];
         while(last.size() && last.back() == 0 && p>1){
            p--;
            last.pop_back();
         }
         if(p>1){
            last.push_back(p);
         }
         else {
            ans+=one;
            one=1;
         }
       }
       else {
        last.push_back(0);
        one = 0;
       }
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
}
/*
1
10
90000000000

1
5
10031
*/
