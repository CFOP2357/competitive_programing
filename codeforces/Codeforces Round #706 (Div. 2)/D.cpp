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

int try2(int i){


    int init = i;
    int ii = a[init];
    int j = i;

    while( i>0 && a[i]>a[i-1] && a[i-1]!=-1){
        i--;//a[--i]=-1;
    }

    a[init] = ii;

    return max(init-i, j-init);

}
int try3(int i){


    int init = i;
    int ii = a[init];
    int j = i;

    while(j<n-1 && a[j]>a[j+1] && a[j+1]!=-1)
        j++;//a[++j]=-1;

    a[init] = ii;

    return max(init-i, j-init);

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

        for(int i = 0; i<n; i++){
            if(try_(i) == ans){

                int k = i+ans;

                while(k<n-1 && a[k]<a[k+1])
                    k++;

                if(k-(i+ans)+1 >= ans){
                    cout<<"0\n";
                    return;
                }

                k = i-ans;
                while(k>0 && a[k]<a[k-1])
                    k--;

                if((i-ans)-k+1 >= ans){
                    cout<<"0\n";
                    return;
                }

                for(int j=1; j<=ans; j++){
                    a[i + j] = -1;
                    a[i - j] = -1;
                }
            }
        }

        for(int i = 0; i<n; i++){
            if(a[i]==-1)
                continue;
            int reply = try2(i);
            if(reply >= ans){
                cout<<"0\n";
                return;
            }
        }

        for(int i = n-1; i>=0; i--){
            if(a[i]==-1)
                continue;
            int reply = try3(i);
            if(reply >= ans){
                cout<<"0\n";
                return;
            }
        }

        cout<<1<<"\n";
    }
    else
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

