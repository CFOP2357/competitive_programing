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

#define MAX 1000010
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


int n;

void solve(){
    vector<pii> segments;

    cin>>n;
    for(int i=1; i<=n; i++){
        int l, r; cin>>l>>r;
        segments.push_back({l, r});
    }
    sort(all(segments));

    int sz = 0;
    UF uf(n+5);
    set<pii> R; //r, idx
    for(int i=0; i<n and sz<n; i++){
        auto segment = segments[i];
        while(R.size() and R.begin()->first < segment.first)
            R.erase(R.begin());
        auto it = R.begin();
        while(it!=R.end() and it->first < segment.second){
            uf.join(i, it->second);
            sz++;
            it++;
        }
        R.insert({segment.second, i});
    }

    if(sz!=n-1){
        cout<<"NO\n";
        return;
    }

    int S = uf.find(0);
    for(int i = 0; i<n; i++){
        if(uf.find(i)!=S){
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
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

