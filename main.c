#include <stdio.h>

int main() {
 
    printf("Select an option below: \n");
    printf("a) Rotation Decryption\n");
    printf("b) Rotation Encryption\n");
    printf("c) Substitution Decryption\n");
    printf("d) Substitution Enctryption\n");
    printf("e) Substitution Decryption Without Key\n");
    printf("f) Substitution Encryption Without Key\n");
    printf("Selection: ");
    
    char selection;
    scanf("%c", &selection);
  
    do{
       if(selection == 97){
           char input[] = "LCOKG";
           int n = 6;
           int counter;
           int key = 2;
           for(counter = 0; counter<n; counter++){
               input[counter]= (input[counter] - key);
               if(input[counter]>90){
                   printf("%c", input[counter]-26);
               }
               else if(input[counter]<65){
                   printf("%c", input[counter]+26);
               }
               else {
                   printf("%c", input[counter]);
               } 
           }
       }

        else if(selection == 98){
            char input[] = "JAMIE";
            int n = 5;
            int counter;
            int key = 2;
            for(counter = 0; counter<n; counter++){
                input[counter]= (input[counter] + key);
                if(input[counter]>90){
                    printf("%c", input[counter]-26);
                }
                else if(input[counter]<65){
                    printf("%c", input[counter]+26);
                }
                else {
                    printf("%c", input[counter]);
                }    
            }
        }
        else if(selection == 99){
            char messageletter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            char ciphertextletter[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
            char input[] = "PQDOT";
            int n = 5;
            int index = 0;
            int counter = 0;
            
            while (index <= n){
                for (counter = 0; counter < 25; counter ++){
                    if (input[index] == ciphertextletter[counter]){
                        printf("%c", messageletter[counter]);
                    }
                }
                index ++;
            }
        
        }
        else if(selection == 100){
            char messageletter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            char ciphertextletter[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
            char input[] = "JAMIE";
            int n = 5;
            int index = 0;
            int counter = 0;
             
            while (index <= n){
                for (counter = 0; counter < 25; counter ++){
                    if (input[index] == messageletter[counter]){
                        printf("%c", ciphertextletter[counter]);
                    }
                }
                index ++;
            }
        }

   }while(selection < 'a' || selection > 'f');
 
   
   /*do {
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