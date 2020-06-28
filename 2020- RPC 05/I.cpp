#include <bits/stdc++.h>
#define MAX 105

using namespace std;

string bad[MAX];
int n, m;

bool valid(string a){
    for(int i=0; i<n; i++){
        for(int j=0; j<a.size(); j++){
            if(a.substr(j, bad[i].size())==bad[i])
                return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>bad[i];
    string a;
    while(m--){
        cin>>a;
        for(int i=0; i<a.size(); i++){
            if(a[i]>='0' && a[i]<='9'){
                switch (a[i]){
                    case '0':
                        a[i]='O';
                    break;
                    case '1':
                        a[i]='L';
                    break;
                    case '2':
                        a[i]='Z';
                    break;
                    case '3':
                        a[i]='E';
                    break;
                    case '5':
                        a[i]='S';
                    break;
                    case '6':
                        a[i]='B';
                    break;
                    case '7':
                        a[i]='T';
                    break;
                    case '8':
                        a[i]='B';
                    break;
                }
            }
        }
        if(valid(a))
            cout<<"VALID\n";
        else
            cout<<"INVALID\n";
    }
    return 0;
}

/*
7 2
AWFUL
BAD
CRUMMY
LOL
POOR
SAD
TERRIBLE
TROUBADOUR
101E10K
*/
