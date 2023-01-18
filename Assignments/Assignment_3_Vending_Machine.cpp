#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int N;
int Q;
int coinnumber[100005];
void dp(int m, int C[]){
    coinnumber[0] = 0;
    for (int i=1 ; i<=m ; i++){
        int least = i;
        for(int j=0 ; j<N ; j++){
            if (i < C[j])   continue;
            if (i == C[j])  {
                least = 1;
                break;
            }
            else if (coinnumber[i-C[j]]+1 < least)  least = coinnumber[i-C[j]]+1;
        }
        coinnumber[i] = least;
    }
    return;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    int C[N+5];
    for (int i=0 ; i<N ; i++){
        cin >> C[i];
    }
    cin >> Q;
    int payback[Q+1];
    int maxpayback=0;
    for (int k=0 ; k<Q ; k++){
        int P[N+5];
        long long int money;
        long long int payment = 0;
        cin >> money;
        for (int j=0 ; j<N ; j++){
            cin >> P[j];
            payment += P[j] * C[j];
        }
        payback[k] = (int)(payment - money);
        maxpayback = max(maxpayback, payback[k]);
    }
    dp(maxpayback,C);
    for (int k=0 ; k<Q ; k++)   cout << coinnumber[payback[k]] << "\n";
}
