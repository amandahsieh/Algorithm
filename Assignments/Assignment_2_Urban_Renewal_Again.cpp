#include <iostream>
#include <algorithm>
using namespace std;

long long int n, k, A, B, i, j, result;
long long int region[100005];

long long int compute (long long int start, long long int last){

    long long int rebuild;
    long long int num = upper_bound(region+1, region+k+1, last) - lower_bound(region+1, region+k+1, start);
    if (num <= 0)   return A;
    else    rebuild = num * (last-start+1) * B;
    if (start == last)  return rebuild;

    long long int divide1 = compute(start, (start+last)/2);
    long long int divide2 = compute((start+last)/2+1, last);

    return min((divide1 + divide2), rebuild);
}



int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> A >> B;
    for (i=1 ; i<=k ; i++){
        cin >> region[i];
    }
    sort(region+1, region+k+1);
    result = compute(1, n);
    cout << result;
}

