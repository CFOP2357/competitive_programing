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

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

void solve(){
    a.clear(); b.clear();
    vector<ull> ans;
    cin>>n;
    UF uf(n+5);
    map<ull, bool> selected;
    set<ull> avaiable;
    for(int i=1; i<=n; i++)
        avaiable.insert(i);

    for(int i=1; i<n; i++){
        ull z; cin>>z;

        ull d = z;
        if(selected[z] or uf.sameSet(i, z)){

            auto p = avaiable.begin();
            /*cout<<"\n&";
            cout<<*p<<" ";
            cout<<selected[*p]<<" "<<uf.sameSet(*p, i)<<"\n";*/
            while(selected[*p] or uf.sameSet(*p, i)){
                p++;
            }
            //cout<<"%%";
            d=*p;

        }

        //cout<<"#"<<i<<" "<<d<<"\n";

        uf.join(i, d);
        avaiable.erase(d);
        selected[d]=true;
        ans.push_back(d);
    }
    ull z; cin>>z;

    ans.push_back(*avaiable.begin());

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
        if(i<ans.size()-1)
            cout<<" ";
    }
    cout<<"\n";

}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

