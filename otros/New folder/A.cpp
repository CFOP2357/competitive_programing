#include <bits/stdc++.h>
using namespace std;

char ans[300];

int main(){
    string a;
    cin>>a;
    for(char i='a'; i<='z'; i++) ans[i] = i;
    for(char i='A'; i<='Z'; i++) ans[i] = i;
    ans['_'] = '_';
    ans['o'] = ans['O'] = '0';
    ans['i'] = ans['I'] = '1';
    ans['z'] = ans['Z'] = '2';
    ans['e'] = ans['E'] = '3';
    ans['a'] = ans['A'] = '4';
    ans['s'] = ans['S'] = '5';
    ans['g'] = ans['G'] = '6';
    ans['t'] = ans['T'] = '7';
    ans['b'] = ans['B'] = '8';

    for(char c : a)
        cout<<ans[c];
    cout<<"\n";
    return 0;
}
