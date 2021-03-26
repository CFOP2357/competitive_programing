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

vector<ull> sizeSequence;

ull n, m;
string s;

void minimum(){

    int k = n;
    for(int i=0; i<sizeSequence.size(); i++){

        vector<int> ans;

        for(int j=0; j<sizeSequence[i]; j++)
            ans.push_back(k--);

        reverse(all(ans));

        for(int a : ans)
            cout<<a<<" ";

    }
    cout<<"\n";

}

void maximum(){

    vector<int> ans;

    int k = n, p = 1;;
    for(int i=sizeSequence.size()-1; i>=0; i--){

        for(int j=1; j<sizeSequence[i]; j++)
            ans.push_back(k--);

        ans.push_back(p++);
    }

    reverse(all(ans));

    for(int a : ans)
        cout<<a<<" ";
    cout<<"\n";

}

void solve(){

    sizeSequence.clear();

    cin>>n>>s;

    sizeSequence.push_back(1);


    for(char c : s)
        if(c != '>'){
            sizeSequence.back()++;
        }
        else{
            sizeSequence.push_back(1);
        }

    minimum();
    maximum();
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

