#include <stdio.h>

/*
This code will perform encryption or decryption on a message.
There are two different methods, rotation or substitution, which can
be selected by following the menu and entering a, b, c or d. The code will
then run the desired encryption or decryption according to the do while loop,
which runs based off the ascii value of the selected user input. The message 
to be encrypted or decrypted will be written into the input.txt file. This 
code is designed to work with capital letters.
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
    printf("Selection: "); // another prompt for user, provides space to enter selection
    
    char selection; // new variable called 'selection'
    scanf("%c", &selection); // the users input is stored in the variable 'selection'
  
    do{
/* 
Bellow is selection 'a', rotation decryption. The key should be written on the first line of the input.txt
file, and the message on the line below that. The key should be a number, positive or negative, and the message
should be in capital letters. 
*/
        if(selection == 97){ // the condition uses the ascii code for 'a', which = 97.
            FILE *input; //declares input file that message will be read from.
            FILE *output; // declares output file that message will be written to.
            output = fopen("output.txt", "w"); //This opens the output file. 'w' is the mode that allows the code to write the decrypted message in this file.
            input = fopen("input.txt", "r"); // This opens the input file.'r' is the mode that allows the code to read from the file.
            char c; // variable that message will be stored in.
            int key; // variable that the key will be stored in.
            int message;//variable that decrypted message is stored in.
            fscanf(input, "%d\n", &key); //code reads the number(hence %d) that the user typed and stores it in variable 'key'
            
            while(feof(input) == 0){ //this loop controls how long the code reads from the file. Reaching the end of text = 0, and will quite the loop.
                fscanf(input, "%c", &c); // fscanf reads from input file and stores the message typed in input.txt in variable 'input'. Use %c to read individual characters and & for 'address of c'
                message = c + key; // Equation that impliments decryption. Message becomes user input + rotation amount.
                if(c == 32){ // Ascii code for whitespace is 32.
                    printf("%c", c); // if the imput is white space, don't alter it.
                    fprintf(output, "%c", c); // fprintf prints to the output file.
                }
                else if(message<65){ // if ascii value of rotated variable is before the alphabet, add 26 to loop it back around.
                    printf("%c", message + 26);
                    fprintf(output, "%c", message + 26);
                }
                else if(message>90){ // if ascii value of rotated variable is after the alphabet, subtract 26 to loop it back around. 
                    printf("%c", message -26);
                    fprintf(output, "%c", message -26);
                }
                else { // if it falls within the alphabet, simply print the message letter.
                    printf("%c", message);
                    fprintf(output, "%c", message);
                }  
                 
            }
        }
/* 
Bellow is selection 'b', rotation encryption. It is the reverse of the
previous code block, meaning if you change the sign of the previous key and input the decrypted message from
above, it will encrypt it back to the original cipher. The key can be a positive or negative number, and the 
message should be capital letters. Arrangement or these are the same as before. 
*/
        else if(selection == 98){ // Menu selection for 'b'. Ascii code = 98.
            FILE *input;//declares input file that message will be read from.
            FILE *output;// declares output file that message will be written to.
            input = fopen("input.txt", "r");// This opens the input file.'r' is the mode that allows the code to read from the file.
            output = fopen("output.txt", "w");//This opens the output file. 'w' is the mode that allows the code to write the decrypted message in this file.
            char c;//variable that message will be stored in.
            int key;//variable that key will be stored in.
            int message; //variable that encrypted message is stored in.
            fscanf(input, "%d\n", &key);//code reads the number(hence %d) that the user typed and stores it in variable 'key'
            
            while(feof(input) == 0){//this loop controls how long the code reads from the file. Reaching the end of text = 0, and will quite the loop.
                fscanf(input, "%c", &c); // fscanf reads from input file and stores the message typed in input.txt in variable 'c'. Use %c to read individual characters and & for 'address of c'
                message = c + key;// Equation that impliments decryption. Message becomes user input + rotation amount.
                if(c == 32){// Ascii code for whitespace is 32.
                    printf("%c", c);// if the imput is white space, don't alter it.
                    fprintf(output, "%c", c);// fprintf prints to the output file.
                }
                else if(message<65){// if ascii value of rotated variable is before the alphabet, add 26 to loop it back around.
                    printf("%c", message + 26);
                    fprintf(output, "%c", message + 26);
                }
                else if(message>90){// if ascii value of rotated variable is after the alphabet, subtract 26 to loop it back around. 
                    printf("%c", message -26);
                    fprintf(output, "%c", message -26);
                }
                else {// if it falls within the alphabet, simply print the message letter.
                    printf("%c", message);
                    fprintf(output, "%c", message);
                }  
                 
            }
        }
