#include <iostream>
#include <cstring>
using namespace std;
int findFirst(int *arr, int n){
    int first = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            first = i;
            break;
        }
    }
    return first;
}
int findLast(int *arr, int n){
    int temp = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            temp = i;
        }
    }
    return temp;
}
bool isSorted(int *arr, int n){
    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]) return false;
    }
    return true;
}
void scan(int *arr, int n){
    for(int i = 0; i <n; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
}
void r3(int *arr, int first, int last){
    for(int i = first; i <= last; i++){
        arr[i] *= -1;
    }
    for(int i = 0; i <= (last -first)/2; i++){
        int temp = arr[first+i];
        arr[first+i] = arr[last -i];
        arr[last-i] = temp;
    }
}
int r2(int *arr, int first, int last,int n){
    int *temp;
    temp = new int[n];
    for(int i = 0; i < n;i++){
        temp[i] = arr[i];
    }
    int result = 0;
    if(last > n){
        return 0;
    }
    if(first < 0){
        return 0;
    }
    for(int i = first; i <= last; i++){ //음수 -> 양수
        arr[i] *= -1;
    }
    for(int i =0; i <= (last - first)/2 ; i++){
        int temp = arr[first+i];
        arr[first+i] = arr[last-i];
        arr[last-i] = temp;
    }
    if(isSorted(arr,n)){
        result++;
        return result;
    }
    else{
        memcpy(arr, temp, sizeof(int)*n);
    }
    return result;
}
int r(int *arr, int n){
    int *temp;
    temp = new int[n];
    int result,first,last;
    for(int i = 0; i <n; i++){
        temp[i] = arr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n ; j++){
            r3(arr,i,j);
            first = findFirst(arr, n);
            last = findLast(arr, n);
            result = r2(arr, first, last,n);
            if(result == 1){
                return 1;
            }
            else{
                memcpy(arr, temp, sizeof(int)*n);
            }
        }
    }
    return 0;
}
int total(int n){
    int *list;
    list = new int[n];
    scan(list,n);
    int first,last,result, res=0;
    first= findFirst(list,n);
    last = findLast(list, n);
    result = r2(list, first, last,n);
    if(result == 1){
        return 1;
    }
    else{
        res = r(list, n);
        if(res == 1){
            return 2;
        }
        else{
            return 3;
        }
    }
}
void out(int n){
    if(n == 1){
        cout << "one" <<endl;
    }
    else if(n==2){
        cout <<"two"<< endl;
    }
    else
        cout <<"over"<< endl;
}
int main(){
    int n;
    cin >> n;
    int num1, num2, num3, num4, num5;
    num1 = total(n);
    num2 = total(n);
    num3 = total(n);
    num4 = total(n);
    num5 = total(n);

    out(num1);
    out(num2);
    out(num3);
    out(num4);
    out(num5);
}
