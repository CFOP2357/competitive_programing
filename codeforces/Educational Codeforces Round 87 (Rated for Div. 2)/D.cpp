#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define all(a) a.begin(), a.end()

typedef int32_t ull;

#define MAX 1000002
#define MOD 1000000007

struct Tree {
	typedef int32_t T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b; } // (any associative fn)
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
	int findK(int k){
	    int b = 0;
		while (b < n) {
			if(s[b] >= k)
                b = b*2;
            else{
                b = b*2+1;
            }
		}
		return b-n;

	}
};

ull n, q;

void solve(){

    cin>>n>>q;

    Tree mst(MAX);

    cout<<mst.query(0, MAX)<<"\n";

    for(int i=0; i<n; i++){
        ull z; cin>>z;
        mst.update(z, 1);
    }

    cout<<mst.query(0, n)<<"\n";

    int k;
    while(q--){
        cin>>k;
        if(k>0)
            mst.update(k, mst.query(k, k+1)+1);
        else{
            int element = mst.findK(abs(k));
            cout<<element<<"\n";
            mst.update(element, mst.query(element, element+1)-1);
        }
        //cout<<mset.size()<<"\n";
    }

    int ans = mst.findK(1);

    if(mst.query(0, n)==0)
        cout<<"0\n";
    else cout<<ans<<"\n";

}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

