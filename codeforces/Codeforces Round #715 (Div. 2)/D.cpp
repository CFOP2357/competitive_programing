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
string s[3];

void solve(){
    a.clear(); b.clear();
    cin>>n;
    cin>>s[0]>>s[1]>>s[2];

    string ans = s[0]+s[1];

    for(int i=0; i<3; i++)
        for(int j=i+1; j<3; j++){
            string currentAns = "";

            int idxi(0), idxj(0);

            while(idxi<2*n || idxj<2*n){
                    if(idxi<2*n && idxj<2*n && s[i][idxi]==s[j][idxj]){
                        currentAns += s[i][idxi++]; idxj++;
                    }
                    else if(idxi <= idxj){
                        currentAns += s[i][idxi++];
                    }
                    else
                        currentAns += s[j][idxj++];
            }

            if(currentAns.size() < ans.size())
                ans = currentAns;
        }

    for(int i=0; i<3; i++)
        for(int j=i+1; j<3; j++){
            string currentAns = "";

            int idxi(0), idxj(0);

            while(idxi<2*n || idxj<2*n){
                    if(idxi<2*n && idxj<2*n && s[i][idxi]==s[j][idxj]){
                        currentAns += s[i][idxi++]; idxj++;
                    }
                    else if(idxi < 2*n){
                        currentAns += s[i][idxi++];
                    }
                    else
                        currentAns += s[j][idxj++];
            }

            if(currentAns.size() < ans.size())
                ans = currentAns;
        }

    for(int p=0; p<3; p++)
    for(int i=0; i<3; i++)
        for(int j=i+1; j<3; j++){
            string currentAns = "";

            int idxi(0), idxj(0);

            while(idxi<2*n || idxj<2*n){
                    if(idxi<2*n && idxj<2*n && s[i][idxi]==s[j][idxj]){
                        currentAns += s[i][idxi++]; idxj++;
                    }
                    else if(idxi <2*n && idxj<2*n){
                        if(rand()%2)
                            currentAns += s[i][idxi++];
                        else
                            currentAns += s[j][idxj++];
                    }
                    else if(idxi < 2*n){
                        currentAns += s[i][idxi++];
                    }
                    else
                        currentAns += s[j][idxj++];
            }

            if(currentAns.size() < ans.size())
                ans = currentAns;
        }


    for(int i=0; i<3; i++)
        for(int j=i+1; j<3; j++){
            string currentAns = "";

            for(int k = 0; k<2*n; k++){
                if(s[i][k]==s[j][k])
                    currentAns += s[i][k];
                else{
                    currentAns += '0';
                    currentAns += '1';
                }
            }

            int p = currentAns.size();
            int k = 0;
            for(int r = 0; r<currentAns.size(); r++){
                if(k>=s[i].size())
                    p = r;
                if(s[i][k] == currentAns[r])
                    k++;
            }
            k = 0;
            for(int r = 0; r<currentAns.size(); r++){
                if(k>=s[j].size())
                    p = max(r, p);
                if(s[j][k] == currentAns[r])
                    k++;
            }

            for(int i=currentAns.size()-1; i>p && i<currentAns.size(); i--)
                currentAns.pop_back();

            if(currentAns.size() < ans.size())
                ans = currentAns;
        }

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

