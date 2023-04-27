#include <iostream>
#include <algorithm>
using namespace std;
long long int N, i;
long long int arr[2000010]={0};

long long int becomesame(long long int start, long long int last){
    if (last - start ==1)   return abs(arr[start]-arr[last]);
    nth_element(arr+start, arr+(start+last)/2, arr+(last+1));
    long long int tmp=0;
    long long int mid = (start + last)/2;
    for (i=start; i<mid; i++)   tmp += arr[mid]-arr[i];
    for (i=mid; i<last+1; i++)  tmp += arr[i]-arr[mid];
    return tmp;
}

long long int counting(long long int start, long long int last){
    if (last-start<=1)  return 0;
    else {
        long long int tmp1 = counting(start, (start + last)/2);
        long long int tmp2 = counting((start + last)/2+1, last);
        long long int same1 = becomesame((start + last)/2+1, last);
        long long int same2 = becomesame(start, (start + last)/2);
        return (min((tmp1 + same1), (tmp2 + same2)));
    }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (i=0 ; i<N ; i++) cin >> arr[i];
    cout << counting(0, N-1);
}
