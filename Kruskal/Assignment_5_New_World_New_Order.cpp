#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class neighbor_cost{
public:
    int a, b;
    long long int cost;
    int weak = 0;
};
vector <neighbor_cost> con;
int v, e, w;
long long int tcost;
vector <int> component;
vector <int> weak_;

bool bigger(neighbor_cost a1, neighbor_cost a2){
    return a1.cost<a2.cost;
}

long long int looking(long long int a){
    if (a!= component[a])   return looking(component[a]);
    else    return a;
}

int main (){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    while (cin >> v){
        int cannot = 0;
        tcost = 0;
        cin >> e >> w;
        component.resize(v);
        for (int i=0 ; i<v ; i++)   component[i] = i;
        con.resize(e);
        weak_.resize(v);
        int w_;
        for (int i=0 ; i<e ; i++)   cin >> con[i].a >> con[i].b >> con[i].cost;
        for (int i=0 ; i<w ; i++){
            cin >> w_;
            weak_[w_] = 1;
        }
        for (int i=0 ; i<e ; i++)   if (weak_[con[i].a] || weak_[con[i].b]) con[i].weak = 1;
        sort(con.begin(), con.begin()+e, bigger);
        for (int i=0 ; i<e ; i++){
            if (con[i].weak)    continue;
            int first = looking(con[i].a);
            component[con[i].a]=first;
            int second = looking(con[i].b);
            component[con[i].b]=second;
            if (first == second)    continue;
            tcost += con[i].cost;
            component[second] = first;
        }
        int compo = -1;
        for (int i=0 ; i<v ; i++){
            if (weak_[i]==0){
                compo = looking(i);
                break;
            }
        }
        for (int i=0 ; i<v ; i++){
            if (weak_[i])   continue;
            int head = looking(i);
            //cout << i << "  " << head << endl;
            if (head != compo){
                cannot = 1;
                break;
            }
        }
        if (cannot){
            cout << -1 << "\n";
            component.clear();
            con.clear();
            weak_.clear();
            continue;
        }
        for (int i=0 ; i<e ; i++){
            if (con[i].weak!=1) continue;
            int first = looking(con[i].a);
            int second = looking(con[i].b);
            if (first == second)    continue;
            tcost += con[i].cost;
            component[second] = first;
        }
        compo = looking(0);
        for (int i=0 ; i<v ; i++){
            //if (weak_[i]==0)    continue;
            int head = looking(i);
            //cout << i << "  " << head << endl;
            if (head != compo){
                cannot = 1;
                break;
            }
        }
        if (cannot){
            cout << -1 << "\n";
            component.clear();
            con.clear();
            weak_.clear();
            continue;
        }
        cout << tcost << "\n";
        component.clear();
        con.clear();
        weak_.clear();
    }
}
