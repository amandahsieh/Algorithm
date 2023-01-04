#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*---b：題目所述，每個位置能往上走的格數，from：最遠可從何處走到---*/
vector <int> b;
vector <int> from;
int N;
int ans=0;

int main (){
		/*--------------------------io 優化--------------------------*/
    ios_base::sync_with_stdio(false);
    cin.tie(0);

		/*----------------------輸入並設定長度-----------------------*/
    cin >> N;
    b.resize(N+5);
    from.resize(N+5,-1);
    for (int i=0 ; i<N ; i++)   cin >> b[i];

		/*設定可從何處走到：從 0 (最遠處) 開始，設定可以從 0 走到的點。*/
		/*----若走到的當下 from 值不小於零，則表示有更遠的地方可走到---*/
    for (int i=0 ; i<N ; i++){
        for (int j=1 ; j<=b[i] ; j++)   if(from[i+j]<0) from[i+j]=i;
    }

		/*----------------------計算最少要走幾步----------------------*/
    N--;
    while (N!=0){
        N = from[N];
        ans++;
    }
    cout << ans;
}
