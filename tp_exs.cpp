#include<iostream>
using namespace std;

int degitsum(int num){
    int holder;
    int sum;

    holder = num;
    sum = 0;
    while(!num){
        holder = num % 10;
        sum += holder;
        num = num / 10;
    }

    return holder;
}

void minandmax(int* arr,int size){
    if(!size)
        return;
    
    int imin;
    int imax;
    int i;

    i = 0;
    imin = 0;
    imax = 0;
    while(i < size){
        if(arr[i] < arr[imin]){
            imin = i;
        }
        if(arr[i] > arr[imax]){
            imax = i;
        }
        i++;
    }
    cout<<"the in is: "<<arr[imin]<<" and the max is: "<<arr[imax]<<endl;

}

void inverse(int* arr,int size){
    int i;
    int tmp;
    int mid;

    i = 0;
    mid = ((int)(size / 2)) + 1;
    while(i < mid){
        tmp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = tmp;
        i++;
    }
}



/*int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    int i = 0;
    while(i < 13){
        cout<<", "<<arr[i];
        i++;
    }

    cout<<endl;
    inverse(arr,13);

    i = 0;
    while(i < 13){
        cout<<", "<<arr[i];
        i++;
    }
    cout<<endl;
    return 0;
}*/

int main (){
    float x;
    x = ((float)183)/10;
    cout<<x<<endl;
}