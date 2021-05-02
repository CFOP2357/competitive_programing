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

void solve(){
    vector<ull> A(3);
    cin>>A[0]>>A[1]>>A[2];

    if(!A[0] && !A[1] && !A[2]){
        cout<<"0 0 0 0\n";
        return;
    }

    const ull D = 10000000000LL;
    for(ull r = 0; r<=50000; r++){
        sort(all(A));
        do{
            const ull d = (A[0]+r*(D/10))%(360*12*D);
            ull m, s;

            ull h = d;
            h/=D;
            h/=360;

            m = d%(360*D);
            s = m%(6*D);
            m = m/(6*D);
            if(s%(D/10))
                continue;
            s = s/(D/10);


            //m=30, s=0;
            //cout<<h<<" "<<m<<" "<<s<<"\n";

            ull a1 = ((A[1]+r*(D/10))%(360*12*D));
            ull a2 = ((A[2]+r*(D/10))%(360*12*D));
            if(abs(m*6*12*D-a1) == 0 && abs(s*6*12*D-a2)==0){

                //cout<<d<<" "<<a1<<" "<<a2<<"# ";
                cout<<h<<" "<<m<<" "<<s<<" "<<"0\n";
                return;
            }
        }while(next_permutation(all(A)));
    }

    for(ull r = 0; r<=50000; r++){
        sort(all(A));
        do{
            const ull d = (A[0]+r*(D/10))%(360*12*D);
            ull m, s;

            ull h = d;
            h/=D;
            h/=360;

            m = d%(360*D);
            s = m%(6*D);
            m = m/(6*D);
            if(s%(D/10))
                continue;
            s = s/(D/10);


            //m=30, s=0;
            //cout<<h<<" "<<m<<" "<<s<<"\n";

            ull a1 = ((A[1]+r*(D/10))%(360*12*D));
            ull a2 = ((A[2]+r*(D/10))%(360*12*D));
            if(abs(m*6*12*D-a1) <6*12*D && abs(s*6*12*D-a2)==0){

                //cout<<d<<" "<<a1<<" "<<a2<<"# ";
                cout<<h<<" "<<m<<" "<<s<<" "<<"0\n";
                return;
            }
        }while(next_permutation(all(A)));
    }

    for(ull r = 0; r<=50000; r++){
        sort(all(A));
        do{
            const ull d = (A[0]+r*(D/10))%(360*12*D);
            ull m, s;

            ull h = d;
            h/=D;
            h/=12;
            h/=30;

            m = d%(360*D);
            s = m%(6*D);
            m = m/(6*D);
            ull n = s%(D/10);
            s = s/(D/10);



            //m=30, s=0;
            //cout<<h<<" "<<m<<" "<<s<<"\n";

            ull a1 = ((A[1]+r*(D/10))%(360*12*D));
            ull a2 = ((A[2]+r*(D/10))%(360*12*D));
            if(abs(m*6*12*D-a1) <6*12*D && abs(s*6*12*D-a2)<6*12*D){
                cout<<h<<" "<<m<<" "<<s<<" "<<n<<"\n";
                return;
            }
        }while(next_permutation(all(A)));
    }



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
3
0 0 0
0 21600000000000 23400000000000
1476000000000 2160000000000 3723000000000

*/


