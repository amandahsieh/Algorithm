#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
long long int N;
struct people{
public:
    string name;
    long long int info[5];
};
vector <long long int> groupmemberidx[5];
vector <people> peopleinfo;
int order[5][5];
int tmporder[5];

struct bigger{
    bool operator()(const long long int &n, const long long int &m){
        if (peopleinfo[n].info[tmporder[0]] > peopleinfo[m].info[tmporder[0]])  return 1;
        else if (peopleinfo[n].info[tmporder[0]] == peopleinfo[m].info[tmporder[0]]){
            if (peopleinfo[n].info[tmporder[1]] > peopleinfo[m].info[tmporder[1]])  return 1;
            else if (peopleinfo[n].info[tmporder[1]] == peopleinfo[m].info[tmporder[1]]){
                if (peopleinfo[n].info[tmporder[2]] > peopleinfo[m].info[tmporder[2]])  return 1;
                else if (peopleinfo[n].info[tmporder[2]] == peopleinfo[m].info[tmporder[2]]){
                    if (peopleinfo[n].info[tmporder[3]] > peopleinfo[m].info[tmporder[3]])  return 1;
                    else if (peopleinfo[n].info[tmporder[3]] == peopleinfo[m].info[tmporder[3]]){
                        if (lexicographical_compare(peopleinfo[n].name.begin(), peopleinfo[n].name.end(), peopleinfo[m].name.begin(), peopleinfo[m].name.end()))    return 1;
                    }
                }
            }
        }
        return 0;
    }
};

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    peopleinfo.resize(N+5);
    string o;
    /*build the orders*/
    for (int i=0 ; i<4 ; i++){
        cin >> o;
        for (int j=0 ; j<4 ; j++){
            if (o[j] == 'H')        order[i][j] = 0;
            else if (o[j] == 'W')   order[i][j] = 1;
            else if (o[j] == 'I')   order[i][j] = 2;
            else if (o[j] == 'E')   order[i][j] = 3;
        }
    }

    for (long long int i=0 ; i<N ; i++){
        cin >> peopleinfo[i].name;
        for (int j=0 ; j<4 ; j++)   cin >> peopleinfo[i].info[j];
    }

    for (long long int i=0 ; i<N ; i++){
        long long int mm=0;
        int whichgroup = 0;
        for (int j=0 ; j<4 ; j++){
            if (peopleinfo[i].info[j] > mm){
                mm = peopleinfo[i].info[j];
                whichgroup = j;
            }
        }
        groupmemberidx[whichgroup].push_back(i);
    }

    for (int i=0 ; i<4 ; i++){
        if (groupmemberidx[i].size()<=1)    continue;
        for (int j=0 ; j<4 ; j++)   tmporder[j] = order[i][j];
        sort(groupmemberidx[i].begin(), groupmemberidx[i].end(), bigger());
    }
    for (int i=0 ; i<4 ; i++){
        char groupname = 'A'+i;
        cout << "Group" << groupname << ":";
        if (groupmemberidx[i].size() ==0) cout << "No Audience";
        cout << "\n";
        for (long long int j=0 ; j<groupmemberidx[i].size() ; j++){
            cout << peopleinfo[groupmemberidx[i][j]].name << "\n";
        }
    }
}


























/*
#include <iostream>
#include <cstring>
#include <cmath>
#include<algorithm>
#include <vector>
using namespace std;

struct Names{
public:
    string name;
    long int info[6];
};
int order[6][6];   //組內排序依據
int tmporder[6];
long int groupsize[6]={1,1,1,1,1,1};
Names datas[1000100];
long int  group[6][1000100];
long int num, mm, g, i, j;
string o;
char gr;
struct bigger{
    bool operator()(const long int& n,const long int& m) const{
        if (n==m ||n==0 ||m==0) return 1;
        if (datas[n].info[tmporder[0]] > datas[m].info[tmporder[0]])    return 1;
        else if (datas[n].info[tmporder[0]] == datas[m].info[tmporder[0]]){
            if (datas[n].info[tmporder[1]] > datas[m].info[tmporder[1]])  return 1;
            else if (datas[n].info[tmporder[1]] == datas[m].info[tmporder[1]]){
                if (datas[n].info[tmporder[2]] > datas[m].info[tmporder[2]])  return 1;
                else if (datas[n].info[tmporder[2]] == datas[m].info[tmporder[2]]){
                    if (datas[n].info[tmporder[3]] > datas[m].info[tmporder[3]])  return 1;
                    else if (datas[n].info[tmporder[3]] == datas[m].info[tmporder[3]]){
                        if (lexicographical_compare(datas[n].name.begin(), datas[n].name.end(), datas[m].name.begin(), datas[m].name.end()))    return 1;
                    }
                }
            }
        }
        return 0;
    }

};


int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> num; //總共幾人
    for (i=0 ; i<4 ; i++){
        cin>>o;
        for (j=0 ; j<4 ; j++){
            if (o[j]=='H')  order[i][j]=0;
            else if (o[j]=='W')  order[i][j]=1;
            else if (o[j]=='I')  order[i][j]=2;
            else if (o[j]=='E')  order[i][j]=3;
        }
    }
    for (i=1 ; i<=num ; i++){
        mm = 0;
        g = -1;
        cin >> datas[i].name >> datas[i].info[0] >> datas[i].info[1] >> datas[i].info[2] >> datas[i].info[3];
        for (j=0 ; j<4 ; j++){
            if (datas[i].info[j] > mm){
                g = j;
                mm = datas[i].info[j];
            }
        }
        group[g][groupsize[g]]=i;
        groupsize[g]++;
    }

    for (i=0 ; i<4 ; i++){
        if (groupsize[i]<=1) continue;
        for (j=0 ; j<4 ; j++)   tmporder[j] = order[i][j];
        sort(group[i]+1, group[i]+groupsize[i], bigger());
    }
    for (i=0 ; i<4 ; i++){
        gr = 65+i;
        cout<<"Group "<<gr<<":";
        if (groupsize[i]<2){
            cout<<" No Audience"<<"\n";
            continue;
        }
        cout<<endl;
        for (j=1 ; j<groupsize[i] ; j++){
            cout<<datas[group[i][j]].name<<"\n";
        }
    }
}
*/
