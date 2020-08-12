    #include <bits/stdc++.h>
    using namespace std;

    #define MOD 1000000007

    typedef long long ull;

    vector<ull> a;
    vector<ull> b;
    #define MAX 110

    bool visited[MAX][MAX];

    int n, m;

    void solveLine(int x, int y){
        visited[x][y] = true;
        cout<<y+1<<" "<<x+1<<"\n";
        int lastX = x;
        for(x=0; x<m; x++){
            if(!visited[x][y]){
                cout<<y+1<<" "<<x+1<<"\n";
                visited[x][y] = true;
                lastX = x;
            }
        }
        x = lastX;
        for(int y=0; y<n; y++){
            if(!visited[x][y]){
                solveLine(x, y);
                return;
            }
        }

    }

    void solve(){
        int x, y;
        cin>>n>>m>>y>>x;
        solveLine(x-1, y-1);
    }


    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
        while(t--){
            solve();
        }
        return 0;
    }
