#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin>>n;

    /*double ans = sqrt((double)n);
    ans /= 3;
    ans *= 2;
    while(MOD < ans)
        ans-= (double)MOD;
    ans *= n;
    while(MOD < ans)
        ans-= (double)MOD;
    long long anss = ans;
    if((double)anss<ans) anss++;
    cout<<anss<<"\n";*/
    /*long long n2=n;
    long long anz = 0;
    for(long long i=1, j=2; n2>0; i++, j+=2){
        anz += i*(min(n2, j));
        //cout<<i<<" "<<i*j<<"\n";
        n2 -= j;
        anz %= MOD;
    }cout<<anz<<"\n";*/


    long long ans= 0;
    double p = (sqrt((double)(1+4*n)) - 1) / 2;
    long long x = p;
    ans = x;
    n-=(x*x+x);
    if(x%3==0){
        ans/=3;
        ans *= (x+1);
        ans%=MOD;
        ans *= (2*x + 1);
        ans%=MOD;
    }
    else if(x%3==2){
        ans *= (x+1)/3;
        ans%=MOD;
        ans *= (2*x + 1);
        ans%=MOD;
    }
    else{
        ans *= (x+1);
        ans%=MOD;
        ans *= (2*x + 1)/3;
        ans%=MOD;
    }


    //ans/=3;

    ans%=MOD;

    if(n>0)
        ans += n*(x+1);
    ans%=MOD;

    cout<<ans<<"\n";
    return 0;
}

