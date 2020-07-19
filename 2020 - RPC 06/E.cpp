#include <bits/stdc++.h>

using namespace std;

vector <string> name;
vector <string> team[2];
int pasos;
int n;

int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
  string a; getline(cin, a);
  //cout<<a<<"\n";
  for(char c : a)
    pasos += c==' ' ;
  pasos++;
  //cout<<pasos<<"##\n";

  cin>>n;
  for(int i=0; i<n; i++){
    cin>>a;
    name.push_back(a);
  }

  int current = 0;
  for(int i=0; n--; i = (i+1)%2){
    current = (pasos+current-1)%name.size();
    team[i].push_back(name[current]);
    name.erase(name.begin()+current);
  }

  for(int i=0; i<2; i++){
    cout<<team[i].size()<<"\n";
    for(string s : team[i])
      cout<<s<<"\n";
  }

  return 0;
}







