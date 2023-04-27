#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/*------------變數設定------------*/
/*---------b：可以走多遠----------*/
/*--from：從哪些位置可以走到這裡--*/
/*---------lnum：答案輸出---------*/
vector <int> b;
vector <int> from;
int lnum=0;
int tmp;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    tmp = N-1;
    b.resize(N+5);
    from.resize(N+5, -1);
    /*建立好可能來源的名單，且由於建立順序，第一個數必為最小值*/
    for (int i=0 ; i<N ; i++)   cin >> b[i];
    for (int i=0 ; i<N ; i++){
        for (int j=1 ; j<=b[i] ; j++)   if (from[i+j]<0)    from[i+j] = i;
    }
    while (tmp!=0){
        tmp = from[tmp];
        lnum++;
    }
    cout << lnum;
}
