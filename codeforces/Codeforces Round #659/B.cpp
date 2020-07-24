#include <bits/stdc++.h>
using namespace std;

#define MAX 300005

long long d[MAX];
pair<int, int> nop[MAX];
int n, k, l;

long long altura(int tiempo){
    for(int i=0; i<=k; i++)
        if(i==tiempo)
            return i;
    for(int i=1; i<k; i++)
        if(i+k==tiempo)
            return k-i;
}

int calcularT(int tiempo, int i){

    return -1;
}


int main(){
    int t;

    cin>>t;

    while(t--){
        cin>>n>>k>>l;
        for(int i=0; i<n; i++)
            cin>>d[i];

        int tiempo =0;
        bool yes = true;
        for(int i=0; i<n-1; i++) {
            cout<<i<<" "<<altura(tiempo)<<" #";
            if(d[i] + altura(tiempo) > l){
                cout<<"No\n";
                yes = false;
                break;
            }
            int tiempo1 = tiempo;

            if(tiempo < k && d[i] + altura(k) <= l){
                tiempo1 = tiempo = k-1;
                //cout<<"v";
            }

            bool posible = false;

            do {
                tiempo++;
                tiempo %= (2*k);
            cout<<tiempo<<" ";

                //cout<<
                if(d[i+1] + altura(tiempo) <= l){
                    posible = true;
                    break;
                }


                //cout<<"v";
            } while(tiempo!=tiempo1 && tiempo != -1);
            cout<<"\n";
            if(!posible){
                cout<<"No\n";
                yes = false;
                break;
            }

        }
        if(yes)
            cout<<"Yes\n";

    }

    return 0;
}

/*
1
4 3 4
0 2 4 3
*/
