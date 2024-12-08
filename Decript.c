#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse ROT for decryption
void reverseROT(char *input, int rot) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            char base = islower(input[i]) ? 'a' : 'A';
            input[i] = (input[i] - base - rot + 26) % 26 + base;
        }
    }
}

// Function to decrypt numeric encoded message
void decryptNumeric(int *encoded, int length, char *key, char *output) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int odd[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51};
    int even[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50};
    int keyLen = strlen(key);
    int keyIndex = 0;

    // Initialize output to spaces
    for (int i = 0; i < length; i++) {
        output[i] = ' ';
    }
    output[length] = '\0';

    for (int i = 0; i < length; i++) {
        if (encoded[i] != -1) {
            int currentKey = key[keyIndex++] - '0';
            for (int j = 0; j < 26; j++) {
                if ((currentKey % 2 == 0 && even[j] == encoded[i]) ||
                    (currentKey % 2 != 0 && odd[j] == encoded[i])) {
                    output[i] = alphabet[j];
                    break;
                }
            }
            keyIndex %= keyLen; // Loop back the key index
        }
    }
}

int main() {
    int encoded[200], length = 0;
    char key[20], decodedMessage[200];
    int rot;

    // Input numeric encoded message, ROT value, and key for decryption
    printf("Enter the number of elements in the numeric message: ");
    scanf("%d", &length);

    printf("Enter the numeric message separated by spaces: ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &encoded[i]);
    }

    printf("Enter ROT value: ");
    scanf("%d", &rot);
    printf("Enter the key: ");
    scanf("%s", key);

    // Decrypt the message
    decryptNumeric(encoded, length, key, decodedMessage);

    // Reverse ROT
    reverseROT(decodedMessage, rot);

    printf("Decrypted message: %s\n", decodedMessage);

    return 0;
}