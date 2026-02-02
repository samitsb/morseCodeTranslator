#include <stdio.h>
#include <string.h>
#include <ctype.h> //ctype for toupper function


// Global "Dictionary"
const char *ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const char *MORSE[] = {
    ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..", 
    ".---", "-.-",  ".-..", "--",   "-.",   "---",  ".--.", "--.-", ".-.", 
    "...",  "-",    "..-",  "...-", ".--",  "-..-", "-.--", "--..", // A-Z
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." // 0-9
};


void englishToMorse();
 
void morseToEnglish();  

int main() {
    int choice;

    do {
        printf("\n--- Morse Code Translator ---\n");
        printf("1. English to Morse\n");
        printf("2. Morse to English\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch(choice) {
            case 1: englishToMorse(); break;//break to avoid fall through
            case 2: morseToEnglish(); break;
            case 3: printf("Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 3);

return 0;
}

void englishToMorse() {
    char input[100];
    printf("Enter English Text: ");
    fgets(input, sizeof(input), stdin); //stdin to read string with spaces ,fgets for safer input
    input[strcspn(input, "\n")] = '\0'; //strcspn to remove newline character

    printf("Morse Code: ");

    for (int i = 0; input[i] != '\0'; i++) {
        char c = toupper(input[i]);
        
        if (c == ' ') {
            printf("/ "); 
            continue;//continue to next iteration
        }

        for (int j = 0; j < 36; j++) {//36 characters in ALPHA and MORSE
            if (c == ALPHA[j]) {
                printf("%s ", MORSE[j]);
                break;
            }
        }
    }
    printf("\n");
}

void morseToEnglish(){
    char input[100];
    printf("Enter the Morse Code (separate with spaces): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    char *token = strtok(input, " ");//strtok to split string by spaces
    
    printf("English Text: ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < 36; i++) {
            if(strcmp(token, MORSE[i]) == 0){
                printf("%c", ALPHA[i]);
                found = 1;
                break;
            }
        }
        
        if (!found) {
            printf("?");
        }
        token = strtok(NULL, " ");         
    }
    printf("\n");    
}