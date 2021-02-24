#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>

#include <map>
#include <set>

#include <stack>
#include <queue>

#include <unordered_map>
#include <unordered_set>

#include <time.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define all(a) a.begin(), a.end()

typedef long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 300100
#define MOD 1000000007

vector<ull> a[MAX];
ull n, m;

vector<vector<ull>> possibleAns;
vector<ull> ans;

vector<ull> mstk;
ull differentElements(int i){
    mstk.clear();

    ull sz = 0;
    for(int j=0; j<m; j++)
        if(ans[j]!=a[i][j]){
            sz++;
            mstk.push_back(j);
        }
    return sz;
}

void tryPossibleAns(){

    for(auto ans : possibleAns){

        ::ans = ans;

        bool isAns = true;
        for(int i=0; i<n; i++){

            if(differentElements(i)>2)
                isAns=false;

        }

        if(isAns){
            cout<<"Yes\n";
            for(ull k : ans){
                cout<<k<<" ";
            }
            cout<<"\n";
            exit(0);
        }

    }

}

void solve(){

    srand (time(NULL));

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ull z; cin>>z;
            a[i].push_back(z);
        }
    }

    for(int h = 3; h>=0; h--){
        ans = a[rand()%n];

        for(int i=0; i<n; i++){

            ull d = differentElements(i);

            if(d>4){
                cout<<"NO\n";
                return;
            }

            if(d==4){

                possibleAns.clear();
                for(int j : mstk){

                    for(int k : mstk){
                        possibleAns.push_back(ans);
                        possibleAns.back()[j] = a[i][j];
                        possibleAns.back()[k] = a[i][k];
                    }

                }

                tryPossibleAns();

                cout<<"No\n";
                return;

            }

        }
    }

    ans = a[rand()%n];

    for(int i=0; i<n; i++){

        ull d = differentElements(i);

        if(d>4){
            cout<<"NO\n";
            return;
        }

        if(d>2){

            possibleAns.clear();
            for(int j : mstk){
                possibleAns.push_back(ans);
                possibleAns.back()[j] = a[i][j];

                for(int k : mstk){
                    possibleAns.push_back(ans);
                    possibleAns.back()[j] = a[i][j];
                    possibleAns.back()[k] = a[i][k];
                }

            }

            tryPossibleAns();

            cout<<"No\n";
            return;

        }

    }

    cout<<"Yes\n";
    for(ull k : ans)
        cout<<k<<" ";
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

