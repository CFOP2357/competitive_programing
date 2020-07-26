#include <bits/stdc++.h>
using namespace std;

#define MAX 100005

string a[MAX];
int n;

bool compare(string a, string b){
    string a1 = a+b;
    string b1 = b+a;
    return a1>b1;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<n; i++){

        sort(a[i].begin(), a[i].end(), greater<char>());

    }


    sort(a, a+n, compare);


    for(int i=0; i<n; i++)
        cout<<a[i];
    cout<<"\n";


    return 0;
}

