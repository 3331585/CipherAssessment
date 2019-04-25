#include <stdio.h>

int main() {
 
    printf("Select an option below: \n");
    printf("a) Rotation Encryption\n");
    printf("b) Rotation Decryption\n");
    printf("c) Substitution Encryption\n");
    printf("d) Substitution Dectryption\n");
    printf("e) Substitution Encryption Without Key\n");
    printf("f) Substitution Dectryption Without Key\n");
    printf("Selection: ");
    
    char a;
    scanf("%a", &a);
    
  /*  
    FILE *input;
    char c;
    input = fopen("input.txt", "r");
    
    while(feof(input) == 0){
        fscanf(input, "%c", &c);
        printf("%c\n", c);
    }
    */
   
 return 0;   
}