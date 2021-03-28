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

#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

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

ull t, n, q;

int query(int a, int b, int c){
    cout<<a<<" "<<b<<" "<<c<<endl;
    int ans; cin>>ans;

    if(ans==-1)
        exit(0);

    return ans;
}

vector<int> medianSort(vector<int> a, int l=0, int r=0){

    if(a.size()<=1)
        return a;

    if(a.size()==2){
        if(l){
            int reply = query(a[0], l, a[1]);
            if(reply == a[1])
                swap(a[0], a[1]);
        }
        else if(r){
            int reply = query(a[0], r, a[1]);
            if(reply == a[0])
                swap(a[0], a[1]);
        }
        return a;
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(all(a), std::default_random_engine(seed));

    /*cout<<"%%";
    for(int k : a)
        cout<<k<<" ";
    cout<<endl;*/

    int middle = query(a[0], a[1], a[2]);
    if(a[0]==middle)
        swap(a[0], a[1]);
    if(a[2]==middle)
        swap(a[2], a[1]);

    //ordenar a[0] y a[1]
    if(l){
        int reply = query(a[0], l, a[2]);
        if(reply == a[2])
            swap(a[0], a[2]);
    }
    else if(r){
        int reply = query(a[0], r, a[2]);
        if(reply == a[0])
            swap(a[0], a[2]);
    }

    vector<int> Left, Right;
    Left.push_back(a[0]);
    Right.push_back(a[2]);

    for(int i=3; i<a.size(); i++){
        int reply = query(Left[0], a[i], middle);

        if(reply == Left[0] || reply == a[i])
            Left.push_back(a[i]);
        else
            Right.push_back(a[i]);
    }

    vector<int> ansLeft = medianSort(Left, l, middle);
    vector<int> ansRight = medianSort(Right, middle, r);

    vector<int> ans;

    for(int k : ansLeft)
        ans.push_back(k);
    ans.push_back(middle);
    for(int k : ansRight)
        ans.push_back(k);

    return ans;
}

void solve(){

    vector<int> a;
    for(int i=1; i<=n; i++)
        a.push_back(i);

    vector<int> ans = medianSort(a);

    for(int k : ans)
        cout<<k<<" ";
    cout<<endl;

    int reply; cin>>reply;
    if(reply==-1)
        exit(0);
}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t>>n>>q;
    while(t--){
        solve();
        T++;
    }

    return 0;
}


