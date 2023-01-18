#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
long long int n, i, j;
int c,e,m,p,k;
int score[505]={0};

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (i=0 ; i<n ; i++){
        cin>>c>>e>>m>>p>>k;
        score[c+e+m+p+k]++;
    }
    for (i=500 ; i>=0 ; i--){
        for (j=0 ; j<score[i] ; j++)    cout << i<<"\n";
    }
}
