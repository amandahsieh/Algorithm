#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <long long int> n;
long long int k;
long long int ans=0;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    n.resize(N);
    for (int i=0 ; i<N ; i++)   cin >> n[i];
    sort(n.begin(), n.end());
    n.erase(unique(n.begin(),n.end()),n.end());
    for (int i=1 ; i<N ; i++){
        if (n[i]<=n[i-1]){
            n[i] = 1000000010;
            break;
        }
    }
    cin >> k;
    ans = k*(k+1)/2;
    int which = upper_bound(n.begin(), n.end(), k)-n.begin();
    //cout << which << endl;
    long long int tmp = k+1;
    int t=which;
    //cout << ans << endl;
    for (int i=0 ; i<which ; i++){
        //cout << "n[i]¡G"<<n[i]<<endl;
        ans-=n[i];
        while (tmp==n[t]){
            t++;
            tmp++;
        }
        //cout << "tmp¡G"<<tmp<<endl;
        ans+=tmp;
        tmp++;
        //cout << ans << endl;
    }
    cout << ans;
}
