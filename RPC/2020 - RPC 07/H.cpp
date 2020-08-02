#include <bits/stdc++.h>
using namespace std;
#define MAX 105

vector <int> a;
int total[MAX];
int conjunto[MAX];


void solve(){
  int n; cin>>n;
  a.clear();
  a.resize(n+5);


  for(int i=1; i<=n; i++){
    cin>>a[i];
  }

  for(int k=1; k<=n; k++){
    //limpiar
    for(int i=1; i<=n; i++)
      conjunto[i]=total[i]=0;

    for(int i=1; i<=n; i++){
      if(conjunto[i]) continue;
      //if(k==3)cout<<i<<":\n";
      vector<int> b;
      b.clear();
      //Acomodar
      int last = a[i];
      b.push_back(i);
      for(int j=i; j>0; j--){
        if(a[i]<=a[j])continue;
        if(last>a[j]){
          last = a[j];
          b.push_back(j);
        }
        if(last==a[j]){
          if(!conjunto[j])
            b.back()=j;
        }
        else {
          last = a[j];
          b.back()=j;
        }
      }
      reverse(b.begin(), b.end());
      last = a[i];

      for(int j=i; j<=n; j++){
        if(a[i]<a[j]){
            //cout<<a[j]<<" ";
            if(last<a[j]){
              last = a[j];
              b.push_back(j);
            }
            if(last==a[j]){
              if(!conjunto[j])
                b.back()=j;
            }
            else {
              last = a[j];
              b.back()=j;
            }
        }

      }
       /* if(k==3){
            for(int ii : b)
              cout<<a[ii]<<" ";
            cout<<" || ";
        }*/

      if(b.size() < k )
        continue;
      int t=0;
      vector <int> realSet;
      for(int j : b){ //aber cuales puedo agarrar
        //if(k==3) cout<<a[j]<<"";
        if(!conjunto[j]){ //nadie lo tiene, pos lo agarro
          //if(k==3)cout<<"# ";
          t++;
          realSet.push_back(j);
          continue;
        }
        else if(total[conjunto[j]]>k){ //Me lo prestas?
          //if(k==3)cout<<"$ ";
          total[conjunto[j]]--; //aber prestamelo
          t++; //ya tengo mas
          realSet.push_back(j);
        }
        //else if(k==3)cout<<" ";
      }
      //if(k==3)cout<<"\n";


      if(t>=k){ //si se ajusta, agarro mis cosas
          total[i] = t;
          for(int j : realSet)
            conjunto[j] = i;
      }
      else { //no se ajusto, regreso lo que me prestaron
        for(int j : realSet)
          if(conjunto[j]) //alguien me lo prestaron
            total[conjunto[j]]++; //lo regreso
      }

    }
    //contar
    int s = 0;
    for(int i=1; i<=n; i++)
      if(conjunto[i])
        s++;
    cout<<s<<" ";
    //exit(0);
  }

  cout<<"\n";
}

int main(){
  int t; cin>>t;
  while(t--)
    solve();
  return 0;
}

/*
3
8
2 1 9 3 4 4 5 6
2
1 1
3
1 2 3


1
8
2 1 9 3 4 4 5 6
*/


