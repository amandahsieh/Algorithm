#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main (){
    int N;
    cin >> N;
    int rev[N+5];
    long long int earned[N+5];
    long long int maximum[N+5];
    long long int minimum[N+5];
    long long int ans = 0, tmp;
    for (int i=1 ; i<=N ; i++)   cin >> rev[i];
    earned[0] = 0;
    for (int i=1 ; i<=N ; i++)   earned[i] = earned[i-1] + rev[i];
    maximum[0] = 0;
    minimum[0] = 0;
    for (int i=1 ; i<=N ; i++){
        maximum[i] = (earned[i] > earned[maximum[i-1]])? i:maximum[i-1];
        minimum[i] = (earned[i] < earned[minimum[i-1]])? i:minimum[i-1];
    }
    for (int i=1 ; i<=N ; i++){
        tmp = max(abs(earned[i] - earned[maximum[i]]), abs(earned[i] - earned[minimum[i]]));
        ans = (tmp > ans) ? tmp:ans;
    }
    cout << ans;

}
