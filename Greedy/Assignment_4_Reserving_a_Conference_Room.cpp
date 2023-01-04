#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class reserve{
public:
    int s, f;
};

int N;
int num[1010];
int m=0, last=-1;
vector <vector <int>> F;
vector <reserve> r;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    F.resize(1010, vector <int> (N, -1));
    r.resize(N);
    for (int i=0 ; i<N ; i++){
        cin >> r[i].s >> r[i].f;
        F[r[i].f][num[r[i].f]++] = r[i].s;
        if (r[i].f>m)   m=r[i].f;
    }
    for (int i=1 ; i<=m ; i++){
        sort(F[i].begin(), F[i].begin()+num[i], greater<int>());
    }
    for (int i=1 ; i<=m ; i++){
        if (num[i]>0){
            if (F[i][0]<last)   continue;
            cout << F[i][0] << " "<<i << "\n";
            last = i;
        }
    }
}
