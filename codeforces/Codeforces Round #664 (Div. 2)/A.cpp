#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    int r, g, b, w;
    cin>>r>>g>>b>>w;
    long long total = r+g+b+w;
    int zero = 0;
    int impar = r%2 + g%2 + b%2 + w%2;
    zero = !r + !g + !b + !w;
    //cout<<zero<<"\n";

    if(total%2){ //impar
        if(zero){
            if(zero == 3)
                cout<<"Yes\n";
            else if(impar==1)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
        else {
            if(impar == 1 || impar==3 || impar==0)
                cout<<"Yes\n";
            else {
                if(r==b && r==g)
                    cout<<"Yes\n";
                else cout<<"No\n";
            }
        }
    }
    else{ //par
        if(zero){
            if(zero == 3)
                cout<<"Yes\n";
            else if(impar>0)
                cout<<"No\n";
            else
                cout<<"Yes\n";
        }
        else {
            if(impar == 0 || impar==4)
                cout<<"Yes\n";
            else{
                if(r==b && r==g)
                    cout<<"Yes\n";
                else cout<<"No\n";
            }
        }
    }
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
