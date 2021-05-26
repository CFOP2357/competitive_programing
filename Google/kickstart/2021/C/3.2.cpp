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


char p[3] = {'R', 'P', 'S'};
void solve(){
    vector<ull>frecuency{0, 0, 0};
    vector<ull> play;
    ull W, E; cin>>W>>E;
    play.push_back(rand()%3);
    frecuency[play.back()]++;

    for(int i=1; i<60; i++){
        if(frecuency[0]>=frecuency[1] and frecuency[0]>=frecuency[2]){ //saca P
            if(E >= W/2 && frecuency[2]>frecuency[1])
                play.push_back(1);
            else
                play.push_back(2);
        }
        else if(frecuency[1]>=frecuency[0] and frecuency[1]>=frecuency[2]) //saca S
            if(E >= W/2 && frecuency[0]>frecuency[2])
                play.push_back(2);
            else
                play.push_back(0);
        else{ //saca R
            if(E >= W/2 && frecuency[1]>frecuency[0])
                play.push_back(0);
            else
                play.push_back(1);
        }
        frecuency[play.back()]++;
    }

    for(auto inst : play)
        cout<<p[inst];
    cout<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t;
    int x; cin>>x;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}

/*
5
50 0
50 0
50 0
50 0
50 0
*/
