#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

void selection_sort(int *array, int size);
void show_array(int *arr,int size);
void bubble_sort(int *array, int size);
void choose_sort_algo(int *arr, int size);
int binary_search(int *array, int size, int target); 

int main(){
    int size;
    int *arr = NULL;
    int i;
    int add_size;
    int target;

    printf("enter the size of the array u wana create: ");
    scanf("%d",&size);
    arr = (int*) malloc(sizeof(int) * size);
    if(arr == NULL){
        printf("the dynamic memory allocation was unsuccessful");
        return 1;
    }
    
    i = 0;
    while(i < size){
        printf("enter an element at index %d of the array: ",i);
        scanf("%d",arr + i);
        i++;
    }
    printf("\n");

    printf("the values u have entered are: ");
    show_array(arr,size);
  
    printf("enter how many numbers u are planing to add to the array: ");
    scanf("%d",&add_size);

    //printf("arr = %p\n",arr);
    arr = (int*) realloc(arr,sizeof(int) * (size + add_size));
    //printf("arr = %p\n",arr);
    if(arr == NULL){
        printf("the dynamic memory allocation was unsuccessful");
        return 1;
    }

    size += add_size;
    while(i < size){
        printf("enter the value at index %d of the array: ",i);
        scanf("%d",arr + i);
        i++;
    }
    show_array(arr,size);

    choose_sort_algo(arr,size);
    
    printf("enter a target to search for in the sorted array: ");
    scanf("%d",&target);

    printf("the index of the target %d is: %d\n",target,binary_search(arr,size,target));

    free(arr);
    printf("memory was freed successfully!");

    return 0;
}

/*int main(){
    int arr[6] = {1,5,7,12,16,19};
    printf("the index of 7 on arr is : %d\n",binary_search(arr,6,16));


    return 0;
}*/



void selection_sort(int *array, int size){
    int i;
    int j;
    int tmp;

    i = 0;
    j = 0;
    while(i < size - 1){
        j = i + 1;
        while(j < size){
            if(array[j] < array[i]){
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

void show_array(int *arr,int size){
    int i;

    i = 0;
    while(i < size){
        printf("%d ",arr[i]);
        i++;
    }
    printf("\n");
}

void bubble_sort(int *array, int size){
    int i;
    int j;
    int tmp;

    i = 1;
    while(i < size){
        j = i;
        while(array[j] < array[j - 1]){
            tmp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = tmp;
            if(!(j-1)){
                break;
            }
            j--;
        }
        i++;
    }
}

void choose_sort_algo(int *arr,int size){
    int choice;
    clock_t start;
    clock_t end;

    printf("choose a sorting algorithm to sort the array: \n1. selection sort\n2. buble sort\n");
    scanf("%d",&choice);
    printf("your choice: %d\n",choice);

    start = clock();

    switch (choice){
        case 1:
            selection_sort(arr,size);
            break;
        case 2:
            bubble_sort(arr,size);
            break;
        default:
            printf("enter a number between 1 and 2 next time\n");
            return;
    }
    show_array(arr,size);
    
    end = clock();
    printf("the time it the algorithm to execute is %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int binary_search(int *arr, int size, int target){
    int begin;
    int end;
    int mid;

    begin = 0;
    end = size - 1;
    while(begin <= end){
        if(begin == end){
            if(target == arr[begin]){
                return begin;
            }else{
                return -1;
            }
        }
        mid = begin + ((end - begin)/2);
        if(arr[mid] == target){
            return mid;
        }else{
            if(target > arr[mid]){
                begin = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }

    return -1;
}