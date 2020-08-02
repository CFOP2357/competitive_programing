#include <bits/stdc++.h>
using namespace std;
#define MAX 105

vector <int> a;
int total[MAX];
int conjunto[MAX];
vector <pair<int, int>> seg; //last, first

void solve(){
  int n; cin>>n;
  a.clear();
  a.resize(n+5);


  for(int i=1; i<=n; i++){
    cin>>a[i];
  }

  for(int k=1; k<=n; k++){
    seg.clear();
    //limpiar
    for(int i=1; i<=n; i++)
      conjunto[i]=total[i]=0;
      cout<<"\n";
    cout<<k<<":\n";
    for(int i=1; i<=n; i++){
      int p = 1;
      int last = a[i];
      int j;
      //cout<<a[i]<<" ";
      for(j = i+1; j<=n && p<k; j++){
        if(a[i]<a[j]){
            //cout<<a[j]<<" ";
            if(last<a[j]){
              last = a[j];
              p++;
            }
            else {
              last = a[j];
            }
        }
      }//cout<<"\n";
      //cout<<i<<" "<<j<<"\n";
      if(p==k)
        seg.push_back(make_pair(j-1, i));
    }
    //contar
    sort(seg.begin(), seg.end());
    if(seg.size()){
        int s = 1;
        int last = seg[0].first;
        for(pair<int, int> p : seg){
            cout<<a[p.second]<<" "<<a[p.first]<<"\n";
            if(p.second > last){
                last = p.first;
                s+= k;
            }
        }
        cout<<s<<" ";
    }
    else cout<<0<<" ";
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



