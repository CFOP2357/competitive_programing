#include <bits/stdc++.h>
using namespace std;

#define MAX 300000

/// FONT: GEEKSFORGEEKS
//https://www.geeksforgeeks.org/number-of-elements-greater-than-k-in-the-range-l-to-r-using-fenwick-tree-offline-queries/
// 23 / Jan / 2020

struct node {
    int pos;
    int l;
    int r;
    int val;
};

bool comp(node a, node b)
{

    if (a.val == b.val)
        return a.l > b.l;

    return a.val > b.val;
}


void update(int* BIT, int n, int idx)
{
    while (idx <= n) {
        BIT[idx]++;
        idx += idx & (-idx);
    }
}

int query(int* BIT, int idx)
{
    int ans = 0;
    while (idx) {
        ans += BIT[idx];

        idx -= idx & (-idx);
    }
    return ans;
}

vector<int>  solveQuery(int arr[], int n, int QueryL[],
                int QueryR[], int QueryK[], int q)
{

    node a[n + q + 1];



    for (int i = 1; i <= n; ++i) {
        a[i].val = arr[i - 1];
        a[i].pos = 0;
        a[i].l = 0;
        a[i].r = i;
    }


    for (int i = n + 1; i <= n + q; ++i) {
        a[i].pos = i - n;
        a[i].val = QueryK[i - n - 1];
        a[i].l = QueryL[i - n - 1];
        a[i].r = QueryR[i - n - 1];
    }


    sort(a + 1, a + n + q + 1, comp);


    int BIT[n + 1];

    memset(BIT, 0, sizeof(BIT));

    vector<int> ans(q + 1, 0);

    for (int i = 1; i <= n + q; ++i) {
        if (a[i].pos != 0) {


            int cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1);

            ans[a[i].pos] = cnt;
        }
        else {

            update(BIT, n, a[i].r);
        }
    }

    return ans;
}


int arr[MAX];
int QueryL[MAX];
int QueryR[MAX];
int QueryK[MAX];


int main()
{
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);

    int y, q; cin>>y>>q;

    for(int i = 0; i < y; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < q; i++){
        cin>>QueryL[i];
        cin>>QueryK[i];
        cin>>QueryR[i];

        QueryR[i] += QueryL[i];
        QueryK[i]--;
        QueryL[i]++;

        //cout<<QueryL[i]<<" "<<QueryR[i]<<" "<<QueryK[i]<<"\n";
    }


    auto ans = solveQuery(arr, y, QueryL, QueryR, QueryK, q);

    for(int i = 0; i < q; i++){
        if(QueryK[i]+1 <= arr[QueryL[i]-2])
            ans[i+1] = 0;
    }

    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}
