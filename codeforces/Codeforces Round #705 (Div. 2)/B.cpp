#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>

#include <sstream>

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
ull H, M, h, m;
string s;

char invert(char c){
    switch(c){
        case '2':
            return '5';
        break;
        case '5':
            return '2';
        break;
        default:
            return c;
        break;
    }
    return c;
}

bool correct(int n){
    return n==1 || n==2 || n==0 || n==5 || n==8;
}

bool correct(char c){

    if(c==':')
        return true;

    int n = c-'0';
    return correct(n);
}

bool correct(string s){

    for(char c : s)
        if(!correct(c))
            return false;

    int H, M;

    for(char &c : s)
        c = invert(c);
    s[2] = ' ';
    reverse(all(s));

    stringstream ss(s);

    s[2] = ':';
    reverse(all(s));

    ss>>H>>M;

    if(H >= h || M >= m)
        return false;

    return true;
}

void add(string &s){
    int H, M;
    s[2] = ' ';
    stringstream ss(s);
    ss>>H>>M;

    M++;
    if(M>=m){
        M=0;
        H++;
    }
    if(H>=h)
        H=0;

    s = "";
    s += (H/10)+'0';
    s += (H%10)+'0';
    s += ':';
    s += (M/10)+'0';
    s += (M%10)+'0';

}

void solve(){

    cin>>h>>m;
    cin>>s;

    while(!correct(s))
        add(s);

    cout<<s<<"\n";

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

