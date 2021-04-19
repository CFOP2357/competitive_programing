#include <bits/stdc++.h>

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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
typedef long long ll;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

vector<ull> p;

const int MAX_PR = 100010;
bitset<MAX_PR> isprime;
void eratosthenesSieve() {
    int lim = MAX_PR-1;
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	p = pr;
}

bool isPrime(ull k){

    for(int i=2; i*i<=k; i++){
        if(k%i == 0)
            return false;
    }
    return true;

}

void solve(){
    a.clear(); b.clear();
    cin>>n;

    ull p = sqrt(n)+200;

    ull A(0), B(0);
    ull ans = 0;
    for(int i=0; i<=500 && p-i >= 2; i++){
        ull d = p-i;
        if(isPrime(d)){
            if(d>B)
                B=d;
        }

        if(B>A)
            swap(A, B);

        if(A*B > n){
            A = B;
            B = 0;
        }

        if(A && B)
            break;
    }

    ans = A*B;
    assert(ans);
    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    eratosthenesSieve();

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}

