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

int try_(int i){


    int init = i;
    int j = i;

    while( i>0 && j<n-1 && a[i]>a[i-1] && a[j]>a[j+1] )
        j++, i--;

    if(i>0 && a[i]>a[i-1])
        return 0;
    if(j<n-1 && a[j]>a[j+1])
        return 0;

    return init-i;

}

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    vector<int> p;
    for(int i = 0; i<n; i++){
        int reply = try_(i);
        if(reply)
            p.push_back(reply);
    }



    sort(all(p));

    if(p.size()==1 || (p.size() && p.back() != p[p.size()-2])){

        int ans = *max_element(all(p));

        vector<int> l, r;
        l.push_back(0); r.push_back(0);

        for(int i=0; i<n-1; i++){
            if(a[i]<a[i+1])
                l.push_back(l.back()+1);
            else
                l.push_back(0);
        }

        reverse(all(a));

        for(int i=0; i<n-1; i++){
            if(a[i]<a[i+1])
                r.push_back(r.back()+1);
            else
                r.push_back(0);
        }
        reverse(all(r));

        reverse(all(a));

        /*for(int k : l)
            cout<<k<<" ";
        cout<<"\n";
        for(int k : r)
            cout<<k<<" ";
        cout<<"\n";*/


        for(int i=0; i<n; i++){
            if(l[i]==r[i] && l[i]==ans){

            }
            else {
                if(r[i]>=ans || l[i]>=ans){
                    cout<<"0\n";
                    return;
                }
            }
        }

        if(!(ans%2)){
            cout<<1<<"\n";
            return;
        }
    }
    cout<<0<<"\n";

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
/*
10
1 2 3 4 3 2 1 2 3 4
*/
