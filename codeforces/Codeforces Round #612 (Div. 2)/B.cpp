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

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m, k;
string s;

void solve(){

    cin>>n>>k;

    vector<string> features;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        features.push_back(s);
    }

    ull ans = 0;
    unordered_map<string, ull> frequency;
    for(int i=0; i<n; i++){ //E S T

        for(int j=i+1; j<n; j++){
            string complement;

            for(int f = 0; f<k; f++)
                if(features[i][f] == features[j][f])
                    complement += features[i][f];
                else{

                    char a = features[i][f], b = features[j][f];
                    if(a>b)
                        swap(a, b);

                    if(a=='E'){
                        if(b=='S')
                            complement += 'T';
                        else
                            complement += 'S';
                    }
                    else
                        complement += 'E';

                }

            ans += frequency[complement];
        }

        frequency[features[i]]++;
    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

