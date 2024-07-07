#include<stdio.h>

struct stdInfo{

    int id;
    int sub1;
    int sub2;
    double avg;
};

void swap(int *a, int *b){    

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void swapAvg(double *a, double *b){    

    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

    int n=4;
    struct stdInfo p[n];  //p[]
    
    for(int i=0; i<n; i++){

        printf("Enter id no: ");
        scanf("%d", &p[i].id);

        printf("Enter subject_1 mark: ");
        scanf("%d", &p[i].sub1);

        printf("Enter subject_2 mark: ");
        scanf("%d", &p[i].sub2);

        p[i].avg = double((p[i].sub1 + p[i].sub2)/2);
    }

    printf("\n");
    printf("ID\tSub1\tSub2\tAvg\n");

    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1-i; j++){
            if(p[j].avg<p[j+1].avg){
                swap(&p[j].id, &p[j+1].id);
                swap(&p[j].sub1, &p[j+1].sub1);
                swap(&p[j].sub2, &p[j+1].sub2);
                swapAvg(&p[j].avg, &p[j+1].avg);                
            }
        }
    }

    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\t%.2f\n", p[i].id, p[i].sub1, p[i].sub2, p[i].avg);
    }
    return 0;
}
    
