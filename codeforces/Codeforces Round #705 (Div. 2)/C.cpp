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

map<char, int> times_;

void countTimes(){
    times_.clear();
    for(char c : s)
        times_[c]++;
}

bool isCorrect(){
    countTimes();

    for(char c='a'; c<='z'; c++)
        if(times_[c]%k)
            return false;
    return true;

}

void solve(){

    cin>>n>>k;
    cin>>s;

    if(n%k){
        cout<<"-1\n";
        return;
    }

    for(&& !isCorrect(); c--){

        string last = s;
        if(times_[c]%k){

            for(int i=n-1; i>=0; i--){
                if(times_[s[i]]%k && s[i]<c)
                    s[i]=c;
            }

        }

        s = max(s, last);

    }

    if(isCorrect())
        cout<<s<<"\n";
    else
        cout<<"-1\n";
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

