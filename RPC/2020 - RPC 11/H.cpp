#include <bits/stdc++.h>
//#include <unordered_map>
using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;
#include <unordered_map>
#define findBO find_by_order
#define findBK order_of_key
*/

#define all(a) a.begin(), a.end()

typedef long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define X 3991
#define MOD 1000000007

/*#define X2 11
#define MOD2 1000000009*/

string s[3]; //hash en s[2]
ull n;

unordered_map <ull, vector<ull>> times;

ull getHash(string s){
  ull hash_ = 0;
  ull pot_ = 1;
  for(int j=0; j<n; j++){
    hash_ += (pot_*s[j])%MOD;
    hash_ %= MOD;
    pot_ *= X;
    pot_ %= MOD;
  }
  return hash_;
}

vector<ull> nop;

ull ans1, ans2;
void getRotations(string s){
  ull hash_ = getHash(s);

  if(times.find(hash_)==times.end()){
    ans1 = ans2 = LLONG_MAX;
    return;
  }
  ans1 = times[hash_][0];
  ans2 = times[hash_].back();
}

void seeRotations(){

  for(ull i=0; i<n; i++){
    ull hash_ = 0;
    ull pot_ = 1;
    for(int j=0; j<n; j++){
      hash_ += (pot_*s[2][(j+i)%n])%MOD;
      hash_ %= MOD;
      pot_ *= X;
      pot_ %= MOD;
    }
    times[hash_].push_back(i);
  }

  for(auto &t : times)
    sort(all(t.second));
}



void solve(){
  cin>>s[0]>>s[1]>>s[2];

  n = s[0].size();
  bool valid;
  char c0, c1;
  vector<ull> r;
  ull a, b, c;

  seeRotations();

  string aux;
  aux.resize(n,'C');

  ull ans = LLONG_MAX;

  for(ull i= 0; i< n; i++){
    valid = true;
    for(int j=0; j < n; j++){
      c0 = s[0][j]; c1 = s[1][(i+j)%n];
      if(c0 == c1){
        valid = false;
        break;
      } else {
        if(c0 > c1) swap(c0, c1);

        if(c0 == 'A'){
          if(c1 == 'B') aux[j] = 'C';
          else aux[j] = 'B';
        } else  aux[j] = 'A';
      }
    }
    if(valid){
      getRotations(aux);
      if(ans1!=LLONG_MAX){

        //auto it = upper_bound(all(r), i);

        array<ull,2> arr;

        arr[0] = ans1;
        arr[1] = ans2;

        /*if(it == r.end())
          it--;
        arr[2] = *it;
        if(it!=r.begin()){
          it--;
        }
        arr[3] = *it;*/

        for(auto idx: arr){
          //cout << "#" << idx << '\n';
          a = min(idx, n-idx);
          b = min(i, n-i);
          c = min(abs(idx - i), n - abs(idx - i));
          ans = min({
            ans,
            a+b,
            b+c,
            c+a
          });
        }
      }

      //ans = min(ans, isRotation(aux) + min(i, n-i));
    }

  }

  if(ans == LLONG_MAX)
    cout<<"-1\n";
  else
    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    while(t--){
        solve();
    }

    return 0;
}

