#include <bits/stdc++.h>
using namespace std;

#define MAX 300005
long long a[MAX];
long long n, k, z;
long long dp[10][MAX];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long m = 0;
    long long t;
    cin>>t;
    while(t--){
        cin>>n>>k>>z;
        for(int i=0; i<=n; i++)
            a[i]=0;
        long long ans = 0;
        m = 0;
        long long sum =0;
        //cout<<"\n";
        cin>>a[0];
        sum+=a[0];
        for(int i=1; i<n; i++){
            cin>>a[i];
            sum+=a[i];
            if(i<=k){
                m = max(m, a[i]+a[i-1]);
                long long total = sum;
                if((k-i)/2<=z){
                    total += ((k-i)/2)*m;
                    if((k-i)%2 && (k-i)/2+1<=z)
                        total += a[i-1];
                }
                ans = max(total, ans);
            }
        }

        //cout<<m<<" ";
        cout<<ans<<"\n";

    }
    return 0;
}

/*
1
55 37 1
9 17 6 14 8 4 4 16 1 6 10 13 6 19 10 5 11 13 16 19 10 2 9 11 1 15 13 17 7 1 9 4 11 16 17 11 3 7 15 8 2 10 6 20 3 16 8 4 12 1 9 3 8 17 18
*/
