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

vector<ull> redValue;
vector<ull> blueValue;
ull n;

void solve(){
    redValue.clear(); blueValue.clear();

    cin>>n;
    string redValue; cin>>redValue;
    string blueValue; cin>>blueValue;

    int timesRedIsHigher(0), timesBlueIsHigher(0);

    for(int i=0; i<n; i++){

        if(redValue[i]>blueValue[i])
            timesRedIsHigher++;
        else if(redValue[i]<blueValue[i])
            timesBlueIsHigher++;

    }

    if(timesRedIsHigher > timesBlueIsHigher)
        cout<<"RED\n";
    else if(timesRedIsHigher < timesBlueIsHigher)
        cout<<"BLUE\n";
    else cout<<"EQUAL\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

