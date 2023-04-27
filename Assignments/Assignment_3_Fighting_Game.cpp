#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


int main (){
    int N;
    cin >> N;
    long long int e[N+5];
    long long int cost[N+5];
    for (long long int i=0 ; i<N ; i++){
        cin >> e[i];
    }
    cost[0] = e[0];
    cost[1] = e[1];
    for (long long int i=2 ; i<N ; i++){
        cost[i] = e[i] + min(cost[i-1], cost[i-2]);
    }
    cout << min(cost[N-1], cost[N-2]);
}


/*
int main (){
    int N;
    cin >> N;
    long long int e[N];
    long long int cost[N+2][3];
    for (int i=0 ; i<N ; i++)   cin >> e[i];
    cost[N-1][0] = e[N-1];
    cost[N-2][0] = e[N-2] + cost[N-1][0];
    cost[N-2][1] = e[N-2];
    for (int i=N-3 ; i>=0 ; i--){
        cost[i][0] = e[i] + min(cost[i+1][0], cost[i+1][1]);
        cost[i][1] = e[i] + min(cost[i+2][0], cost[i+2][1]);
    }
    long long int out;
    out = min(cost[0][0], cost[0][1]);
    out = min(out, cost[1][0]);
    out = min(out, cost[1][1]);
    cout << out;
}
*/
