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

vector<ull> a;
vector<ull> b;
map<string, long long int>mp;
ull n;

const ull dig = 10000000;

void solve(){
    cin>>n;

    cout.precision(1000);
    cout << fixed;

    bool todo = true;

    mp["pink"] = dig;
    while(n--){
      string a, b;
      cin>>b>>a;
      long double c;
      cin>>c;

      if(mp[a]){
        mp[b]= max(mp[b],(ull)(mp[a]*c));

        //piso mp[b] a 10^-7
        //mp[b]=(long double)10000000;
        //mp[b] = (long double)((long long)mp[b]) / (long double)10000000
        //floor
      }

      /*if(mp["blue"]>=dig*10){
        todo = false;
      }*/

    }

    /*
    1
    0.5 //0.5
    0.5 //0.2
    2  //0.4
    */
    if(!todo)
      cout<<"10.0000000\n";
    else
      cout<<min((long double)mp["blue"]/dig, (long double)10.0)<<"\n";

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
3
red pink 0.5
yellow red 0.5
blue yellow 2.0
*/
