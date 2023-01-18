#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Node{
public:
    long long int num;
    Node* lchild;
    Node* rchild;
};

class Tb{
public:
    long long int val;
    int ino;
};

int N;
int cnt = 0;
vector <Tb> a;
vector <int> inorder;
vector <int> postorder;

Node* build(int instart, int inlast, int pstart, int plast){
    if (instart > inlast || pstart > plast) return NULL;
    Node* root = new Node;
    root->num = a[postorder[plast]].val;
    int mid = a[postorder[plast]].ino;
    int len = mid - instart;
    root->lchild = build(instart, mid-1, pstart, pstart + len -1);
    root->rchild = build(mid+1, inlast, pstart+len, plast-1);
    if (root->lchild)   if (root->num < root->lchild->num)  cnt++;
    if (root->rchild)   if (root->num < root->rchild->num)  cnt++;
    return root;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    a.resize(N+5);
    inorder.resize(N);
    postorder.resize(N);
    int tmp;
    for (int i=1 ; i<=N ; i++)  cin >> a[i].val;
    for (int i=0 ; i<N ; i++){
        cin >> inorder[i];
        a[inorder[i]].ino = i;
    }
    for (int i=0 ; i<N ; i++)   cin >> postorder[i];
    Node* Tree = build(0, N-1, 0, N-1);
    cout << cnt;
}




/*
int N;
int cnt = 0;
vector <long long int> a;
vector <int> inorder;
vector <int> postorder;

void check (int pstart, int pend, int instart, int inend){
    if (pstart == pend)    return;
    int division = 0;
    while (inorder[division]!=postorder[pend])  division++;
    if (a[postorder[pend]] < a[postorder[pend-1]])    cnt++;
    if (pend - pstart == 1) return;
    if (division>=pstart && division < pend){
        if (a[postorder[pend]] < a[postorder[division-1]]) cnt++;
    }
    if (division-1 > pstart && division-1 > instart)    check(pstart, division-1, instart, division-1);
    if (division < pend-1 && division+1 < inend)   check(division, pend-1, division+1, inend);
}

int main (){
    cin >> N;
    a.resize(N+5);
    inorder.resize(N+5);
    postorder.resize(N+5);
    for (int i=1 ; i<=N ; i++)  cin >> a[i];
    for (int i=0 ; i<N ; i++)   cin >> inorder[i];
    for (int i=0 ; i<N ; i++)   cin >> postorder[i];
    check(0, N-1, 0, N-1);
    cout << cnt;
}
*/
