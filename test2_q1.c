#include<stdio.h>

typedef struct student{
    int roll;
    int marks;
}student;

void swap(student* a, student* b){
    student temp = *a;
    *a = *b;
    *b = temp;
}

void HEAPIFY(student H[], int n, int i){
    int select;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && H[left].roll < H[i].roll){
        select = left;
    }else select = i;
    if(right<n && H[right].roll < H[select].roll){
        select = right;
    }
    if(select !=i){
        swap(&H[i], &H[select]);
        HEAPIFY(H, n, select);
    }
}

void CREATE_HEAP(student H[], int n){
    for(int i = (n/2)-1; i>=0;i--){
        HEAPIFY(H, n, i);
    }
}


void read_students(student H[], int k){
    for(int i = 0; i<k; i++){
    
        scanf("%d %d", &H[i].roll, &H[i].marks);
    }
    
    CREATE_HEAP(H, k);
}

void print_students(student H[], int k){
    for(int i = 0;i<k; i++){
        printf("%d ", H[i].roll);
    }printf("\n");
}

student HEAP_EXTRACT(student H[], int n){
    if(n>1){
        student value = H[0];
        swap(&H[0], &H[n-1]);
        HEAPIFY(H,n-1, 0);
        return value;
    }
}
void sort_students(student H1[], int n, student H2[], int  m, student S[]){
    int i=0, j=0;
    student a = HEAP_EXTRACT(H1, n-i);
    student b = HEAP_EXTRACT(H2, m-j);
    while(i<n || j<m){
        if(a.roll>b.roll && i<n && j<m){
            S[i+j] = a;
            i++;
        }else if(b.roll>a.roll && i<n && j<m){
            S[i+j] = b;
            j++;
        }else if(i<n){
            S[i+j] = a;
            i++;
        }else if(j<m){
            S[i+j] = b;
            j++;
        }
    }
    for(int i = 0; i<n; i++){
        printf("%d %d\n", S[i].roll, S[i].marks);
    }
}

int main(){
    int n,m;
    scanf("%d %d", &n,&m);
    char ch; int k;
    student H1[n],H2[m],S[n+m];
    
    
    scanf("%c", &ch);
    while(ch!='t'){
        if(ch == 'r'){
            scanf(" %d", &k);
            if(k == 1){
                read_students(H1, n);
            }else if(k == 2){
                read_students(H2, m);
            }
        }else if(ch == 'p'){
            scanf(" %d", &k);
            if(k == 1){
                print_students(H1, n);
            }else if(k == 2){
                print_students(H2, m);
            }
        }else if(ch =='s'){
            sort_students(H1, n, H2, m ,S);
        }
        scanf("%c", &ch);
    }
    return 0;
}