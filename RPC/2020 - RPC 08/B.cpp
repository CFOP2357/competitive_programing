#include <bits/stdc++.h>
using namespace std;
#define MAX 1000100

vector <int> a;
int n, q;
int segT[MAX][25];

void mergeSort(int l, int r, int d = 0){ //[l, r]
    if(l==r){
        segT[l][d] = a[l];
        return;
    }
    int m = (l+r)/2;
    mergeSort(l, m, d+1);
    mergeSort(m+1, r, d+1);
    merge(&segT[l][d+1], &segT[m][d+1], &segT[m+1][d+1], &segT[r][d+1], &segT[l][d]);
}

void query(){
    int l, r, k;
    cin>>l>>r>>k;

}


int main(){

    while(cin>>n>>q){
        a.clear();
        for(int i=0; i<n; i++){
            int a; cin>>a;
            ::a.push_back(a);
        }
        mergeSort(0, n-1);
        while(q--) query();
    }
}
