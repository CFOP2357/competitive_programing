#include <bits/stdc++.h>

using namespace std;

int main(){
    priority_queue<string, vector<string>, greater<string>> result;
    string abc, word;
    cin>>abc>>word;

    //Remove
    for(int i=0; i<word.size(); i++){
        result.push(word.substr(0,i)+word.substr(i+1));
    }

    //Add
    //cout<<word.substr(0,1)<<" "<<word.substr(1)<<"\n";
    for(int i=0; i<word.size(); i++){
        for(int j=0; j<abc.size(); j++){
            result.push(word.substr(0,i+1)+abc[j]+word.substr(i+1));
        }
    }
    for(int j=0; j<abc.size(); j++){
        result.push(word+abc[j]);
        result.push(abc[j]+word);
        //cout<<word+abc[j]<<"\n";
    }

    //change
    for(int i=0; i<word.size(); i++){
        for(int j=0; j<abc.size(); j++){
            string toAdd=word;
            toAdd[i] = abc[j];
            result.push(toAdd);
        }
    }

    //print
    string last="";
    while(!result.empty()){
        string r = result.top();
        result.pop();
        if(last==r)continue;
        last = r;
        if(r==word)continue;
        cout<<r<<"\n";
    }

    return 0;
}
