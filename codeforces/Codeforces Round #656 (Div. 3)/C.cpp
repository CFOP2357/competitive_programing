#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef int ull;

deque<ull> a;
vector<ull> b;
int n;

void solve(){
    a.clear();
    cin>>n;
    int d = 0;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        ::a.push_back(a);
        if(i>0 && ::a[i]>=::a[i-1] && d==i-1){
            d = i;
        }
    }

    int D = n-1;
    for(int i=n-1; i>=0; i--){
        if(i<n-1 && a[i]>=a[i+1] && D==i+1){
            D = i;
        }
    }
    if(D<=d){
        cout<<"0\n";
        return;
    }
    int ans = 0;
    while(d<n){
        ans = d+1;
        d++;
        for(int i=d+1; i<n; i++){
            if(i>0 && a[i]>=a[i-1] && d==i-1){
                d = i;
            } else break;
        }
        if(D<=d){
            cout<<ans<<"\n";
            return;
        }
    }
    cout<<n<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

