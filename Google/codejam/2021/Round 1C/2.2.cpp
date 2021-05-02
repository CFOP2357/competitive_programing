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

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

bool isRoaring(ull n){

    for(ull k = 10; k<=1000000000000000000; k*=10){
        vector<ull> p;
        ull f = k;
        ull t = n;
        while(t){
            p.push_back(t%f);
            t/=f;
            if(p.back() == f/10 && f>10)
                f/=10;
        }

        ull d = 0;
        t = n;
        while(t){
            t/=10;
            d++;
        }

        bool possible = true;
        for(int i=1; i<p.size(); i++){
            if(p[i-1] != p[i]+1)
                possible = false;
        }

        ull D = 0;
        for(auto t : p)
            while(t){
                t/=10;
                D++;
            }

        if(p.size()>1 && possible && D==d){
            return true;
        }
        if(k==1000000000000000000)
            break;
    }
    return false;
}

void solve(){
    cin>>n;
    s = to_string(n);
    ull ans = 1234567891011121314;
    for(int i = 1; i<=s.size(); i++){
        string current = s.substr(0, i);
        ull z = stoll(current);
        while(current.size()<=19 && stoll(current)<=n){
            z++;
            current += to_string(z);
        }
        if(current.size()<=19 && isRoaring(stoll(current)) && stoll(current)>n){
            ans = min(ans, stoll(current));
        }
    }
    for(int i = 1; i<=s.size(); i++){
        string current = s.substr(0, i);
        current = to_string(stoll(current)+1);
        ull z = stoll(current);
        while(current.size()<=19 && stoll(current)<=n){
            z++;
            current += to_string(z);
        }
        if(current.size()<=19 && isRoaring(stoll(current)) && stoll(current)>n){
            ans = min(ans, stoll(current));
        }
    }
    for(int i = 1; i<=s.size()+1; i++){
        string current = "1"+string(i-1, '0');
        ull z = stoll(current);
        while(current.size()<=19 && stoll(current)<=n){
            z++;
            current += to_string(z);
        }
        if(current.size()<=19 && isRoaring(stoll(current)) && stoll(current)>n){
            ans = min(ans, stoll(current));
        }
    }
    for(int i = 1; i<=s.size()+1; i++){
        string current = s[0]+string(i-1, '0');
        ull z = stoll(current);
        while(current.size()<=19 && stoll(current)<=n){
            z++;
            current += to_string(z);
        }
        if(current.size()<=19 && isRoaring(stoll(current)) && stoll(current)>n){
            ans = min(ans, stoll(current));
        }
    }
    ull k = n;
    while(++k <= n+100000 && k<ans){
        if(isRoaring(k)){
            cout<<k<<"\n";
            return;
        }
    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}


