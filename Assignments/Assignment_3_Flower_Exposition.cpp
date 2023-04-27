#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> l(n,0);
    int maxnum = 0;
    for (int i=0 ; i<n ; i++)   cin >> l[i];
    vector <vector <int>> ans(1, vector<int>(1,l[0]));
    for (int i=1 ; i<n ; i++){
        int newone=1;
        for (int j=0 ; j<ans.size() ; j++){
            if (ans[j][j]>l[i]){
                if (j==0)   ans[j][j] = l[i];
                else if (ans[j][j-1]<l[i])  ans[j][j] = l[i];
                if (j!=0 && (ans[j-1][j-1]<l[i])){
                    ans[j] = ans[j-1];
                    ans[j].push_back(l[i]);
                }
                newone = 0;
                break;
            }
            else if (ans[j][j]>=l[i])   newone=0;
        }
        if (newone){
            ans.push_back(ans[ans.size()-1]);
            ans[ans.size()-1].push_back(l[i]);
        }
        /*
        for (int k=0 ; k<ans.size() ; k++){
            for (int r=0 ; r<=k ; r++)  cout << ans[k][r] << "\t";
            cout << "\n";
        }
        cout << "\n";
        */
    }
    //cout << "\n";
    cout << ans.size();
}
