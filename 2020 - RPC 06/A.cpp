#include <bits/stdc++.h>
using namespace std;

set<string> posible[250];
vector<string> name[250];
int palabras[250];

string ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string prev;
    cin>>prev;
    int n;
    cin>>n;
    string ans = "";
    char last = prev[prev.size()-1];
    while(n--){
        string a; cin>>a;
        posible[a[0]].insert(a);
        name[a[0]].push_back(a);
        if(a[0] == last && ans =="")
            ans = a;
        palabras[a[0]]++;
    }

    if(posible[last].empty()){
        cout<<"?\n";
        return 0;
    }

    for(string a : name[last]){
        posible[last].erase(a);

        palabras[a[0]]--;

        if(!palabras[a[a.size()-1]]){
            cout<<a<<"!\n";
            return 0;
        }

        palabras[a[0]]++;
    }

    cout << ans <<"\n";

    return 0;
}

/*
dog
4
rso
gemu
unicornio
gato

hare
4
bee
cat
eagle
eagle

hare
3
bee
cat
eagle


a
2
b
a

perro
1
oso
olio
obo
oko

pigt
2
goat
toadg

*/
