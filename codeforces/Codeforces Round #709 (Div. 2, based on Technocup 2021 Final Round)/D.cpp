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

#include <list>

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

list<pii> a; //val, pos

ull n, m;
string s;

void solve(){
    a.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back({z, i+1});
    }

    queue<list<pii>::iterator> next;
    queue<int> nextPos;
    vector<int> ans;

    map<int, bool> erased;

    for(auto current = a.begin(); current!=a.end() && n>1; current++){

        auto sig = current; sig++;

        if(sig==a.end())
            sig=a.begin();

        if(__gcd(sig->first, current->first) == 1){

            erased[sig->second] = true;

            ans.push_back(sig->second);
            a.erase(sig);
            next.push(current);
            nextPos.push(current->second);
            n--;
            //erased[sig] = true;
        }

    }

    while(next.size() && n>1){
        int ss = nextPos.front();
        nextPos.pop();

        if(erased[ss]){
            next.pop();
            continue;
        }

        auto current = next.front();
        next.pop();


        if(current == a.end())
            current = a.begin();

        auto sig = current; sig++;
        if(sig==a.end())
            sig=a.begin();

        if(__gcd(current->first, sig->first) == 1){
            erased[sig->second] = true;
            ans.push_back(sig->second);
            a.erase(sig);
            next.push(current);
            nextPos.push(current->second);
        }

    }
    if(n==1 && a.begin()->first == 1){
        ans.push_back(a.begin()->second);
    }

    cout<<ans.size()<<" ";
    for(int k : ans)
        cout<<k<<" ";
    cout<<"\n";
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

/*
1
6
1 2 4 2 4 2
*/

