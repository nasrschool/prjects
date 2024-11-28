/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include<stdlib.h>
#include<stdio.h>
int** filter(int** triplets,int j,int* size,int** columnSizes){
    int i,h,l;
    int flag;
    int condition;

    int** foutput = (int**) malloc(sizeof(int*) * j);
    i = 0;
    l = 0;
    while(i < j){
        h = j - 1;
        flag = 0;

        printf("i: %d\n",i);
        while(h > i){
            printf("h: %d\n",h);
            //printf("triplets[i][0] : %d | triplets[i][1] : %d | triplets[i][2] : %d\n",triplets[i][0],triplets[i][1],triplets[i][2]);
            //printf("triplets[h][0] : %d | triplets[h][1] : %d | triplets[h][2] : %d\n",triplets[h][0],triplets[h][1],triplets[h][2]);
            condition = !(((triplets[i][0] != triplets[h][0]) && (triplets[i][0] != triplets[h][1]) && (triplets[i][0] != triplets[h][2])) 
            || ((triplets[i][1] != triplets[h][0]) && (triplets[i][1] != triplets[h][1]) && (triplets[i][1] != triplets[h][2])));
            printf("condition: %d\n",condition);
            if(condition){
                //printf("baa\n");
                flag = 1;
                break;
            }
            h--;
        }
        
        if(!flag){
            printf("ggggg\n");
            foutput[l] = triplets[i];
            printf("foutput[l]: %p | triplets[i] : %p",foutput[l],triplets[i]);
            *columnSizes[l] = 3;
            l++;
        }
        i++;
    }
    
    *size = l;
    printf("l: %d\n");
    return foutput;

}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int holder1,holder2,holder3;
    int* triplets[1000];
    int j = 0;
    int** foutput;
    int* size;


    holder1 = 0;
    while(holder1 < numsSize-2){
        holder2 = holder1 + 1;
        while(holder2 < numsSize-1){
            holder3 = holder2 + 1;
            while(holder3 < numsSize){
                if((nums[holder1] + nums[holder2] + nums[holder3]) == 0){
                    triplets[j] = (int*) malloc(sizeof(int) * 3);
                    triplets[j][0] = nums[holder1];
                    triplets[j][1] = nums[holder2];
                    triplets[j][2] = nums[holder3];
                    printf("holder1 : %d | holder2 : %d | holder3 : %d\n",nums[holder1],nums[holder2],nums[holder3]);
                    j++;
                }
                holder3++;
            }
            holder2++;
        }
        holder1++;
    }
    printf("j : %d\n",j);
    foutput = filter(triplets,j,returnSize,returnColumnSizes);
    printf("waa\n");
    return foutput;
}


int main(){
    int nums[] = {-1,0,1,2,-1,-4};
    int* returnSize = (int*) malloc(sizeof(int));
    int** returnColumnSizes;
    int** foutput = threeSum(nums,6,returnSize,returnColumnSizes);

    printf("returno size: %d\n",*returnSize);
    int i,j;
    i = 0;
    while(i<6){
        j = 0;
        while(j<3){
            printf("%d,",foutput[i][j]);
            j++;
        }
        printf("\n");
    }

}