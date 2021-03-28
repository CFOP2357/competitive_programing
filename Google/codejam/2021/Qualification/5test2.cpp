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

#include <random>

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

vector<double> Ans;

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

double sigmoid(double x){

    double ans = 1;
    ans /= (1.00 + exp(-x));
    return ans;

}

void solve(){


    vector<int> repetitions(10005, 0);

    for(int i=0; i<30000; i++){

        double S = fRand(-3.00, 3.00);

        int points = 0;
        for(int j=0; j<10000; j++){

            double Q = fRand(-3.00, 3.00);

            if(0){ //cheat
                points++;
            }
            else { //not cheat
                double p = fRand(-3.00, 3.00);
                if(p <= sigmoid(S-Q)){
                    points++;
                }
            }
        }

        //cout<<points<<"\n";
        repetitions[points/100]++;

    }

    vector<pii> ans;
    for(int i=0; i<repetitions.size(); i++){
        ans.push_back({repetitions[i], i*100});
    }

    sort(all(ans), greater<pii>());

    for(int i=0; i<10; i++){
        cout<<ans[i].second<<" "<<ans[i].first<<"\n";
    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand (time(NULL));

    solve();

    return 0;
}


