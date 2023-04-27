#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define M 1000000007
#define N 200010

using namespace std;
int main (){
    long long int num;
    long long int mul=1;
    long long int n[200005];
    cin >> num;
    for (long long int k=0 ; k<num ; k++){
        cin>>n[k];
        if (n[k]>num) n[k]=num;
    }
    sort(n, n+num);
    for (long long int i=0 ; i<num ; i++){
        long long int s = (n[i]-i)%M;
        mul *= s;
        mul = mul % M;
    }
    cout<<mul;
}
