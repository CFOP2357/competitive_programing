#include <bits/stdc++.h>

using namespace std;

bool chan[100005];

int main(){
    int n;
    string a, b;
    cin>>n;
    cin>>a>>b;
    if(a==b){
        cout<<"yes";
        return 0;
    }
    char seg = b[0];
    bool completed = b[0]==a[0];
    bool pos =true;
    for(int i=1; i<n; i++){
        if(seg!=b[i] && !completed){
            pos = false;
        }
        if(a[i]==seg) completed = true;
        if(a[i]!=b[i]){
            completed=false;
            seg = b[i];
        }
    }
    //if()
    if(pos){
        cout<<"yes\n";
        return 0;
    }
    seg = b[n-1];
    completed = b[n-1]==a[n-1];
    pos=true;
    for(int i=1; i<n; i++){
        if(seg!=b[i] && !completed){
            pos = false;
        }
        if(a[i]==seg) completed = true;
        if(a[i]!=b[i]){
            completed=false;
            seg = b[i];
        }
    }
    if(!pos)
        cout<<"no\n";
    else cout<<"yes\n";
    return 0;
}
