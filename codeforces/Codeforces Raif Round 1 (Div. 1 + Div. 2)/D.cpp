#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
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

#define MAX 1000100
#define MOD 1000000007

vector<int> row;
vector<int> column;
vector<ull> a;
ull n;

void solve(){

    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    row.assign(n+5, 0);
    column.assign(n+5, 0);

    vector<pair<int, int>> ans;

    int j = n-1, k = n-1;
    for(int i = n-1; i>=0; i--){
        while(j>i && (column[j] == 2 || column[j] == 0 || a[j]==1)) j--;
        while(k>i && (column[k] == 2 || column[k] == 0 || (column[k] == 1 && row[k]!=k+1))) k--;

        //cout<<i<<" "<<j<<" "<<k<<"\n";

        if(a[i] == 1){
            ans.push_back({i+1, i+1});
            column[i]++;
            row[i] = i+1;
        }
        else if(a[i] == 2){
            if(k==i){
                cout<<"-1\n";
                return;
            }

            ans.push_back({i+1, k+1});
            row[i] = k+1;
            column[i]++;
            column[k]++;

        }
        else if(a[i]==3){
            if(j==i){
                if(k==i){
                    cout<<"-1\n";
                    return;
                }
                ans.push_back({i+1, i+1});
                ans.push_back({k+1, i+1});
                row[i] = k+1;
                column[i]++;
                column[k]++;
            }
            else{
            ans.push_back({i+1, i+1});
            ans.push_back({j+1, i+1});
            row[i] = j+1;
            column[i]++;
            column[j]++;}
        }
    }

    cout<<ans.size()<<"\n";
    for(auto p : ans)
        cout<<p.second<<" "<<p.first<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

