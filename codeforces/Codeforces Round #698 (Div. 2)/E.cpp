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

typedef ull ll;

const ll inf = 0; //unit value
struct Node {

    static ll operation(ll a, ll b){
        return a+b;
    }

	Node *l = 0, *r = 0;
	ll lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = operation(l->val, r->val);
		}
		else val = v[lo];
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return operation(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x*(R-L+1), madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = operation(l->val, r->val);
		}
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset = x;
			else madd = x;
			val = x*(R-L+1);
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = operation(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

vector<ull> a;
vector<ull> b;
vector<int> selected;
ull n, q;

void solve(){
    a.clear(); b.clear();
    cin>>n>>q;
    string s; cin>>s;
    string f; cin>>f;

    vector<pii> segment;
    selected.assign(n, 0);
    while(q--){
        int l, r; cin>>l>>r;
        segment.push_back({l, r});
        selected[l-1] = max(r-l+1, selected[l-1]);
    }
    //cout<<"\n#\n";

    vector<ull> init; init.push_back(0);
    for(char c: f)
        init.push_back(c-'0');

    Node *st = new Node(init, 0, init.size());

    for(int i=1; i<=n; i++)
        cout<<st->query(i, i+1)<<" ";
    cout<<"$\n";

    reverse(all(segment));
    for(auto operation : segment){
        int l, r; l = operation.first; r = operation.second;
        int d = r-l+1;

        ull numberOfOnes = st->query(l, r+1);
        ull numberOfZeros = d-st->query(l, r+1);

        if(numberOfOnes == numberOfZeros){
            cout<<"NO#\n";
            return;
        }

        if(numberOfOnes > numberOfZeros)
            st->add(l, r+1, 1);
        else
            st->add(l, r+1, 0);

        //st->set(1, r+1, 0);
        cout<<l<<" "<<r<<"\n";
        for(int i=1; i<=n; i++)
            cout<<st->query(i, i+1)<<" ";
        cout<<"#\n";
    }

    int toAdd = 0;
    for(int i=0; i<n; i++){
        toAdd = max(toAdd, selected[i]);
        if(toAdd){
            selected[i] = 1;
            toAdd--;
        }
    }

    for(int i=0; i<s.size(); i++){
        if(selected[i] && st->query(i+1, i+2) != s[i]-'0'){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

