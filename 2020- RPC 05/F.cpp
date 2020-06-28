#include <bits/stdc++.h>

using namespace std;

int ABC[30];
int fib[40];

int main(){
    string s;
    getline(cin, s);
    int letters=0;
    for(char c:s){
        if(c>='a' && c<='z'){
            ABC[c-'a']++;
            letters++;
        }
        if(c>='A' && c<='Z'){
            ABC[c-'A']++;
            letters++;
        }
    }

    /*for(int i=0; i<'z'-'a'+1; i++){
        cout<<(char)(i+'a')<<" "<<ABC[i]<<"\n";
    }*/

    sort(ABC, ABC+30);

    int i=29;

    int a=1, b=2;
    fib[0]=1;
    fib[1]=2;
    for(int j=2; j<30; j++){
        fib[j] = fib[j-1]+fib[j-2];
    }

    int dash = 3;
    int point = 1;
    int total = 0;
    for(int j=0; i>=0; j++){
        //cout<<j<<" ";
        //cout<<fib[j]<<" "<<j*2+1<<" ";
        for(int k=0; k<fib[j] && i>=0; k++, i--){
            //cout<<total<<" ";
            total+=ABC[i]*(j*2+1);
            //cout<<i+'a'<<" ";
            //cout<<ABC[i]<<" ";
            //cout<<j*2+1<<"\n";
        }
        //cout<<"\n";
    }
    //cout<<letters;
    //cout<<"\n";

    if(letters)
        total+=(letters-1)*3;

    cout<<total<<"\n";
    return 0;
}
/*
The quick brown dog jumps over the lazy fox.

*/
