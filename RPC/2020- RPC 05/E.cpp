#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    if(n%2){ //impar
        cout<<"Either\n";
    }
    else { //par
        bool impar = 1;
        for(int i=2; i<n; i+=2)
            impar = !impar;
        if(impar)
            cout<<"Odd\n";
        else
            cout<<"Even\n";
    }
    return 0;
}
