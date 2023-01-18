#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
long long int  qu[200005];
long long int v[200005];
vector <long long int> q;
priority_queue <long long int> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int n, first;
    first=0;
    cin >> n;
    for (long long int i=0 ; i<n ; i++){
        cin >> qu[i];
        if (qu[i]==1) cin>>v[i];
    }
    for (long long int i=0 ; i<n ; i++){
        switch (qu[i]){
        case 1:    q.push_back(v[i]);   break;
        case 2:
            for (int i=0 ; i<q.size() ; i++)    pq.push(q[i]);
            q.clear();
            break;
        case 3:
            if (pq.empty() && q.empty())  cout << "Oh Oh\n";
            else if (pq.empty()){
                cout<<q[0]<<endl;
                q.erase(q.begin());
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
            break;
        }

    }
}
