#include<bits/stdc++.h>
using namespace std;
void selectionsort(int arr[],int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        int min=i;
        for(int j=i+1;j<=n-1;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        swap(i,min);
    }
}
void brutebubble(int arr[],int n)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void insertion_sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
