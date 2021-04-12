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
    a.clear(); b.clear();
    cin>>n>>k;

    map<char, int> nxt;
    map<pair<char, char>, int> selected;

    cout<<'a';
    char last = 'a';

    n--;
    while(n--){
        char p = (char)(nxt[last]+'a');

        if(p >= (k+'a')){
            selected.clear();
            nxt.clear();
            p='a';
        }

        if(nxt[p] >=k){
            while(nxt[p]>=k){
                p++;

                if(p>=(k+'a'))
                    p='a';
            }

        }

        if(selected[{last, p}]){

            char c = p;

            p = 'a';
            while(selected[{last, p}] && p<('a'+k)){
                p++;
            }

            if(p>=(k+'a'))
                p=c;
        }

        cout<<p;
        selected[{last, p}]++;

        if(last == k+'a'-1 && p == 'a'){
            selected.clear();
            nxt.clear();
        }

        nxt[last]++;
        last = p;
    }
    cout<<"\n";

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

