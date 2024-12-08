#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to perform ROT encryption
void applyROT(char *input, int rot) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            char base = islower(input[i]) ? 'a' : 'A';
            input[i] = (input[i] - base + rot) % 26 + base;
        }
    }
}

// Function to find numeric replacement based on odd/even key
void replaceWithNumeric(char *input, char *key, int *output) {
    int odd[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51};
    int even[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50};
    int keyLen = strlen(key);
    int keyIndex = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            int index = tolower(input[i]) - 'a'; // Always use lowercase for indexing
            int currentKey = key[keyIndex++] - '0';
            if (currentKey % 2 == 0) {
                output[i] = even[index];
            } else {
                output[i] = odd[index];
            }
            keyIndex %= keyLen; // Loop back the key index
        } else {
            output[i] = -1; // For non-alphabetic characters
        }
    }
}

void encrypt(char *input, char *key, int rot) {
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    printf("Enter ROT value: ");
    scanf("%d", &rot);

    printf("Enter the key: ");
    scanf("%s", key);

    while (getchar() != '\n'); // Flush buffer

    // Encrypt the message
    applyROT(input, rot);
    int encoded[200];
    replaceWithNumeric(input, key, encoded);

    printf("Encoded numeric message: ");
    for (int i = 0; input[i] != '\0'; i++) {
        if (encoded[i] != -1) {
            printf("%d ", encoded[i]);
        } else {
            printf(" "); // Preserve spaces
        }
    }
    printf("\n");
}

int main() {
    char input[200], key[20], choice;
    int rot;

    printf("Enter the original message: ");
    fgets(input, 200, stdin);

    encrypt(input, key, rot);
    return 0;
}
