#include <stdio.h>

/*
This code will perform encryption or decryption on a message.
There are two different methods, rotation or substitution, which can
be selected by following the menu and entering a, b, c or d. The code will
then run the desired encryption or decryption according to the do while loop,
which runs based off the ascii value of the selected user input. The message 
to be encrypted or decrypted and the key are hard coded in each section. This 
code is designed to work with capital letters.To run the code, the user can 
use the terminal to make selections and see results.
*/

int main() {

/*
The code below is the menu that allows users to choose which option they'd
like to select. The printf statements prompt the user and offer choices.
*/
 
    printf("Select an option below: \n"); //This line is soley used as a prompt
    printf("a) Rotation Decryption\n"); // \n is used to separate each possible selection, makes reading easier for user
    printf("b) Rotation Encryption\n");
    printf("c) Substitution Decryption\n");
    printf("d) Substitution Enctryption\n");
    printf("e) Substitution Decryption Without Key\n");
    printf("f) Substitution Encryption Without Key\n");
    printf("Selection: "); // another prompt for user, provides space to enter selection
    
    char selection; 
    scanf("%c", &selection); // the users input is stored in the variable 'selection'
  
    do{
/* Bellow is selection 'a', rotation decryption. The input has been hard coded
to 'LCOKG' and the key is -2. This means each letter is pushed back 2 spots in 
the alphabet, the decryption printing 'JAMIE'. Note that the char data type
is used because it allows strings to be stored in arrays. 
*/
       if(selection == 97){ // the condition uses the ascii code for 'a', which = 97
           char input[] = "LCOKG"; // Code that will be decrypted. An array is used to that we can process multiple variables or letters
           int n = 6; // This is the length of the string, since it finishes with an unseen 0. This is required to act as a limit in the condition of the for loop below. 
           int counter; // Acts as index for the array. It is increased each time the for loop goes through, meaning each letter is decrypted.
           int key = -2; // The is how much the input code will be rotated. Can be changed based on the input code.
           for(counter = 0; counter<n; counter++){ // for loop is required so that each letter can be decrypted individually.
               input[counter]= (input[counter] + key); // assigning the new value to the input after being altered by the key.
/*
The if and else conditions below are based of the ascii values of the input.
It allows the letters like A and Z to wrap back around the other side of the alphabet
instead of being converted into random values on either side of the alphabet.
*/
               if(input[counter]>90){ // incase the decryption goes past Z
                   printf("%c", input[counter]-26);
               }
               else if(input[counter]<65){ //incase the decryption goes before A
                   printf("%c", input[counter]+26);
               }
               else { //If neither of the above, just print the input letter + key
                   printf("%c", input[counter]);
               } 
           }
       }
/* 
Bellow is selection 'b', rotation encryption. It is the reverse of the
previous code block, as the input is 'LCOKG' and the key is 2. This means each 
letter is pushed forward 2 spots in the alphabet, printing 'JAMIE'.
*/
        else if(selection == 98){ // Menu selection for 'b'. Ascii code = 98.
            char input[] = "JAMIE"; // input message initialised as an array to allow for multiple variables
            int n = 6; // This is the length of the string, since it finishes with an unseen 0. This is required to act as a limit in the condition of the for loop below.
            int counter; // will be used as an index for the array, allowing each individual letter to be encrypted one by one as the loop increments.
            int key = 2; // Positive key will reverse the previous decryption.
            for(counter = 0; counter<n; counter++){ // for loop increments through each letter of the array using the index 'counter'.
                input[counter]= (input[counter] + key); //assigning the input letter a new value by adding the key of 2
//The below code is used to for same reason stated in the rotation decryption section above. 
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
/*
Below is selection 'c', substitution decryption. It works by using three 
different arrays, the input, the normal alphabet, and the substitution 
alphabet. A for loop runs until the ascii value of the first input letter
matches one from the substitution alphabet. The index of this letter in the alphabet is 
then matched to the opposing index in the regular alphabet, and this
letter takes its place. The input is 'PQDOT', and using the 'QWERTY' 
substitution, this will spell 'JAMIE'.

 */
        else if(selection == 99){ // Menu selection 'c'. Ascii code = 99
            char messageletter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // The regular alphabet for the input message
            char substitutionletter[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // The substitution alphabet. 'Q' substitutes for 'A' etc.
            char input[] = "PQDOT"; // Input message initialised as array due to multiple variables.
            int n = 6; // length of array. Required for the condition of the for loop.
            int index = 0; // index for the input, initialised to 0 since arrays begin from 0.
            int counter = 0; // index for the alphabets. Initialised to zero so it begins at the first letter.
            
            while (index <= n){ // loop makes code quit after all letters are decrypted. 
                for (counter = 0; counter < 25; counter ++){ // counter stops at 25 because it reaches the end of the alphabet, since it begins at 0. 
                    if (input[index] == substitutionletter[counter]){ // compares input letter to substitution alphabet letter. 
                        printf("%c", messageletter[counter]); //If they're equal, prints corresponding message letter.
                    } // If they aren't equal, loop runs again and the counter goes to the next letter in the alphabet.
                }
                index ++; // Index goes to next input letter once the first letter has been decrypted.
            }
        
        }
/*
Below is selection 'd', substitution encryption. It works by using three 
different arrays, the input, the normal alphabet, and the substitution 
alphabet. A for loop runs until the ascii value of the first input letter
matches one from the alphabet. The index of this letter in the alphabet is 
then matched to the opposing index in the substitution alphabet, and this
letter takes its place. The input is 'JAMIE', and using the 'QWERTY' 
substitution, this will spell 'PQDOT'.
 */
        else if(selection == 100){ // Menu selection 'd', ascii value = 100.
            char messageletter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // normal alphabet that will be encrypted.
            char substitutionletter[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // substitution alphabet that replaces regular alphabet.
            char input[] = "JAMIE"; // Input message initialised in an array
            int n = 6; // Length of string, variable required for while loop condition
            int index = 0; // Index for the input, initialised to zero since arrays begin from 0
            int counter = 0; // Index for the alphabets. Initialised to zero so it begins at the first letter.
             
            while (index <= n){ // While loop makes the code quit once all letters have been encrypted. 
                for (counter = 0; counter < 25; counter ++){ // counter stops at 25 because it reaches the end of the alphabet, since it starts at 0
                    if (input[index] == messageletter[counter]){ // compares input letter to alphabet letter
                        printf("%c", substitutionletter[counter]); // If they're equal, prints corresponding substitution letter. 
                    }
                } // If they're not equal, loop repeats and checks the next alphabet letter.
                index ++; // Input index goes to next letter once first letter has been decrypted.
            }
        }

   }while(selection < 'a' || selection > 'd'); // condition tested after the code runs once, to make sure the letter selected was one of the options. 
 
   
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