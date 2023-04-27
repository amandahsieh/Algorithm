#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*宣告變數：c case 數   l 可見範圍的長度   r 可降落範圍長度   s 地圖   pos 座標*/
int c, l, r;
vector <string> s;
int ans=0;
class pos{
public:
    int x, y;
};

/*---bfs 搜尋視野內最大面積：每次在上下左右加入草地區域 (push)，設為^避免重複---*/
int bfs(int mx,int my){
    int t=0;
    pos m;
    m.x = mx;
    m.y = my;
    queue <pos> p;
    s[m.x][m.y] = '^';
    p.push(m);
    int tx, ty;
    while (!p.empty()){
        tx = p.front().x;
        ty = p.front().y;
        p.pop();
        t++;
        if (tx > 0){
            if (s[tx-1][ty]=='_'){
                s[tx-1][ty] = '^';
                pos tl;
                tl.x = tx-1;
                tl.y = ty;
                p.push(tl);
            }
        }
        if (tx < l-1){
            if (s[tx+1][ty]=='_'){
                s[tx+1][ty] = '^';
                pos tr;
                tr.x = tx+1;
                tr.y = ty;
                p.push(tr);
            }
        }
        if (ty > 0){
            if (s[tx][ty-1]=='_'){
                s[tx][ty-1] = '^';
                pos tu;
                tu.x = tx;
                tu.y = ty-1;
                p.push(tu);
            }
        }
        if (ty < l-1){
            if (s[tx][ty+1]=='_'){
                s[tx][ty+1] = '^';
                pos td;
                td.x = tx;
                td.y = ty+1;
                p.push(td);
            }
        }
    }
    return t;
}

int main (){
    cin >> c;
    while (c--){
				/*-------------------設定、輸入變數-------------------*/
        ans = 0;
        cin >> l >> r;
        s.resize(l);
        for (int i=0 ; i<l ; i++)   cin >> s[i];
				/*---在可降落範圍內，搜尋最大草地面積 (範圍為視野內)---*/
        for (int i=l/2-r ; i<=l/2+r ; i++){
            for (int j=l/2-r ; j<=l/2+r ; j++){
                if (s[i][j]=='_'){
                    s[i][j] = '^';
                    ans = max(ans, bfs(i, j));
                }
            }
        }
        cout << ans << "\n";
        s.clear();
    }
}
