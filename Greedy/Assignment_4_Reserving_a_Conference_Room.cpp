#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
/*---------------記錄每筆預約的開始及結束時間----------------*/
class reserve{
public:
    int s, f;
};

/*----本題使用貪婪演算法，最先結束 / 同時結束較晚開始者優先----*/
bool comparing(reserve a, reserve b){
    if (a.f!=b.f)   return a.f < b.f;
    else            return a.s > b.s;
}
int N;
vector <reserve> r;
int t = 0;

int main (){
		/*-----------------------io 優化-----------------------*/
    ios_base::sync_with_stdio(false);
    cin.tie(0);

		/*--------------------輸入及設定變數-------------------*/
    cin >> N;
    r.resize(N);
    for (int i=0 ; i<N ; i++)    cin >> r[i].s >> r[i].f;

		/*---以函式排序 (貪婪，先結束、同時結束較晚開始者優先)--*/
    sort(r.begin(), r.end(), comparing);
    for (int i=0 ; i<N ; i++){
        if (r[i].s >= t){
            t = r[i].f;
            cout << r[i].s << " " << r[i].f << "\n";
        }
    }
}
