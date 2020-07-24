#include <bits/stdc++.h>

using namespace std;

int n;
float t0, d0;
float t1, d1;
int maxSpeed;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cin>>t0>>d0;
    n--;
    while(n--){
        cin>>t1>>d1;

        int speed = (d1-d0)/(t1-t0);
        maxSpeed = max(speed, maxSpeed);

        t0=t1;
        d0=d1;
    }
    cout<<maxSpeed<<"\n";
    return 0;
}
