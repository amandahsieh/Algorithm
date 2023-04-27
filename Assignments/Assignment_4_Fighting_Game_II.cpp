#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/*------------�ܼƳ]�w------------*/
/*---------b�G�i�H���h��----------*/
/*--from�G�q���Ǧ�m�i�H����o��--*/
/*---------lnum�G���׿�X---------*/
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
    /*�إߦn�i��ӷ����W��A�B�ѩ�إ߶��ǡA�Ĥ@�Ӽƥ����̤p��*/
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
