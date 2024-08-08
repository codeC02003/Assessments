#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int N ,int i){

        int largest=i;

        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if(l<N && arr[l]>largest)
            largest=l;

        if(r<N && arr[r]>largest)
            largest=r;

        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify( arr , N , largest);
        }

}

void Heapsort(int arr[] ,int N){
    for(int i = N/2 - 1 ; i >= 0 ; i--)
        heapify(arr , N , i);

    for(int i = N - 1 ; i > 0 ; i--){
        swap(arr[0],arr[i]);
        heapify(arr, i , 0);
    }
}



void insertion(int arr[], int N){
    int i,key,j;
    for(i=1;i<N;i++){
    key=arr[i];
    j=i-1;
    while(j>=0 && arr[j]>key){
         arr[j+1]=arr[j];
         j=j-1;
    }
    arr[j+1]=key;

    }

}

void bubble(int arr[],int n){
    for(int i=0;i<=n-1;i++)
        for(int j=0;j<=n-i-1;j++)
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
}

int getMax(int a[], int n) {
   int max = a[0];
   for(int i = 1; i<n; i++) {
      if(a[i] > max)
         max = a[i];
   }
   return max; //maximum element from the array
}

void counting(int arr[], int n){
    int max=getMax(arr,n);
    int count[max+1];
    int output[n+1];

    for(int i=0;i<=max;i++){
        count[i]=0;
    }

    for(int i=0;i<=n-1;i++){
        count[arr[i]]++;
    }

    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }

    for(int i=n-1;i>=0;i--){
        output[count[arr[i]-1]]=arr[i];
        count[arr[i]]--;
    }

    for(int i=0;i<=n-1;i++){
        output[i]=arr[i];    }

}

int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    counting(arr,N);
     for(int j=0;j<=N-1;j++){
        cout<<arr[j]<<" ";
     }
}
