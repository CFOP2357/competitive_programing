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
ull n, m, p;
string s;

void solve(){

    vector<int> possibleAns;
    vector<int> possibleAns2;
    vector<pii> rep;


    for(int i=0; i<100; i++){
        cin>>s;
        int points = 0;
        for(char c : s){
            if(c=='1')
                points++;
        }

        rep.push_back({points, i+1});

        /*if(points>=9000)
            possibleAns.push_back(i+1);
        else if(points>=8000)
            possibleAns2.push_back(i+1);*/
    }

    /*if(possibleAns.size())
        cout<<possibleAns[rand()%possibleAns.size()]<<"\n";
    else if(rand()%101 <= 87 && possibleAns2.size())
        cout<<possibleAns2[rand()%possibleAns2.size()]<<"\n";
    else{*/
        sort(all(rep));

        for(int i=rep.size()-1; i>=0; i--){

            if(rand()%101 <= 80){
                cout<<rep[i].second<<"\n";
                return;
            }

        }
        cout<<rand()%100+1<<"\n";
    //}

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t>>p;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}


