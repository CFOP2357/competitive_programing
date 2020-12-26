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

#define MAX 200100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

struct TreeMin {
	typedef ull T;
	static constexpr T unit = LLONG_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	TreeMin(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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

//abs(LLONG_MIN) = LLONG_MAX-1

struct TreeMax {
	typedef ull T;
	static constexpr T unit = LLONG_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	TreeMax(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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

TreeMin st_min(MAX);
TreeMax st_max(MAX);

bool print = false;
int lastPositionFromlWhereMinIsX(int l, int r, ull x, const int i){ //[l, r)

  /*if(print)
    cout<<l<<" "<<r<<"$\n";*/

  if(l+1>=r){
    /*if(print){
      print = false;
      cout<<st_min.query(i+1, l+1)<<"\n";
    }*/
    if(st_min.query(i+1, l+1) == x)
      return l;
    return -1;
  }

  int m = (l+r)/2;

  /*if(print)
    cout<<m<<" "<<st_min.query(i+1, m+1)<<"\n";*/

  if(st_min.query(i+1, m+1) >= x)
    return lastPositionFromlWhereMinIsX(m, r, x, i);
   return lastPositionFromlWhereMinIsX(l, m, x, i);

}


int lastPositionButLastWhereMaxIsX(int l, int r, ull x){ //(l, r]
  if(print)
    cout<<l<<" "<<r<<"$\n";

  if(l+1>=r){
    if(print){
      print = false;
      cout<<st_min.query(r, n)<<"\n";
    }

    if(st_max.query(r, n) == x)
      return r;
    return -1;
  }

  int m = (l+r)/2;

  if(print)
    cout<<m<<" "<<st_max.query(m, n)<<"\n";

  if(st_max.query(m, n) <= x)
    return lastPositionButLastWhereMaxIsX(l, m, x);
   return lastPositionButLastWhereMaxIsX(m, r, x);

}

const int cs = -2;

void solve(){
    //lectura
    a.clear();
    cin>>n;
    for(int i = 0; i < n; i++){
        ull z;
        cin>>z;
        a.push_back(z);
    }
    //crear segment de min
    for(int i = 0; i < n; i++)
      st_min.update(i, a[i]);
    //crear segment de max
    for(int i = 0; i < n; i++)
      st_max.update(i, a[i]);

    ull actmax = -(INT_MAX - 1);

    // oooooooooooooooooooooooooooooo
    for(int i = 0; i < n; i++){

        /*if(i==1){
            print = true;
            cout<<i<<" "<<n-1<<"\n";
        }*/

        actmax = max(actmax, a[i]);
        int x, y, z;
        x = i+1;

        y = lastPositionFromlWhereMinIsX(i+1, n, actmax, i);
        int yPos = y;
        if(y==-1)
            continue;
        y -= i;

        z = lastPositionButLastWhereMaxIsX(i, n-1, actmax);
        int zPos = z;
        if(z==-1)
            continue;
        z = n - z;

        if(i==cs){
          cout<<y<<" "<<z<<" | "<<yPos<<" "<<zPos<<"#\n";
        }

        //max(1,x)=min(x+1,x+y)=max(x+y+1,n)

        if(y > 0 and z > 0 and x + y + z > n){
            if(i==cs) cout << "validacion\n";

            int l = zPos;
            int r = yPos + 1;
            int m = (zPos + yPos) / 2;

            int mn = -1;
            int mx = -1;

            //>>>>>>===<<<<<<<<<<<<<
            //>>>>>>>>>>>>>>>>><<<<<<<<<<<<
            //=======================
            while(l+1 < r){
                int m = (l+r)/2;

                mn = st_min.query(x, m);
                //mx = st_max.query(m, n);

                if(mn >= actmax){
                    l = m;
                }
                else{
                    r = m;
                }

            }
            if(i==cs)cout << x << ' ' << l+1 << "##\n";

            //>>>>===<<
            //>>>======

            /*if(l==n-1 || st_min.query(x, l+2)<actmax)
              l--;*/

            mn = st_min.query(x, l+1);
            if(i==cs)cout << mn << "##\n";

            mx = st_max.query(l+1, n);
            if(i==cs)cout << mx << "##\n";


            if(mx == actmax && mn == actmax){
              y = l - i;
              z = n - l - 1;
            }
            else {
              l--;
              mn = st_min.query(x, l+1);
              if(i==cs)cout << mn << "##\n";
              if(mn != actmax)
                  continue;
              mx = st_max.query(l+1, n);
              if(i==cs)cout << mx << "##\n";
              if(mx != actmax)
                continue;

              y = l - i;
              z = n - l - 1;
            }
        }

        if (y > 0 and z > 0 and x + y + z == n){
            cout << "YES\n";
            cout << x << ' ';
            cout << y << ' ';
            cout << z << '\n';
            return;
        }
    }
    cout<<"NO\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
1
7
4 3 4 3 3 3 4
  ^         ^

z x y
4 4 4 4 4 4 4
    4 3

1
9
2 1 4 2 4 3 3 1 2

1
11
1 2 3 3 3 4 4 3 4 2 1

1
5
1 1 1 1 1

1
6
2 2 2 2 2 1

1
10
2 4 2 2 8 4 8 2 6 2
  > = = = = = =

1
10
1 8 3 7 8 8 2 1 7 6

// 4 1 5
*/
