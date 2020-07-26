#include <bits/stdc++.h>
using namespace std;

int a[505];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int m, n;
    cin>>m;

    for(int i=0; i<m; i++)
        cin>>a[i];

    int n;

    int k=-1;
    for(int i=0; i<n; i++){
        while(true){
            k++;
            string a = to_string(a);
            string b = to_string(k);

            bool match = true;
            for(int j=0; j<a.size(); j++){
                for(int p=0; p<b.size(); p++)
            }
        }
    }
    cout<<k<<"\n";



    return 0;
}

