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
vector<string> s;
multiset<string> palindrome;
map<string, int> repetitionsOf;

bool itsPalindrome(string s){
    for(int i=0; i<s.size(); i++){
        if(s[i]!=s[s.size()-i-1])
            return false;
    }
    return true;
}

void solve(){

    cin>>n>>m;
    for(int i=0; i<n; i++){
        string z; cin>>z;
        s.push_back(z);
    }

    string ans;
    for(string s : ::s){

        string r = s; reverse(all(r));
        if(repetitionsOf[r]){
            ans += s;
            repetitionsOf[r]--;
            if(itsPalindrome(s)){
                palindrome.erase(palindrome.find(s));
            }
        }
        else {
            repetitionsOf[s]++;
            if(itsPalindrome(s)){
                palindrome.insert(s);
            }
        }

    }

    string r = ans; reverse(all(r));
    if(palindrome.size())
        ans += *palindrome.begin();
    ans += r;

    cout<<ans.size()<<"\n";
    cout<<ans<<"\n";

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

