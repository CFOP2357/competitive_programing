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
vector<ull> x;
ull n;

void solve(){
    a.clear(); b.clear(); x.clear();
    cin>>n;

    map<ull, deque<ull>> nxt;

    for(int i=0; i<n; i++){
        ull z; cin>>z;
        nxt[z].push_back(i);
        x.push_back(z);
    }

    for(ull z : x){
        if(nxt[z].size())
            nxt[z].pop_front();

        if((bool)b.size() == (bool)a.size() && (!a.size() || a.back()==b.back() )){
            if(!a.size() || a.back()!=z)
                a.push_back(z);
        }
        else if(a.size() && a.back()==z){
            b.push_back(z);
        }
        else if(b.size() && b.back()==z){
            a.push_back(z);
        }
        else if(!b.size())
            a.push_back(z);
        else if(!a.size())
            b.push_back(z);
        else { //ninguno vacio frente no iguales, ninguno es igual a z
            if(!nxt[a.back()].size())
                b.push_back(z);
            else if(!nxt[b.back()].size())
                a.push_back(z);
            else if(nxt[a.back()].front() < nxt[b.back()].front())
                a.push_back(z);
            else
                b.push_back(z);
        }
    }

    cout<<a.size()+b.size()<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

