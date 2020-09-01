#include <bits/stdc++.h>
using namespace std;

#define MAX 100010
#define MOD 1000000007

typedef long long ull;

vector<ull> muzzle;
vector<ull> notMuzzle;

void solve(){
    int n, d, m;
    cin>>n>>d>>m;

    for(int i=0; i<n; i++){
        int z; cin>>z;
        if(z>m)
            muzzle.push_back(z);
        else notMuzzle.push_back(z);
    }

    sort(muzzle.begin(), muzzle.end(), greater<ull>());
    sort(notMuzzle.begin(), notMuzzle.end(), greater<ull>());

    for(int i=1; i<muzzle.size(); i++)
        muzzle[i] += muzzle[i-1];

    for(int i=1; i<notMuzzle.size(); i++)
        notMuzzle[i] += notMuzzle[i-1];

    ull ans = 0;
    if(muzzle.size() && notMuzzle.size()){
        for(int i=0; i<=notMuzzle.size(); i++){
            int k = n-i;
            if(k%(d+1)){
                k /= d+1;
                k++;
            }
            else k /= d+1;

            ull total = 0;
            if(i>0)
                total = notMuzzle[i-1];
            if(k>0)
                total+=muzzle[min(k-1, (int)muzzle.size()-1)];

            //cout<<k<<" "<<total<<"\n";

            ans = max(ans, total);
        }
    }
    else if(notMuzzle.size()){
        ans += notMuzzle.back();
    }
    else ans += muzzle[n/(d+1) + (bool)(n%(d+1)) - 1];

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
