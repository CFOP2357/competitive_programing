#include <bits/stdc++.h>
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

struct Robot{
    int x;
    char dir;
    int id;
    int time;

    Robot(){
        time = 0;
    }

    bool operator <(const Robot &b){
        return x < b.x;
    }
};

void solve(){
    cin>>n>>m;

    vector<int> ans(n, -1);
    vector<Robot> robot(n);
    for(int i=0; i<n; i++){
        cin>>robot[i].x;
        robot[i].id = i;
    }
    for(int i=0; i<n; i++){
        cin>>robot[i].dir;
    }

    sort(all(robot));
    list<Robot> robots_in_list(all(robot));

    set<Robot> even_to_match;
    set<Robot> odd_to_match;

    for(auto current = robots_in_list.begin(); current != robots_in_list.end(); current++){
        if(current->dir == 'L'){

        }
        else {
            if(current->x%2)
                odd_to_match.insert(current);
            else
                even_to_match.insert(current);
        }
    }



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

