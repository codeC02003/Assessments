#include <bits/stdc++.h>
using namespace std;

int getMax(int a[], int n) {
   int max = a[0];
   for(int i = 1; i<n; i++) {
      if(a[i] > max)
         max = a[i];
   }
   return max; //maximum element from the array
}

void countSort(int a[], int n) // function to perform counting sort
{
   int output[n+1];
   int max = getMax(a, n);
   int count[max+1]; //create count array with size [max+1]


  for (int i = 0; i <= max; ++i)
  {
    count[i] = 0; // Initialize count array with all zeros
  }

  for (int i = 0; i < n; i++) // Store the count of each element
  {
    count[a[i]]++;
  }

   for(int i = 1; i<=max; i++)
      count[i] += count[i-1]; //find cumulative frequency

  /* This loop will find the index of each element of the original array in count array, and
   place the elements in output array*/
  for (int i = n - 1; i >= 0; i--) {
    output[count[a[i]] - 1] = a[i];
    count[a[i]]--; // decrease count for same numbers
}

   for(int i = 0; i<n; i++) {
      a[i] = output[i]; //store the sorted elements into main array
   }
}

void printArr(int a[], int n) /* function to print the array */
{
    int i;
    for (i = 0; i < n; i++)
        cout<<a[i]<<" ";
}

int main() {
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    countSort(arr, N);
    cout<<"\nAfter sorting array elements are - \n";
    printArr(arr, N);
    return 0;
}
