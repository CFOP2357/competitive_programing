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

#include <bitset>

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

const int MAX_PR = 100000;
bitset<MAX_PR> isprime;
vector<int> pr;
void eratosthenesSieve(int lim = MAX_PR) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	for(int i=2; i<lim; i++) if (isprime[i]) pr.push_back(i);
}

ull d;

void solve(){

    cin>>d;

    ull a = *lower_bound(all(pr), d+1);
    ull b = *lower_bound(all(pr), a+d);

    cout<<min(a*b, a*a*a)<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    eratosthenesSieve();

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

