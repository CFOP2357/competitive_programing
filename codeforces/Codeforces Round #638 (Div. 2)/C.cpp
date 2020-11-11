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

vector<ull> a;
vector<ull> b;
ull n, k;

int t[250];

void solve(){
    fill(t, t+250, 0);

    cin>>n>>k;
    string s; cin>>s;

    if(k==1){
        sort(all(s));
        cout<<s<<"\n";
        return;
    }

    sort(all(s));
    char last = 'a';
    for(char c : s){
        t[c]++;
        last = max(c, last);
    }

    string ans = "", ans2 = "";
    int emp = k;
    bool nxtAns = false;
    for(char c = 'a'; c<='z'; c++){

        if(t[c]){
            if(emp){
                if(t[c] < emp){
                    emp-=t[c];
                    nxtAns = true;
                }
                else {

                    if(nxtAns){
                        ans = c;
                        break;
                    }

                    if(last==c){
                        emp=0;
                        c--;
                    }
                    else{
                        t[c]-=emp;
                        emp = 0;
                        ans = string(t[c]+1, c);
                    }

                    if(t[c]>0)
                        nxtAns = true;
                }

            }
            else if(last == c){
                if(!nxtAns){
                    ans += string(t[c]/k, c);
                    if(t[c]%k)
                        ans += c;
                }
                else {
                    ans += string(t[c], c);
                }
            }
            else {
                ans += string(t[c], c);
                nxtAns = true;
            }



        }

    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

