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

typedef int ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }


    ull ans = 2;
    ull lastPosition = 0, difference = 0;

    vector<ull> leftAns(n+1, 0), leftDifference(n+1, 0);
    for(int i=1; i<n; i++){

        ull currentAns = i-lastPosition+1;
        leftAns[i] = currentAns;
        leftDifference[i] = difference;
        if(a[i]-a[i-1] != difference){

            ull d = a[i-1] + difference;
            if(i+1<n && d + difference == a[i+1])
                currentAns++;

            lastPosition = i-1;
            difference = a[i]-a[i-1];
        }

        ans = max(ans, currentAns);

        //cout<<difference<<" ";
    } //cout<<"\n";

    //reverse(all(a));

    difference = 0;
    vector<ull> rightAns(n+1, 0), rightDifference(n+1, 0);
    for(int i=n-2; i>=0; i--){

        ull currentAns = lastPosition-i+1;
        rightAns[i] = currentAns;
        rightDifference[i] = difference;
        if(a[i+1]-a[i] != difference){

            ull d = a[i+1] - difference;
            if(i-1>=0 && d - difference == a[i-1])
                currentAns++;

            lastPosition = i+1;
            difference = a[i+1]-a[i];
        }

        ans = max(ans, currentAns);

        //cout<<difference<<" "<<i<<" "<<a[i]<<" "<<a[i+1]<<"\n";
    } //cout<<"\n";
    //reverse(all(rightAns)); reverse(all(rightDifference));

    /*cout<<"\n";
    for(int i = 0; i<n; i++)
        cout<<leftDifference[i]<<" ";
    cout<<"\n";
    for(int i = 0; i<n; i++)
        cout<<rightDifference[i]<<" ";
    cout<<"\n\n\n";
    for(int i = 0; i<n; i++)
        cout<<leftAns[i]<<" ";
    cout<<"\n";
    for(int i = 0; i<n; i++)
        cout<<rightAns[i]<<" ";
    cout<<"\n\n";*/

    for(int i=1; i<n-1; i++){
        //cout<<leftDifference[i]<<" "<<rightDifference[i]<<" "<<a[i]<<"\n";
        if(leftDifference[i] == rightDifference[i] && leftDifference[i] + a[i-1] == a[i+1] - rightDifference[i])
            ans = max(ans, leftAns[i]+rightAns[i]-1);
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

/*
1
9
5 5 4 5 5 5 4 5 6

1
10
1 2 3 4 3 6 2 2 1 1

3
5
1 2 3 4 6
5
1 2 10 4 5
5
10 2 3 4 5

1
2
1 2
*/
