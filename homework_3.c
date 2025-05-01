//vigenere
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 4096 

char* vigenere_encrypt(char* plaintext, char* key)
{
    int text_length = strlen(plaintext);
    int key_length = strlen(key);

    char* cipher = (char*) malloc(sizeof(char) * (text_length + 1));
    if (!cipher) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            int shift = tolower(key[i % key_length]) - 'a';
            if (islower(plaintext[i]))
                cipher[i] = 'a' + (plaintext[i] - 'a' + shift) % 26;
            else
                cipher[i] = 'A' + (plaintext[i] - 'A' + shift) % 26;
        }
        else
        {
            cipher[i] = plaintext[i]; 
        }
    }

    cipher[text_length] = '\0';
    return cipher;
}

void read_file(const char* filename, char* buffer, int max_size)
{
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fgets(buffer, max_size, file);
    buffer[strcspn(buffer, "\n")] = '\0'; 
    fclose(file);
}

int main()
{
    char text[MAXN];
    char key[MAXN];

    read_file("message.txt", text, MAXN);
    read_file("key.txt", key, MAXN);

    char* cipher = vigenere_encrypt(text, key);

    FILE* out = fopen("cipher.txt", "w");
    if (!out) {
        printf("Could not open output file.\n");
        free(cipher);
        return EXIT_FAILURE;
    }
    fprintf(out, "%s", cipher);
    fclose(out);

    printf("Encrypted message saved to cipher.txt\n");
    free(cipher);
    return EXIT_SUCCESS;
}
