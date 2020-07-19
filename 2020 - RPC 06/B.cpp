#include <bits/stdc++.h>

using namespace std;

long long m = LONG_MAX;

long long a[3];
long long b[3];

long long x, y;
vector <pair<long long, long long>> esquina;
bool v[3];

void encontrar(int i=0){

    if(i==3){
        x = y = 0;
        //cout<<"#";
        for(pair<long long, long long> p : esquina){
            x = max(x, p.first);
            y = max(y, p.second);
            //cout<<p.first<<","<<p.second<<" ";
        }
        //cout<<"\n";
        //cout<<x*y<<" "<<x<<" "<<y<<"\n";

        /*if(x*y == 9){
            exit(0);
        }*/
        m = min(m, x*y);
    }


    for(int j=0; j<3; j++){
        if(!v[j]){
            v[j]=true;

            for(int l=0; l<esquina.size(); l++)
                for(int k=0; k<esquina.size(); k++){
                    if(k==l) continue;
                    if(esquina[k].first>esquina[l].first && esquina[k].second>esquina[l].second)
                        return;
                }
                //cout<<p.first<<" "<<p.second<<"\n";
            //cout<<"##\n";

            for(int k=0; k<esquina.size(); k++){
                long long ward = esquina[k].first;
                esquina[k].first += a[j];
                esquina.push_back({ward, esquina[k].second+b[j]});

                encontrar(i+1);

                esquina.pop_back();
                esquina[k].first -= a[j];
            }

            v[j]=false;
        }
    }

}

void permutar(int i=0){
    if(i==2){
        v[0]=v[1]=v[2]=false;
        encontrar();
        return;
    }
    for(int j=i; j<3; j++){
        swap(a[i], a[j]);
        swap(b[i], b[j]);
        permutar(i+1);
        swap(a[i], a[j]);
        swap(b[i], b[j]);
    }
}

void probar(int i=0){
    if(i==3){
        esquina.clear();
        esquina.push_back(make_pair(0, 0));
        permutar();
        /*for(int i=0; i<3; i++)
            cout<<a[i]<<","<<b[i]<<"\t";
        cout<<"\n";*/
        return;
    }
    probar(i+1);
    swap(a[i], b[i]);
    probar(i+1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        for(int i=0; i<3; i++){
            cin>>a[i]>>b[i];
        }

        x=y=0;
        m = LONG_MAX;
        probar();
        cout<<m<<"\n";
    }
    return 0;
}

/*
2
2 3 2 2 1 1
2 4 5 1 2 3

1
2 4 5 1 2 3

1
2 3 5 1 4 2

*/
