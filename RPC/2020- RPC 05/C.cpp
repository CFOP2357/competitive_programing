#include <bits/stdc++.h>

using namespace std;

int row[55];
int column[55];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r, c, a, b;
    cin>>r>>c>>a>>b;

    for(int i=0; i<a; i++)
        cin>>row[i];
    for(int i=0; i<b; i++)
        cin>>column[i];

    char start = 'B', actual='B';
    /*for(int i=0; i<a; i++)
        cout<<row[i];
    cout<<"\n";*/
    for(int i=0; i<a; i++){
        actual=start;
        for(int y=0; y<row[i]; y++){
            actual=start;
            for(int j=0; j<b; j++){

                for(int x=0; x<column[j]; x++)
                    cout<<actual;
                //cout<<"v";
                if(actual == 'B')
                    actual = 'W';
                else if(actual == 'W')
                    actual = 'B';
            }
            cout<<"\n";
        }

        if(start == 'B')
            start = 'W';
        else if(start == 'W')
            start = 'B';
    }
    return 0;
}
/*
10 10 5 5
3
2
1
1
1
2
2
2
2
2
*/
