#include <bits/stdc++.h>
using namespace std;

vector <string> name;
vector <int> f;
typedef pair<int, int> pi;

void solve(){
  int n, k; cin>>n>>k;
  name.clear();
  f.clear();
  priority_queue<pi, vector<pi>, greater<pi>> next; //time, id

  for(int i=0; i<n; i++){
    string name;
    int f;
    cin>>name>>f;
    ::name.push_back(name);
    ::f.push_back(f);
    next.push({f, i});
  }

  while(k--){
    auto p = next.top();
    cout<<p.first<<" "<<name[p.second]<<"\n";
    next.pop();
    next.push({p.first + f[p.second], p.second});
  }


}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t; cin>>t;
  while(t--){
    solve();
  }
}
