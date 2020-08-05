#include <bits/stdc++.h>
using namespace std;
#define MAX 100005



vector <pair<long long, long long>> g[MAX]; //w, v
vector <pair<long long, long long>> arista; //pesoReal, cantidad hojas

class compare
{
  bool reverse;
public:
  compare(const bool& revparam=false)
    {reverse=revparam;}
  bool operator()(pair<long long, long long> a, pair<long long, long long> b) const{
    long long sA = a.first - (arista[a.second].first/2)*arista[a.second].second;
    long long sB = b.first - (arista[b.second].first/2)*arista[b.second].second;
    if(sA!=sB)
        return sA<sB;
    return a<=b;
  }
};

priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, compare> edge; //peso, id
bool visited[MAX];
long long n, S;
long long realS;

long long dfs(int v){//regresa la cantidad de hojas
    if(visited[v])
        return 0;
    visited[v] = true;

    if(g[v].size()==1 && v!=1)
        return 1;

    long long totalL = 0;
    long long l = 0;
    for(pair<long long, int> next : g[v]){
        l = dfs(next.second);
        if(!l)
            continue;
        totalL+=l;
        arista.push_back(make_pair(next.first, l));
        realS+=next.first*l;
    }
    return totalL;
}

void solve(){
    int n;
    cin>>n>>S;
    realS=0;
    arista.clear();
    for(int i=1; i<=n; i++){
        visited[i]=false;
        g[i].clear();
    }
    for(int i=1; i<n; i++){
        long long u, v, w;
        cin>>u>>v>>w;
        g[u].push_back( make_pair(w, v));
        g[v].push_back( make_pair(w, u));
    }

    dfs(1);

    //cout<<realS<<"#\n";

    for(long long id = 0; id<arista.size(); id++){
        edge.push( make_pair( arista[id].first*arista[id].second, id ) );
        //cout<<arista[id].first*arista[id].second<<"<<\n";
    }

    long long m = 0;
    while(realS > S){
        pair<long long, long long> a = edge.top();
        edge.pop();
        long long id = a.second;
        if(arista[id].first){
            //cout<<arista[id].first<<" ";
            realS -= arista[id].first*arista[id].second;
            arista[id].first/=2;
            realS += arista[id].first*arista[id].second;
            //cout<<realS<<"#\n";
            edge.push( make_pair( arista[id].first*arista[id].second, id ) );
            m++;
        }
    }
    while(edge.size())edge.pop();
    cout<<m<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }

}
/*
1
7 8
1 2 3
1 3 3
2 4 4
2 5 4
3 6 4
3 7 4

1
7 20
1 2 3
1 3 3
2 4 4
2 5 4
3 6 4
3 7 4

1
5 10
2 1 3
3 2 20
4 3 1
5 3 1

1
5 10
2 1 3
3 2 20
4 3 1
5 3 1

1
5 0
2 1 3
3 2 20
4 3 1
5 3 1

1
10 28
8 2 8
5 1 4
6 1 10
10 2 7
7 2 1
9 2 1
2 1 5
4 1 9
3 2 5
*/
