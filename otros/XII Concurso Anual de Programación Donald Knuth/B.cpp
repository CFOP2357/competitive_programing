#include <bits/stdc++.h>
using namespace std;

#define MAX 100005


int R[MAX];
int G[MAX];
int B[MAX];
int Y[MAX];


string a;

int beauty(int left, int right){ //[]
    right++;
    int M = INT_MIN, m = INT_MAX;
    M = max(M, R[right]-R[left]);
    M = max(M, G[right]-G[left]);
    M = max(M, B[right]-B[left]);
    M = max(M, Y[right]-Y[left]);
    m = min(m, R[right]-R[left]);
    m = min(m, G[right]-G[left]);
    m = min(m, B[right]-B[left]);
    m = min(m, Y[right]-Y[left]);
    return M-m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int minDif=INT_MAX;

    cin >> a;

    for(int i=0; i<a.size(); i++){
        if(a[i]=='R')
            R[i+1]++;
        if(a[i]=='G')
            G[i+1]++;
        if(a[i]=='B')
            B[i+1]++;
        if(a[i]=='Y')
            Y[i+1]++;

        R[i+1]+=R[i];
        G[i+1]+=G[i];
        B[i+1]+=B[i];
        Y[i+1]+=Y[i];
    }

    for(int i=0; i<a.size(); i++)
        for(int j=0; j+i<a.size(); j++){
            minDif = min(beauty(j, j+i), minDif);
        }

    for(int i=a.size()-1; i>=0; i--)
        for(int j=0; j+i<a.size(); j++){
            if(minDif == beauty(j, j+i)){
                cout<<minDif<<" "<<i+1<<"\n";
                cout<<j+1<<" "<<j+i+1<<"\n";
                return 0;
            }
        }


    return 0;
}
