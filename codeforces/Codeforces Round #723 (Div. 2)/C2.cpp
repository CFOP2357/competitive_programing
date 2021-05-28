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

#define MAX 200010
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

struct Tree {
	typedef ull T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a+b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};
Tree sum(MAX);
map<ull, ull> last;

int update(int i, ull &val){
    if(val<=sum.query(i, i+1)){
        sum.update(i, sum.query(i, i+1)-val);
        val = 0;
        return i;
    }
    if(sum.query(i, i+1) > 0){
        val -= sum.query(i, i+1);
        sum.update(i, 0);
    }
    return last[i] = update(last[i], val);
}

void solve(){
    a.clear(); b.clear();
    cin>>n;
    priority_queue<pii, vector<pii>, greater<pii>> nxt; //val, pos

    ull ans = 0;
    ull current_last = 0;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        last[i+1] = current_last;
        if(z>=0){
            sum.update(i+1, z);
            current_last = i+1;
            ans++;
        }
        else{
            nxt.push({abs(z), i+1});
        }
    }

    while(nxt.size()){
        int pos = nxt.top().second;
        ull val = nxt.top().first;
        nxt.pop();
        //cout<<pos<<" "<<val<<"\n";

        if(sum.query(0, pos)-val >= 0){
            update(pos, val);
            ans++;
        }

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

