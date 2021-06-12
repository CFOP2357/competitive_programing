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
ull h, w, k;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>h>>w>>k;

    vector<ull> height(w+5, 0);
    vector<vector<ull>> grid(h+5, vector<ull>(w+5, 0));
    UF uf_width((h+5)*(w+5)+10), uf_height((h+5)*(w+5)+10), uf_diagonal((h+5)*(w+5)+10), uf_diagonal2((h+5)*(w+5)+10);

    for(int i=0; i<h*w; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    int current = 1;
    int time = 1;
    for(ull x : a){
        ull y = ++height[x];

        ull id = y*w + x;

        grid[y][x]=current;
        if(grid[y][x+1]==current)
            uf_width.join(id, (y)*w+(x+1));
        if(grid[y][x-1]==current)
            uf_width.join(id, (y)*w+(x-1));

        if(grid[y+1][x]==current)
            uf_height.join(id, (y+1)*w+(x));
        if(grid[y-1][x]==current)
            uf_height.join(id, (y-1)*w+(x));

        if(grid[y-1][x+1]==current)
            uf_diagonal.join(id, (y-1)*w+(x+1));
        if(grid[y+1][x-1]==current)
            uf_diagonal.join(id, (y+1)*w+(x-1));

        if(grid[y+1][x+1]==current)
            uf_diagonal2.join(id, (y+1)*w+(x+1));
        if(grid[y-1][x-1]==current)
            uf_diagonal2.join(id, (y-1)*w+(x-1));


        if(uf_height.size(id)>=k or uf_width.size(id)>=k
           or uf_diagonal.size(id)>=k or uf_diagonal2.size(id)>=k){
            if(current == 1)
                cout<<"A ";
            else
                cout<<"B ";
            cout<<time<<"\n";
            return;
        }

        current++;
        if(current==3)
            current = 1;
        time++;
    }

    cout<<"D\n";

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

