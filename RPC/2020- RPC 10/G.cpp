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

ull n;

int visited[1005];

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const deque<int>& a, const deque<int>&b) const
  {
    if(a.size()==1 || b.size() == 1)
        return !(a.size()==1);

    int da = 0, db = 0;
    for(int i = 0; i<a.size(); i++){
        da += !visited[a[i]];
    }
    for(int i = 0; i<b.size(); i++){
        db += !visited[b[i]];
    }

    if(da == 1 || db == 1)
        return !(da==1);

    if(a.front()!=b.front())
        return !(a.front()<b.front());

    return da>db;
  }
};
/*
6
1 2 3 6
1 2 3 7


6
1 2 3 6
1 2 3 7

6 7
6
*/

vector<deque<int>> times;

void solve(){

    cin>>n;

    for(int i=0; i<n; i++){
        int t; cin>>t;
        while(t--){
            int z; cin>>z;
            if(!visited[z])
                visited[z] = i+1;
        }
    }

    map<int, bool> mp;

    int c = 0;
    for(int i=1; i<=1000; i++){
        if(visited[i] && !mp[visited[i]]){
            c++;
            mp[visited[i]] = true;
        }
        if(c==n){
            cout<<i+1<<"\n";
            exit(0);
        }
    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

/*
5
3 1 2 3
2 2 3
1 3
4 1 2 3 4
4 1 2 3 5

4
2 1 3
2 1 2
3 1 4 10
2 1 2

4
4 1 2 3 20
4 1 2 3 30
3 2 3 7
2 3 4

4
2 3 11
3 2 9 11
2 2 3
2 3 9

3
2 4 6
3 4 9 11
1 4

5
1 1
2 1 2
2 1 3
2 1 4
1 30

4
2 1 2
3 1 2 5
3 1 2 4
3 1 3 4


4
2 1 2
1 1
2 2 4
2 2 5

3
2 1 6
2 1 10
1 10

*/
