#include <stdio.h>

/* TLE
    void regua(int n){
    if( n == 1){ //caso base
        printf(".-\n");
    }else{
        regua(n-1);
        printf(".");
        for(int i =0; i < n; i++){
            printf("-");
        }
        printf("\n");
        regua(n-1);
    }

}
*/

void mark(int h){// serve para desenhar a marca
    printf(".");
    for(int i = 0 ; i < h ; i++)
        printf("-");
    printf("\n");
}

void rule2(int h){ 
    if (h > 0) { 
        rule2(h-1);
        mark(h);
        rule2(h-1);
    }
}

int main(){
    int n;
    printf("Enter how many lines the ruler will have: ");
    scanf("%d", &n);
    //Rule(n);
    rule2(n);
    return 0;
}

/* Web resolution

void rule(int p, int r, int h){ 
    int m = (p + r)/2;
    if (h > 0) { 
        //printf("p = %d\t, m = %d\t, h = %d\n", p, m, h);
        rule(p, m, h-1);
        mark(h);
        //printf("m = %d\t,r = %d\t, h = %d\n", m,r ,h);
        rule(m, r, h-1);
    }
}

void Rule(int n) {// serve para iniciar a regua
    int p = 1;
    for (int i = 0; i < n; i++)// i intera n vezes
        p *= 2; 
    //printf("r = %d\t, n = %d\n", p , n);
    rule(0, p, n);
}


*/