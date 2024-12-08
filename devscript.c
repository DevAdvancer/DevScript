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

// Function to reverse ROT for decryption
void reverseROT(char *input, int rot) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            char base = islower(input[i]) ? 'a' : 'A';
            input[i] = (input[i] - base - rot + 26) % 26 + base;
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
            int index = tolower(input[i]) - 'a';
            int currentKey = key[keyIndex++] - '0';
            if (currentKey % 2 == 0) {
                output[i] = even[index];
            } else {
                output[i] = odd[index];
            }
            keyIndex %= keyLen; // Loop back the key index
        } else {
            output[i] = -1; // For non-alphabetic characters (e.g., spaces, punctuation)
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

    for (int i = 0; i < length; i++) {
        if (encoded[i] == -1) {
            output[i] = ' '; // Handle spaces or punctuation
        } else {
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
    output[length] = '\0'; // Null-terminate the decrypted string
}

int main() {
    char input[200], key[20], choice;
    int rot;

    printf("Do you want to (E)ncrypt or (D)ecrypt a message? ");
    scanf(" %c", &choice);

    if (choice == 'e' || choice == 'E') {
        // Input original message, ROT value, and key for encryption
        printf("Enter the original message: ");
        getchar(); // Consume leftover newline
        fgets(input, 200, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character
        printf("Enter ROT value: ");
        scanf("%d", &rot);
        printf("Enter the key: ");
        scanf("%s", key);

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

    } else if (choice == 'd' || choice == 'D') {
        // Input numeric encoded message, ROT value, and key for decryption
        int encoded[200], length = 0;
        printf("Enter the length of the numeric message: ");
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
        char decodedMessage[200];
        decryptNumeric(encoded, length, key, decodedMessage);

        // Reverse ROT
        reverseROT(decodedMessage, rot);

        printf("Decrypted message: %s\n", decodedMessage);
    } else {
        printf("Invalid choice. Please enter E for encryption or D for decryption.\n");
    }

    return 0;
}
