#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

long long int n, t;
long long int w[305];
long long int tmp, tmpsum;
long long int combination=0;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>t;
    for (long long int i=0 ; i<n ; i++){
        cin>>w[i];
    }
    sort(w, w+n);
    for (long long int i=0 ; i<n-3 ; i++){
        if (i>0 && w[i]==w[i-1])    continue;
        tmpsum=w[i];
        if ((tmpsum > t && w[i+1]>0) ||(tmpsum < t && w[n-1]<0) ) continue;
        for (long long int j=i+1 ; j<n-2 ; j++){
            if (j>i+1 && w[j]==w[j-1])    continue;
            tmpsum=w[i] + w[j];
            if ((tmpsum > t && w[j+1]>0) || (tmpsum < t && w[n-1]<0))   continue;
            for (long long int k=j+1 ; k<n-1 ; k++){
                if (k>j+1 && w[k]==w[k-1])  continue;
                tmpsum=w[i] + w[j] + w[k];
                if ((tmpsum > t && w[k+1]>0) || (tmpsum < t && w[n-1]<0))   continue;
                for (long long int r=k+1 ; r<n ; r++){
                    if (r>k+1 && w[r]==w[r-1])  continue;
                    tmpsum=w[i] + w[j] + w[k] + w[r];
                    if ((tmpsum > t && w[r+1]>0) || (tmpsum < t && w[n-1]<0)) continue;
                    if (tmpsum==t){
                        combination++;
                    }
                }
            }
        }
    }
    if (combination==0) cout<<"FeiDooDoo_Zuo_Wei_Men";
    else    cout<<combination;
}
