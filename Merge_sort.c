#include <stdio.h>
#include <stdlib.h>
void merge(int low,int mid,int high,int a[])
{
  int c[50];
  int i,j,k;
  i=low;
  j=mid+1;
  k=low;
  while(i<=mid&&j<=high)
  {
    if(a[i]<a[j])
    {
      c[k]=a[i];
      i++;
      k++;
    }
    else{
      c[k]=a[j];
      j++;
      k++;
    }
  }
  while(i<=mid)
  {
    c[k]=a[i];
    k++;
    i++;
  }
  while(j<=high)
  {
    c[k]=a[j];
    k++;
    j++;
  }
  for(i=low;i<=high;i++)
  {
  a[i]=c[i];
  }
}

void mergeSort(int low, int high,int a[])
{
  if(low<high)
  {
    int mid=(low+high)/2;
    mergeSort(low, mid, a);
    mergeSort(mid+1,high,a);
    merge(low, mid, high, a);
  }
}

void main()
{
  int n;
  printf("\nEnter the size: ");
  scanf("%d",&n);
  int i, a[50], low=0, high=n-1;
  printf("Enter the elements to be sorted: ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  mergeSort(low, high, a);
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
}

