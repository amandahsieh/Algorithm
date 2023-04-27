#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class vertex{
public:
    vector <int> ad;
    vector <long long int> cost;
};
int l,r,s;
vector <long long int> ld; //location dose
vector <vertex> v;
vector <long long int> d;
vector <int> shelter;
int start;

void di(int sv){
    queue <int> q;
    q.push(sv);
    d[sv]=ld[sv];
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (int cn=0 ; cn<v[cur].ad.size() ; cn++){
            long long int checking = v[cur].ad[cn];
            if (d[checking]<0 || d[checking]>d[cur]+v[cur].cost[cn]+ld[checking]){
                q.push(checking);
                d[checking] = d[cur]+v[cur].cost[cn]+ld[checking];
            }
        }
    }
}

int main (){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    while(cin >> l){
        cin >> r >> s;
        ld.resize(l);
        v.resize(l);
        d.resize(l,-1);
        shelter.resize(s);
        for (int i=0 ; i<l ; i++)   cin >> ld[i];
        for (int i=0 ; i<r ; i++){
            int a, b, c;
            cin >> a >> b >> c;
            v[a].ad.push_back(b);
            v[a].cost.push_back(c);
            v[b].ad.push_back(a);
            v[b].cost.push_back(c);
        }
        for (int i=0 ; i<s ; i++)   cin >> shelter[i];
        cin >> start;
        di(start);
        long long int ans=-1;
        for (int i=0 ; i<l ; i++)   cout << d[i]<<"  ";
        cout << endl;
        for (int i=0 ; i<s ; i++){
            if (d[shelter[i]]>0 && (ans<0 || ans>d[shelter[i]]))    ans = d[shelter[i]];
        }
        //if (start < 0 || start >= l)    ans = -1;
        //cout << ans << "\n";
        v.clear();
        d.clear();
        ld.clear();
        shelter.clear();
    }
}
