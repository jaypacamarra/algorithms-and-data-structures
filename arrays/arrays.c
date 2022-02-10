#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// default array size
#define ARRAY_SIZE  (10U)

void printArray(int arr[]);
void reverseArray(int arr[]);
void findDuplicatesInArray(int arr[]);
void findDuplicatesInArray2(int arr[]);
bool isMonotonic(int* nums, int numsSize);
int* getConcatenation(int* nums, int numsSize, int* returnSize);
int count_duplicates_sorted_array_not_using_hashtable(int *arr, int size);

int main() {
    int array[ARRAY_SIZE] = {1,2,3,4,5,6,7,7,9,10};
    //print original array
    printArray(array);
    
    clock_t t_begin = clock();

    // execute algorithm
    //reverseArray(array);
    //findDuplicatesInArray2(array);
    //printf("%d\n",isMonotonic(array,ARRAY_SIZE));
    printf("duplicates in array = %d\n",count_duplicates_sorted_array_not_using_hashtable(array,ARRAY_SIZE));
    clock_t t_end = clock();

    //print time of execution
    printf("execution time: %f ms\n", 1000 * (double)(t_end - t_begin)/CLOCKS_PER_SEC);

    return 0;
}

void printArray(int arr[]) {
    /*
     *   Note, when an array is passed directly to a function, the array
     *   decays into a pointer and therefore information of its size is lost.
     *   Therefore, the size of the array should be passed as an argument as well.
     */

    for(int i=0; i<ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    puts("");//newline
}

void reverseArray(int arr[]) {
    int revArr[ARRAY_SIZE]={0};
    for(int i=0; i<ARRAY_SIZE; i++) {
        revArr[i] = arr[ARRAY_SIZE-1-i];
    }
    printArray(revArr);
}

void findDuplicatesInArray(int arr[]) {
    int duplicates=0;
    int duplicateNum;
    int arr1[ARRAY_SIZE]={0};
    int arr2[ARRAY_SIZE]={0};

    for(int i=0; i<ARRAY_SIZE; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
    }

    for (int i=0; i<ARRAY_SIZE; i++) {
        for (int j=0; j<ARRAY_SIZE; j++) {
            if(arr1[i] == arr2[j]) {
                if(i!=j) {
                    duplicates++;
                    duplicateNum=arr2[j];
                }
            }
        }
        if(duplicates>0)
            break; //we only care about duplicates of a single number
    }
    printf("There are %d duplicates of %d\n", duplicates+1,duplicateNum);
}


// find duplicates in sorted array
void findDuplicatesInArray2(int arr[]) {
    int lastDuplicate=0;
    for(int i=0; i<ARRAY_SIZE; i++) {
        if(arr[i] == arr[i+1] && arr[i] != lastDuplicate) {
            printf("%d is duplicated \n", arr[i]);
            lastDuplicate=arr[i];
        }
    }
}

bool isMonotonic(int* nums, int numsSize){
    bool b_isMonotonic = true;
    int direction = -1; //-1=Unused, 0=Decreasing, 1=Increasing

    //assume direction based on first change
    for(int i=0; i < numsSize-1; i++) {
        if(nums[i]>nums[i+1]) {
            direction = 0;
            break;
        }
        else if(nums[i]<nums[i+1]) {
            direction = 1;
            break;
        }
    }

    //Fully check elements if monotonic increasing or decreasing
    if(direction == 0) {
        for(int i=0; i < numsSize-1; i++) {
            if(nums[i] >= nums[i+1]) {
                continue;
            }
            b_isMonotonic = false;
        }
    }
    if(direction == 1) {
        for(int i=0; i < numsSize-1; i++) {
            if(nums[i] <= nums[i+1]) {
                continue;
            }
            b_isMonotonic = false;
        }
    }

    return b_isMonotonic;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    *returnSize = 2*numsSize;
    int* concArr = (int *)malloc(2*numsSize*sizeof(int));
    for(int i=0; i<numsSize; i++) {
        concArr[i] = nums[i];
        concArr[i+numsSize] = nums[i];
    }
    return concArr;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * Function to decode an array that has been decoded in the following way:
 * encoded[i] = original[i] XOR original[i+1]
 * returns decoded array with size encodedSize+1
 * first is the first element in the original array
 *
 * ex. encoded = [1,2,3]
 *     original = [1,0,2,1]
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize){
    int len_decArr = encodedSize+1;
    int* decArr = (int*)malloc(len_decArr*sizeof(int));
    decArr[0]=first;
    for(int i=0; i<len_decArr-1; i++) {
        decArr[i+1]=decArr[i]^encoded[i];
    }
    return decArr;
}

/*
 * algorithm uses one iterator, and a counter
 * uses a single for loop
 * time complexity -> O(n-1) ?
 * for loop statement executes in constant time O(1) * O(n-1) = O(n-1)
 */
int count_duplicates_sorted_array_not_using_hashtable(int *arr, int size) {
    int numDuplicates=0;
    int i;
    for(i=0; i<size-1; i++) {
        if(arr[i]==arr[i+1]) {
            numDuplicates++;
        }
    }
    return numDuplicates != 0 ? ++numDuplicates : 0; //count one more duplicate or 0
}



