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

vector<vector<int>> moves;
ull n, k;
string s;

bool ordered(){
    bool ans = true;
    for(int i=0; i<n-1; i++){
        if(s[i]=='R' && s[i+1]=='L')
            ans = false;
    }
    return ans;
}

void solve(){
    cin>>n>>k;
    cin>>s;

    //cout<<ordered()<<"%\n";

    ull sz = 0;
    while(!ordered()){
        moves.push_back(vector<int>());

        for(int i=0; i<n-1; i++)
            if(s[i]=='R' && s[i+1]=='L'){
                s[i]='L';
                s[i+1]='R';
                i++;
                sz++;
                moves.back().push_back(i);
            }

    }

    //cout<<moves.size()<<"#\n";

    if(sz<k || moves.size()>k){
        cout<<"-1\n";
        return;
    }

    int toDo = moves.size();
    int done = 0;
    for(auto m : moves){
        while(toDo + done < k && m.size()>1){
            done++;
            cout<<"1 "<<m.back()<<"\n";
            m.pop_back();
        }
        toDo--; done++;
        cout<<m.size()<<" ";
        for(auto a : m)
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

