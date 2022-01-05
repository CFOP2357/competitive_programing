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

char next_of(char c){
    if(c == '9')
        return '0';
    return c+1;
}

void solve(){
    a.clear(); b.clear();
    cin>>n;
    cin>>s;

    bool changed = true;
    while(changed){
        changed = false;

        for(char first_char = '0'; first_char <= '9'; first_char++){
            string new_s;

            for(int i = 0; i < s.size(); i++){
                if(i < s.size()-1 and s[i] == first_char and s[i+1] == next_of(first_char)){
                    new_s.push_back(next_of(s[i+1]));
                    i++;

                    changed = true;
                }
                else
                    new_s.push_back(s[i]);
            }

            s = new_s;
        }

    }

    cout<<s<<"\n";

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


