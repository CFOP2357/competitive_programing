#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int k;
    string a;
    string name;
    bool soup;
    bool pan;

    cin>>n;
    while(n--){
        cin>>k;
        getline(cin, a);
        getline(cin, name);
        soup=false;
        pan = false;
        while(k--){
            getline(cin, a);
            if(a== "pea soup")
                soup=true;
            if(a== "pancakes")
                pan=true;
        }
        if(pan && soup){
            //cin.clear();
            cout<<name<<"\n";
            return 0;
        }
    }
    cout<<"Anywhere is fine I guess\n";
    //while(true);
}
