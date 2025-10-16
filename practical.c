// 1: function FINDMAXSUBARRAY(A, low, high)
// 2: if low = high then
// 3: return (low, high, A[low])
// 4: else
// 5: mid ← b low+high
// 2
// c
// 6: L ← FINDMAXSUBARRAY(A, low, mid)
// 7: R ← FINDMAXSUBARRAY(A, mid + 1, high)
// 8: C ← FMCS(A, low, mid, high)
// 9: if L.maxSum >= R.maxSum and
// 10: L.maxSum >= C.maxSum then
// 11: return L
// 12: else if R.maxSum >= L.maxSum and
// 13: R.maxSum >= C.maxSum then
// 14: return R
// 15: else
// 16: return C
// 17: end if
// 18: end if
// 19: end function
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct subarray{
    int low;
    int high;
    int maxsum;
};
struct subarray FINDMAXCROSSARRAY(int *A,int low,int mid,int high){
    int leftsum=-999999,rightsum=-999999,sum=0,maxleft=low,maxright=high;
    for(int i=mid;i>=low;i--){
        sum+=A[i];
        if(sum>leftsum){
            leftsum=sum;
            maxleft=i;
        }
    }
    sum=0;
    for(int i=mid+1;i<=high;i++){
        sum+=A[i];
        if(sum>rightsum){
            rightsum=sum;
            maxright=i;
        }
    }
    struct subarray result={maxleft,maxright,leftsum+rightsum};
    return result;
}
struct subarray FINDMAXSUBARRAY(int *A, int low, int high){
    int mid;
    struct subarray result,L,R,C;
    if(low==high){
        struct subarray result={low,high,A[low]};
        return result;
    }
    else{
        mid=(high+low)/2;
        L=FINDMAXSUBARRAY(A,low,mid);
        R=FINDMAXSUBARRAY(A,mid+1,high);
        C=FINDMAXCROSSARRAY(A,low,mid,high);
        if(L.maxsum>=R.maxsum&&L.maxsum>=C.maxsum){
            return L;
        }
        else if(R.maxsum>=L.maxsum&&R.maxsum>=C.maxsum){
            return R;
        }
        else{
            return C;
        }
    }
    }
int main(){
    int *ptr,num;
    struct subarray result;
    printf("Enter the number of elements that you want in the array:");
    scanf("%d",&num);
    ptr=(int*)malloc(num*sizeof(int));
    for(int i=0;i<num;i++){
        printf("Enter the number at %d position::",i+1);
        scanf("%d",&ptr[i]);
    }
    result=FINDMAXSUBARRAY(ptr,0,num-1);
    printf("Max sum subarray is %d from-->%d to %d ",result.maxsum,result.low,result.high);
    return 0;
}