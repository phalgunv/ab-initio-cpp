#include <stdio.h>
#include <math.h>
 
void decimalToBinary(int op1, int aOp[]){
    int result, i = 0;
    do{
        result = op1 % 2;
        op1 /= 2;
        aOp[i] = result;
        i++;
    }while(op1 > 0);
 }
 
 
 int binaryToDecimal(int array[]){
    int sum = 0, i;
    for(i = 0; i < 8; i++){
        if(array[i]) sum += pow(2,i);
    }
    return sum;
}
 
 void showBinary(int array[], int n){
    int i;
    for(i = n -1; i >=0; i--){
        printf("%d ", array[i]);
 
    }
    printf("\n");
 }
 
 
 
int addBinary(int a1[], int a2[], int result[]){
    int i, c = 0;
    for(i = 0; i < 8 ; i++){
        result[i] = ((a1[i] ^ a2[i]) ^ c); //a xor b xor c
        c = ((a1[i] & a2[i]) | (a1[i] &c)) | (a2[i] & c); //ab+bc+ca
    }
    result[i] = c;
    return c;
 }
 
 
int main(){
    int op1, op2, sum;
    int  aOp1[8] = {0,0,0,0,0,0,0,0};
    int  aOp2[8] = {0,0,0,0,0,0,0,0};
    int  aSum[8] = {0,0,0,0,0,0,0,0};
 
    printf("Enter two operands (0 to 255): ");
    scanf("%d %d", &op1, &op2);
    while(op1 < 0 || op1 > 255 || op2 < 0 || op2 > 255 ){
        printf("Enter two operands (0 to 255): ");
        scanf("%d %d", &op1, &op2);
    }
 
 
 
    decimalToBinary(op1, aOp1);
    decimalToBinary(op2, aOp2);
 
    printf("Binary Equivalent of %d is ",op1);
    showBinary(aOp1, 8);
    printf("Binary Equivalent of %d is ",op2);
    showBinary(aOp2, 8);
 
    if(!addBinary(aOp1, aOp2, aSum)){
        printf("Sum of the two number is : ");
        showBinary(aSum, 8);
        sum = binaryToDecimal(aSum);
        printf("Decimal eqivalent is: %d", sum);
    }else{
       printf("Overflow");
    }
    return 0;
 }
