#include<stdio.h>
int main(){
    int a[50],size,o[50];
    printf("Enter size of array\n");
    scanf("%d",&size);
    printf("Enter elements of array\n");
    for(int i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    // for(int i=0;i<size;i++){
    //     printf("%d ",a[i]);
    // }
    for(int i=0;i<size-1;i++){
        int flag=0;
        for(int j=0;j<size-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
    printf("The new array is\n");
    for(int i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    for(int i=0;i<size;i++){
        int count=1;
        for (int j=i+1;j<size;j++) { 
            if (a[i]==a[j]){
                count++;
            }
        }
        if(count>=3){
            for(int m=0;m<50;m++)
                o[m]=a[i];
            // printf(o[i]);
        }
        i=i+count-1;
        // for(int j=i+1;j<size;j++){
        //     if(a[j]==a[i]){
        //         count++;
        //     }
        // }
    }
    
    // int l=sizeof(o)/sizeof(o[0]);
    for(int i=0;i<50;i++){
        printf("%d ",o[i]);
    }  
    return 0;
}