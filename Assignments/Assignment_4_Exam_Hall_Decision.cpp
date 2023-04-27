#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

//�O���C�ӤH��ⶡ�ЫǶ����Z���t(cd)�A�H�������@�������(s)
class diff{
public:
    int s;
    int cd;
    int cost[2];
};

//�H��
int N;
int num[3];
long long int totalcost = 0;
//�C�ӤH������
vector <diff> d;
vector <vector <int>> cost;

bool comparing(diff a, diff b){
    return a.cd>b.cd;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    d.resize(N);
    cost.resize(N, vector<int> (2));
    for (int i=0 ; i<N ; i++){
        cin >> d[i].cost[0] >> d[i].cost[1];
        d[i].cd = abs(d[i].cost[0] - d[i].cost[1]);
        d[i].s  = d[i].cost[0]<d[i].cost[1] ? 0:1;
    }
    num[0] = 0;
    num[1] = 0;
    sort(d.begin(), d.end(), comparing);
    for (int i=0 ; i<N ; i++){
        if (num[d[i].s] < N/2){
            totalcost += d[i].cost[d[i].s];
            num[d[i].s]++;
        }
        else{
            if (d[i].s==0){
                totalcost += d[i].cost[1];
                num[1]++;
            }
            else{
                totalcost += d[i].cost[0];
                num[0]++;
            }
        }
    }
    cout << totalcost;
}
