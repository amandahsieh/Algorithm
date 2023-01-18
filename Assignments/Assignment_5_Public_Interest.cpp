#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class connect_{
public:
    int s1, s2;
    long long int cost;
    int rum = 0;
};

int v, e, s;
vector <connect_>    connect;
vector <int>    sp;
vector <int>    com1;
vector <int>    com2;

int looking1(int aa){
    if (aa!= com1[aa])   return looking1(com1[aa]);
    else    return aa;
}


int looking2(int bb){
    if (bb!= com2[bb])   return looking2(com2[bb]);
    else    return bb;
}

bool bigger(connect_ a1, connect_ a2){
    return a1.cost>a2.cost;
}

bool smaller(connect_ a1, connect_ a2){
    return a1.cost<a2.cost;
}

int main (){
    while (cin >> v){   //輸入形式為 EOF 前
        int cannot=0;
        cin >> e >> s;
        long long int c1 = 0, c2 = 0;
        connect.resize(e);
        sp.resize(v);
        //輸入 + 設定好所有的連線
        for (int i=0 ; i<e ; i++){
            cin >> connect[i].s1 >> connect[i].s2 >> connect[i].cost;
        }
        //輸入需特別處理的點
        for (int i=0 ; i<s ; i++){
            int tmp;
            cin >> tmp;
            sp[tmp] = 1;
        }
        //cout << "input end\n";
        for (int i=0 ; i<e ; i++){
            if (sp[connect[i].s1] || sp[connect[i].s2]) connect[i].rum = 1;
        }
        //cout << "sp end\n";
        //c1 開始處理
        sort(connect.begin(), connect.end(), bigger);
        //cout << "sort end\n";
        com1.resize(v);
        for (int i=0 ; i<v ; i++)   com1[i] = i;
        //cout << "component1 initialized\n";
        for (int i=0 ; i<e ; i++){
            int first = looking1(connect[i].s1);
            com1[connect[i].s1]=first;
            int second = looking1(connect[i].s2);
            com1[connect[i].s2]=second;
            if (first == second)    continue;
            c1 += connect[i].cost;
            com1[second] = first;
        }
        //cout << "merged\n";
        int head = looking1(0);
        //cout << head;
        for (int i=1 ; i<v ; i++){
            //cout << i << head << looking1(i)<<"\n";
            if (looking1(i)!=head){
                cannot = 1;
            }
        }
        //cout << "case1 end\n";

        //case2
        //sort(connect.begin(), connect.end(), smaller);
        com2.resize(v);
        for (int i=0 ; i<v ; i++)   com2[i] = i;
        for (int i=e-1 ; i>=0 ; i--){
            if (connect[i].rum == 0)    continue;
            int first = looking2(connect[i].s1);
            com2[connect[i].s1]=first;
            int second = looking2(connect[i].s2);
            com2[connect[i].s2]=second;
            c2 += connect[i].cost;
            com2[second] = first;
        }
        //cout << "c2 after rumor: "<<c2<<"\n";
        for (int i=e-1 ; i>=0 ; i--){
            if (connect[i].rum == 1)    continue;
            int first = looking2(connect[i].s1);
            com2[connect[i].s1]=first;
            int second = looking2(connect[i].s2);
            com2[connect[i].s2]=second;
            /*
            cout << "first: ";
            cout << connect[i].s1 << "  "<< first<<"\n";
            cout << "second: ";
            cout << connect[i].s2 << "  "<< second<<"\n";
            */
            if (first == second)    continue;
            c2 += connect[i].cost;
            //cout << connect[i].cost << endl;
            com2[second] = first;
        }
        int head2 = looking2(0);
        for (int i=1 ; i<v ; i++){
            if (looking2(i)!=head2){
                cannot = 1;
            }
        }
        /*
        for (int i=0 ; i<s ; i++){
            for (int j=0 ; j<num[sp[i]] ; j++){
                if (connect[record[i][j]].been2==1) continue;
                c2+=connect[record[i][j]].cost;
                connect[record[i][j]].been2 = 1;
            }
        }*/
        if (cannot)  cout <<"no\n";
        else    cout <<c1-c2 <<"\n";
        //else    cout <<"ANS: "<< c1-c2 <<"\n" << c1 << "  " << c2 <<endl;
        //每次都需要清空記憶體！
        connect.clear();
        com1.clear();
        com2.clear();
        sp.clear();
    }
}
