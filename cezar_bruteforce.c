#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXN 1000
#define ALPHA_LENGTH 26

//(str[i] - 'a') + shift) %26 + 'a' 
char* cezar_decipher(char* cipher, int key){
    int lenght = (strlen(cipher));
    char* plaintext = (char*) malloc (sizeof(char)*(lenght+1));
    for(int i=0; i<lenght; i++){
        if(cipher[i] >= 'a' && cipher[i] <='z')
        {
            plaintext[i] = ((cipher[i]- 'a')-key+26) % 26 +'a';
        }
        else if (cipher[i] >= 'A' && cipher[i] <='Z')
        {
            plaintext[i] = ((cipher[i]- 'A')-key+26) %26 +'A';
        }
        else if (cipher[i] >= '0' && cipher[i] <='9')
        {
            plaintext[i] = ((cipher[i]- '0')-key+10) %10 +'0';
        }
        else
        {
            plaintext[i] = cipher[i];
        }
    }
    return plaintext;
}


int main()
{
    char cipher[MAXN];
    scanf("%s",cipher);
    for(int key=0;key<ALPHA_LENGTH;key++){
        char* plaintext = cezar_decipher(cipher, key);
        printf("%s,key=%d -> %s\n",cipher,key,plaintext);
        free (plaintext);
    } 
    return EXIT_SUCCESS;
}
