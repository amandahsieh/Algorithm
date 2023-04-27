#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
vector <string> s;
bool comparing(string a, string b){
    string tmp1 = a+b;
    string tmp2 = b+a;
    return tmp1>tmp2;
    /*
    int k=min(a.length(), b.length());
    for (int j=0 ; j<k ; j++){
        if (a[j]>b[j])  return true;
        else if (a[j]<b[j]) return false;
    }
    if (k<a.length()){
        return comparing(a.substr(k, a.length()-k), b);
    }
    else if (k<b.length()){
        return comparing(a, b.substr(k, b.length()-k));
    }
    else    return true;
    */
}


int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    s.resize(N);
    for (int i=0 ; i<N ; i++)   cin >> s[i];
    sort(s.begin(), s.end(), comparing);
    int start = 0;
    for (int i=0 ; i<N ; i++){
        if (start == 0){
            if (s[i]!="0")    start = 1;
        }
        if (start)  cout << s[i];
    }
    if (start == 0) cout << "0";
}
