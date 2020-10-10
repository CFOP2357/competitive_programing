#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
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

ull n;

vector<vector<int>> ans;

void rotation(vector<int> sz){
    vector<int> b;
    ans.push_back(sz);

    int last = n;

    reverse(all(sz));

    for(int k : sz){

        for(int i = last-k; i<last; i++)
            b.push_back(a[i]);
        last -= k;

    }

    for(int i=0; i<n; i++)
        a[i] = b[i];


    /*for(int k : a)
        cout<<k<<" ";
    cout<<"\n";*/
}

bool ordered(){
    for(int i = 1; i<n; i++)
        if(a[i]<a[i-1])
            return false;
    return true;
}

void solve(){

    cin>>n;
    bool order= true;
    //cout<<"#\n";
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        if(i>0 && a[i]<a[i-1])
            order = false;
    }

    if(order){
        cout<<"0\n";
        return;
    }


    if(a[0] == 1)
        rotation(vector<int>(n,1));

    //cout<<"#\n";

    while(!ordered()){

        vector<int> nxt;

        int i;
        for(i=1; i<n && (a[i]-1==a[i-1] || a[i] == 1); i++){
            if(a[i-1]==1)
                break;
        }

        if(i==n)
            for(i=1; i<n && a[i]-1==a[i-1]; i++);

        //i--;

        nxt.push_back(i);

        int j;
        for(j = i-1; a[j]!=a[0]-1 && j<n; j++);

        if(j==n){
           for(j = i-1; a[j]!=n && j<n; j++);
        }

        //cout<<i<<" "<<j<<"\n";
        if(j>=i)
            nxt.push_back(j-i+1);

        if(j<n-1){
            if(a[j+1] == 1){
                nxt.push_back(1);
                j++;
            }
            if(j<n-1)
                nxt.push_back(n-j-1);
        }

        /*for(int p : nxt)
            cout<<p<<" ";
        cout<<"\n";*/

        rotation(nxt); //cout<<"\n";
    }


    //cout<<"#\n";
    cout<<ans.size()<<"\n";
    for(auto v : ans){
        cout<<v.size()<<" ";
        for(int a : v)
            cout<<a<<" ";
        cout<<"\n";
    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

/*
10
7 2 8 10 9 3 1 4 5 6

*/
