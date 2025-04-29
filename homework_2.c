//cezar
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXN 1000

char* cezar_cipher(char* str, int key) {
    int length = strlen(str);
    char* cipher = (char*) malloc(sizeof(char) * (length + 1));

    for (int i = 0; i < length; i++) {
        char ch = str[i];

        // Lowercase letters
        if (ch >= 'a' && ch <= 'z') {
            cipher[i] = ((ch - 'a' + key) % 26) + 'a';
        }
        // Uppercase letters
        else if (ch >= 'A' && ch <= 'Z') {
            cipher[i] = ((ch - 'A' + key) % 26) + 'A';
        }
        // Digits
        else if (ch >= '0' && ch <= '9') {
            cipher[i] = ((ch - '0' + key) % 10) + '0';
        }
        else {
            cipher[i] = ch;
        }
    }

    cipher[length] = '\0';
    return cipher;
}

void save_to_file(const char* filename, const char* cipher) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s\n", cipher);
    fclose(file);
}

int main() {
    char str[MAXN];
    int key;

    printf("Enter a message: ");
    fgets(str, MAXN, stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Enter key: ");
    scanf("%d", &key);

    char* cipher = cezar_cipher(str, key);
    printf("Encrypted: %s\n", cipher);

    save_to_file("cipher.txt", cipher);

    free(cipher); 
    return EXIT_SUCCESS;
}
