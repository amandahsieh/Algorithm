#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

class num{
public:
    long long int number=0;
    long long int cnt=0;
};
num arr[20010];

bool comparing(num a, num b){
    return a.cnt > b.cnt;
}

long long int n, k, tmp, i;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (i=0 ; i<n ; i++){
        cin >> tmp;
        arr[tmp+10005].cnt++;
        arr[tmp+10005].number = tmp;
    }
    sort(arr, arr+20010, comparing);
    cout<<arr[k-1].number;
}
