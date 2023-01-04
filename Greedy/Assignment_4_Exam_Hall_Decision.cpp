#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;
/*---記錄每個學生到各教室的距離、兩者距離差，以及距何者較近---*/
class student{
public:
    int which;
    int cd;
    int cost[2];
};

/*--------------------將差別較大的排前面--------------------*/
bool comparing(student a, student b){
    return a.cd > b.cd;
}

vector <student> s;
int N;
int num[3];
long long int ans = 0;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    s.resize(N);
    num[0] = 0;
    num[1] = 0;
		/*--------輸入的同時判斷距離哪間教室較近，並計算距離差---------*/
    for (int i=0 ; i<N ; i++){
        cin >> s[i].cost[0] >> s[i].cost[1];
        s[i].cd = abs(s[i].cost[0] - s[i].cost[1]);
        s[i].which = (s[i].cost[0]<s[i].cost[1])? 0:1;
    }
		/*---根據距離差進行排序，後續優先安排距離差較大者到較近的教室---*/
    sort(s.begin(), s.end(), comparing);
    for (int i=0 ; i<N ; i++){
        int tmp = s[i].which;
        if (num[tmp]<(N/2)){
            num[tmp]++;
            ans += s[i].cost[tmp];
        }
        else{
            if (tmp == 0){
                num[1]++;
                ans += s[i].cost[1];
            }
            else{
                num[0]++;
                ans += s[i].cost[0];
            }
        }
    }
    cout << ans;

}
