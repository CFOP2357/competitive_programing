#include <bits/stdc++.h>
using namespace std;

#define MAX 200005

vector <bool> a;
int pos[MAX];

void solve(){
    int n;
    cin>>n;
    a.clear();
    string b; cin>>b;
    for(int i=0; i<n; i++){
        a.push_back( b[i] - '0');
    }
    stack <int> uno;
    stack <int> cero;
    int s = 0;
    for(int i=0; i<n; i++){
        if(a[i]){ //es un uno
            if(uno.size()){
                pos[i]=uno.top();
                cero.push(uno.top());
                uno.pop();
            }
            else {
                s++;
                cero.push(s);
                pos[i]=s;
            }
        }
        else {
            if(cero.size()){
                pos[i]=cero.top();
                uno.push(cero.top());
                cero.pop();
            }
            else {
                s++;
                uno.push(s);
                pos[i]=s;
            }
        }
    }
    cout<<s<<"\n";
    for(int i=0; i<n; i++)
        cout<<pos[i]<<" ";
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }

}

