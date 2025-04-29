#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXN 1000
#define ALPHA_LENGTH 26
#define COMMON_COUNT 10

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

int* count_frequencies(char* cipher){
    int* frequency=(int*) malloc(sizeof(int) * ALPHA_LENGTH);
    memset(frequency,0,sizeof(int) ALPHA_LENGTH);

    int length = strlen (cipher);
    for(int i=0; i<length; i++){
        char letter = tolower(cipher[i]);
        if(letter >= 'a' && letter <= 'z'){
            int position = letter - 'a';
            frequency[position]++;
        }
    }
    return frequency;
}

int get_max_index(int* frequency){
    int max_index = 0;
    for (int i=0; i< ALPHA_LENGTH; i++){
        if (frequency[i] > frequency[max_index]){
            man_index = i;
        }
    }
    return max_index;

}


int main()
{
    char cipher[MAXN];
    scanf("%s",cipher);
    char letters [COMMON_COUNT] = {'e','a','t','o','i'};
    int most_common_letter = get_max_index(cipher) + 'a';


    for(int i=0;i<COMMON_COUNT;i++){
        char* plaintext = cezar_decipher(cipher, key);
        printf("%s,key=%d -> %s\n",cipher,key,plaintext);
        free (plaintext);
    } 
    return EXIT_SUCCESS;
}
