#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
long long int c;
class   pos{
public:
    int x,y;
};
int l, r;
vector <string> mid;
int ans;

int bfs(int starti, int startj, int last){
    int t=0;
    queue <pos> q;
    pos tp;
    tp.x = starti;
    tp.y = startj;
    q.push(tp);
    mid[starti][startj]='^';
    int si, sj;
    while (!q.empty()){
        si = q.front().x;
        sj = q.front().y;
        q.pop();
        t++;
        if (sj>0){
            if (mid[si][sj-1]=='_') {
                mid[si][sj-1]='^';
                tp.x = si;
                tp.y = sj-1;
                q.push(tp);
            }
        }
        if (sj<last){
            if (mid[si][sj+1]=='_') {
                mid[si][sj+1]='^';
                tp.x = si;
                tp.y = sj+1;
                q.push(tp);
            }
        }
        if (si>0){
            if (mid[si-1][sj]=='_') {
                mid[si-1][sj]='^';
                tp.x = si-1;
                tp.y = sj;
                q.push(tp);
            }
        }
        if (si<last){
            if (mid[si+1][sj]=='_') {
                mid[si+1][sj]='^';
                tp.x = si+1;
                tp.y = sj;
                q.push(tp);
            }
        }
    }
    return t;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> c;
    while (c--){
        ans=0;
        cin >> l >> r;
        int m = l/2;
        mid.resize(l+5);
        for (int i=0 ; i<l ; i++) cin >> mid[i];
        for (int i=m-r ; i<=m+r ; i++){
            for (int j=m-r ; j<=m+r ; j++){
                if (mid[i][j]!='_') continue;
                mid[i][j]='^';
                int thisans = bfs(i, j, l-1);
                if (ans<thisans)    ans = thisans;
            }
        }
        cout << ans << endl;
        mid.clear();
    }
}
/*
5
8 3
________
________
________
________
________
________
________
________
8 3
^^^^^^^^
____^^__
^^^_____
^^^___^_
________
_^^_____
___^^___
____^^^^
8 3
^^^^^^^^
^^^^^^^^
^^^^^^^^
^^^^^^^^
^^^^^^^^
^^^^^^^_
^^^^^^_^
^^^^^_^^
4 1
^^^^
^^__
^^^^
^^_^
4 1
____
^___
^^__
^^__

*/
