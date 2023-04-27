#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

/*N 已有的商品總數  k 需要的商品數  p 已有的商品價格  ans 最小所需價格*/
int N;
long long int k;
vector <long long int> p;
long long int ans = 0;

int main (){
/*-------------------------io 優化-------------------------*/
    ios_base::sync_with_stdio(false);
    cin.tie(0);

/*----------------------輸入數量及價格----------------------*/
    cin >> N;
    p.resize(N);
    for (int i=0 ; i<N ; i++)   cin >> p[i];

/*--------------------排序並排除重複值-----------------------*/
    cin >> k;
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()),p.end());

/*--預設答案是從1到k，再排除已買商品的價格，求下一個未出現的數--*/
    ans = k*(k+1)/2;
    int t = upper_bound(p.begin(), p.end(), k)-p.begin();
    int b = t;
    int tmp = k+1;
    for (long long int i=0 ; i<b ; i++){
        ans -= p[i];
        while (tmp == p[t]){
            tmp++;
            t++;
        }
        ans += tmp;
        tmp++;
    }
    cout << ans;
}
