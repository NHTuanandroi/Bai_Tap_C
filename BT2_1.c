#include"stdio.h"
#include <stdlib.h>
void In_Put_Array(int arr[], int n)
{
    for(int i = 0;i <n; i++){
        printf("In Put Arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    printf("\n");

}

void Print_Array(int arr[], int n)
{
    for(int i = 0;i <n; i++){
        printf("Arr[%d]: %d ",i,arr[i]);
        printf("\n");
    }
    printf("\n");
}

void Increase_Sort(int arr[], int n) // .... sort algorithm
{
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void Decrease_Sort(int arr[], int n) // .... sort algorithm
{
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] > arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void Number_of_apear(int arr[], int n){ // function use to count the number of appear of each elenment
    int cnt = 1;
    int i = 0;
	for( i = 0; i < n;i++){
		if(arr[i] == arr[i+1]) ++cnt;
		else{
			printf("\nElement %d appear: %d times ", arr[i], cnt);
			cnt = 1;
		}

	}

}
int main()
{
    int n;
    printf("In put number of elenment: "); scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int)); //  memory allocation size of arr.

    In_Put_Array(arr,n); // call function input array
    Print_Array(arr, n);

    Increase_Sort(arr,n);
    printf("After Increase Sort:\n");
    Print_Array(arr, n);

    Decrease_Sort(arr,n);
    printf("After Decrease Sort:\n");
    Print_Array(arr, n);

    Number_of_apear(arr,n);

    return 0;
}