/*
Below is selection 'c', substitution decryption. It works by using two 
different arrays, the normal alphabet, and the substitution 
alphabet. A for loop runs until the ascii value of the first input letter
matches one from the substitution alphabet. The index of this letter in the alphabet is 
then matched to the opposing index in the regular alphabet, and this
letter takes its place. For example, if the input is 'PQDOT', using the 'QWERTY' 
substitution, this will spell 'JAMIE'.
*/
        else if(selection == 99){ // Menu selection 'c'. Ascii code = 99
            FILE *input; //declares input file that message will be read from.
            FILE *output;// declares output file that message will be written to.
            input = fopen("input.txt", "r");// This opens the input file.'r' is the mode that allows the code to read from the file.
            output = fopen("output.txt", "w");//This opens the output file. 'w' is the mode that allows the code to write the decrypted message in this file.
            char c;//variable that message will be stored in.
            char messageletter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // char is used so that the string can be stored in an array.
            char substitutionletter[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // char is used so that the string can be stored in an array.
            int counter = 0;//counter is used to compare different letters between the two alphabets. Initialised to 0 to start from the first letter.
                    
            while (feof(input) == 0){ //this loop controls how long the code reads from the file. Reaching the end of text = 0, and will quite the loop.
                while(feof(input) == 0){
                fscanf(input, "%c", &c);// fscanf reads from input file and stores the message typed in input.txt in variable 'c'. Use %c to read individual characters and & for 'address of c'
                    for (counter = 0; counter < 25; counter ++){// <25 because it reaches the end of the alphabet.
                        if (c == substitutionletter[counter]){//for loop runs until the ascii values of c and substitutionletter match
                            printf("%c", messageletter[counter]); //when they match, print the corresponding message letter
                            fprintf(output, "%c", messageletter[counter]);//print to output.txt as well. %c because it processes individual characters
                        } 
                    }
                }
            }
        
        }
/*
Below is selection 'd', substitution encryption. It works by using 2 
different arrays, the normal alphabet, and the substitution alphabet. 
A for loop runs until the ascii value of the first input letter
matches one from the alphabet. The index of this letter in the alphabet is 
then matched to the opposing index in the substitution alphabet, and this
letter takes its place. If the input is 'JAMIE', using the 'QWERTY' 
substitution, this will spell 'PQDOT', which is the input for the previous decryption.
 */
        else if (selection == 100){ // Menu selection 'd', ascii value = 100.
            FILE *input;//declares input file that message will be read from.
            FILE *output;// declares output file that message will be written to.
            input = fopen("input.txt", "r");// This opens the input file.'r' is the mode that allows the code to read from the file.
            output = fopen("output.txt", "w"); //This opens the output file. 'w' is the mode that allows the code to write the decrypted message in this file.
            char c;//variable that message will be stored in.
            char messageletter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // char is used so that the string can be stored in an array.
            char substitutionletter[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // char is used so that the string can be stored in an array.
            int counter = 0; //counter is used to compare different letters between the two alphabets. Initialised to 0 to start from the first letter.
                    
            while (feof(input) == 0){ //this loop controls how long the code reads from the file. Reaching the end of text = 0, and will quite the loop.
                while(feof(input) == 0){
                fscanf(input, "%c", &c);// fscanf reads from input file and stores the message typed in input.txt in variable 'c'. Use %c to read individual characters, and & for 'address of c'
                    for (counter = 0; counter < 25; counter ++){ // <25 because it reaches the end of the alphabet.
                        if (c == messageletter[counter]){ //for loop runs until the ascii values of c and substitutionletter match
                            printf("%c", substitutionletter[counter]);//when they match, print the corresponding message letter. %c because it processes individual characters
                            fprintf(output, "%c", substitutionletter[counter]);//print to output.txt as well. %c because it processes individual characters
                        } 
                    }
                }
            }
        }

   } while(selection < 'a' || selection > 'd'); // condition tested after the code runs once, to make sure the letter selected was one of the options. 
   
    return 0;
}
