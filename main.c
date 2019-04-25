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
    
    char selection;
    scanf("%c", &selection);
    do {
        switch(selection){
            case 'a': // function call for rotation encryption
                break;
            case 'b': // function call for rotation decryption
                break;
            case 'c': // function call for substitution encryption
                break;
            case 'd': // function call for substitution decryption
                break;
            case 'e': // function call for substitution encryption w/key
                break;
            case 'f': // function call for substitution decryption w/key
                break;
            default: printf("unknown option, enter a, b, c, d, e or f");
        }
        
        // block of code that calls above functions
        // switch case - call different function for each option...
        
    } while(selection < 'a' || selection > 'f');
    
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