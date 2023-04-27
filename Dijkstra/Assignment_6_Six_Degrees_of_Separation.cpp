#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long int e, v;
vector <string> names;
class relate{
public:
    string name_;
    vector <long long int> ne;
};
vector<relate> r;


long long int bfs(long long int s){
    long long int d=-1;
    vector <int> visited(v,0);
    queue <long long int> q;
    q.push(s);
    visited[s]=1;
    while (!q.empty()){
        ++d;
        long long int qs = q.size();
        for (long long int qq=0 ; qq<qs; qq++){
            long long int recent = q.front();
            q.pop();
            for (long long int rn=0 ; rn<r[recent].ne.size() ; rn++){
                long long int t=r[recent].ne[rn];
                if (visited[t]) continue;
                visited[t]=1;
                q.push(t);
            }
        }
    }
    for (long long int qq=1 ; qq<v ; qq++){
        if (visited[qq]==0){
            d=-1;
            break;
        }
    }
    return d;
}

int main (){
    while (cin >> e){
        unordered_map<string, int> um;
        string a, b;
        v=1;
        r.resize(2*e+5);
        for (long long int i=0 ; i<e ; i++){
            cin >> a >> b;
            if (!um[a]){
                um[a]=v++;
                //cout << v;
            }
            if (!um[b]){
                um[b]=v++;
            }
            r[um[a]].ne.push_back(um[b]);
            r[um[b]].ne.push_back(um[a]);
            r[um[a]].name_=a;
            r[um[b]].name_=b;
        }
        /*
        for (int i=1 ; i<=v ; i++){
            cout << r[i].name_<<": \n";
            for (int j=0 ; j<r[i].ne.size() ; j++) cout << r[i].ne[j]<<" "<< endl;
            cout << endl;
        }
*/
        long long int depth = -1;
        for (long long int i=1 ; i<v ; i++){
            long long int tmp = bfs(i);
            if (depth<tmp)    depth = tmp;
        }
        cout << depth<<"\n";
        r.clear();
        names.clear();
    }
}
