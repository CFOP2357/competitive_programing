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

vector<ull> u;
vector<ull> s;
vector<ull> ans;
vector<vector<ull>> university_student;
ull n, m;

void solve(){
    u.clear(); s.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        u.push_back(z);
    }
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        s.push_back(z);
    }

    university_student.assign(n+1, vector<ull>());
    for(int i=0; i<n; i++)
        university_student[u[i]].push_back(s[i]);

    for(auto &un : university_student){
        sort(all(un), greater<ull>());
        ull acum = 0;
        for(ull &skill : un){
            acum += skill;
            skill = acum;
        }
    }


    ans.assign(n+1, 0);
    for(const auto &un : university_student){
        for(int k = 1; k<=un.size(); k++){
            int lim = (un.size()/k)*k - 1;
            if(lim>=0){
                ans[k] += un[lim];
            }
        }
    }

    for(int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
1
7
1 2 1 2 1 2 1
6 8 3 1 5 1 5
*/

