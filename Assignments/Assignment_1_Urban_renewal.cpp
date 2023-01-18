#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
/*
int main (){
    long long int n, k,sum;
    vector <int> power(65);
    int now=0;
    int len=0;
    cin>>n>>k;
    long long int minsum=0;
    long long int nn=n;
    while (nn>0){
        if (nn%2==1){
            minsum++;
            power[now]++;
            //cout<<now<<endl;
            len=now;
        }
        now++;
        nn/=2;
    }
    if (minsum>k || n<k){
        cout<<"NO"<<endl;
        return 0;
    }
    else {
        cout<<"YES"<<endl;
        sum = minsum;
        while (sum<k){
            while (power[len]){
                sum++;
                power[len]--;
                power[len-1]+=2;
                if (sum==k) break;
            }
            if (sum==k){
                if (power[len]==0)  len--;
                break;
            };
            len--;
        }
    }
    if (sum==k){

        for (int i=0 ; i<=len ; i++){
            for (int j=0 ; j<power[i] ; j++){
                long long int ans=pow(2, i);
                cout<<pow(2,i)<<" ";
            }
        }
    }
}*/


long long int n, k;
vector <long long int> c;
int same=0;
long long int sum=0;
int impossible = 0;
int  main (){
    cin>>n>>k;
    if (k>n) {
        cout<<"NO"<<endl;
        return 0;
    }
    c.push_back(n);
    //c[i] 代表有幾個 2 的 i 次方
    sum=n;
    while (same==0){
        if (sum==k) same = 1;
        else if (sum < k) break;
        else{
            //如果目前已經是最大位數，無法再減少 sum
            if (c[c.size()-1]==1){
                cout<<"NO"<<endl;
                return 0;
            }
            long long int temp=c.size()-1;
            c.push_back(c[temp]/2);
            sum = sum - c[temp]/2;
            c[temp]=c[temp]%2;
        }
    }
    if (same==0){
        if (c[c.size()-1]==1){
            impossible = 1;
            cout<<"NO"<<endl;
            return 0;
        }
        while (same==0){
            sum+=1;
            c[c.size()-1]--;
            c[c.size()-2]+=2;
            if (sum==k) same=1;
        }
    }
    if (same ==1){
        cout<<"YES\n";
        for (int i=c.size()-1 ; i>=0 ; i--){
            for (int j=0 ; j<c[i] ; j++){
                long long int ans = pow(2,i);
                cout<<ans<<" ";
            }
        }
    }
}
