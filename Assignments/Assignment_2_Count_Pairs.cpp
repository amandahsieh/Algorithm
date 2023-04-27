#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long int n, i;
//oj 不知道為甚麼要 long int 才會過
long long int l, r, cnt=0, tmp, lef, rig;
long long int mx, mn;
long long int arr[100010];


int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l >> r;
    for (i=0 ; i<n ; i++)    cin >> arr[i];
    sort(arr, arr+n);
    for (i=0 ; i<n ; i++){
        if (arr[i] > sqrt(r))   break;
        mx = (r-r%arr[i])/arr[i];// + (r%arr[i] != 0);
        mn = (l-l%arr[i])/arr[i] + (l%arr[i]!=0);
        rig = upper_bound((arr+i+1), (arr+n), mx)-arr;
        lef = lower_bound((arr+i+1), (arr+n), mn)-arr;
        tmp = rig - lef;
        //cout<<i<<"\t"<<tmp<<endl;
        if (tmp)    cnt+=tmp;
    }
    cout<<cnt;
}
