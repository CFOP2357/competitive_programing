#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005

long long p[MAX];

int realTime;

int pos[MAX];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    int n, k;

    while(t--){
        cin>>n>>k;

        realTime = 0;

        for(int i=1; i<=n; i++){
            cin>>p[i];
        }
        for(int i=1; i<=n; i++){
            while(p[i]!=i){
                swap(p[i], p[p[i]]);
                realTime++;

            }
        }
        /*for(int i=1; i<=n; i++){
            cout<<p[i]<<" ";
        }*/

        if(realTime==k)
            cout<<"Yes\n";
        else{
           if(realTime > k)
                cout<<"No\n";
           else {
                //k-=realTime;

                    if((k-realTime)%2){
                        cout<<"No\n";
                    }
                    else cout<<"Yes\n";

           }
        }
    }
    //cout<<"\n";

    return 0;
}
