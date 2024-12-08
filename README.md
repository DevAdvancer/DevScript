# DevScript Documentation

## Introduction
DevScript is an encryption and decryption algorithm that utilizes a combination of ROT (rotation) cipher and numeric encoding based on a user-defined key. This algorithm first applies ROT to shift the characters in the original message, and then encodes the message into numeric values based on the odd/even positions in the alphabet. The decryption process reverses this procedure to recover the original message.

## Features
- **ROT Encryption and Decryption**: A customizable shift value (ROT) to encode and decode alphabetic characters.
- **Numeric Encoding**: The algorithm converts alphabetic characters into numeric values, which are determined by whether the character corresponds to an odd or even number in the alphabet.
- **Key-Based Encoding**: The numeric encoding relies on a user-provided key to determine how alphabetic characters are mapped to numeric values.
- **Reversible Process**: The decryption function reverses the numeric encoding and applies the reverse ROT to recover the original message.

## How It Works

### 1. **Encryption Process**
- **Step 1**: Apply **ROT encryption** to shift each character in the message by a specified value. This is done for each alphabetic character while preserving non-alphabetic characters (like spaces).
- **Step 2**: Use the **numeric encoding** scheme, which assigns numeric values to the characters based on the odd/even positions in the alphabet. The user-provided key is used to decide whether an alphabetic character corresponds to an odd or even value.
- **Step 3**: Convert the entire string into a series of numeric values representing the encoded message.

### 2. **Decryption Process**
- **Step 1**: Take the **encoded numeric message** and use the key to map the numeric values back to their corresponding alphabetic characters.
- **Step 2**: Apply the **reverse ROT** to shift the characters back by the specified value, restoring the original message.

### 3. **Key and ROT**
- The **key** is a sequence of digits, where each digit determines whether an alphabetic character is mapped to an **odd** or **even** value.
- The **ROT value** is a user-defined integer that specifies the number of positions to shift each letter in the message.

## How to Use

### Input Format

- **Message**: The original message to be encrypted or decrypted.
- **ROT value**: A numerical value specifying the number of positions to shift each letter in the alphabet.
- **Key**: A sequence of digits (e.g., `234`), which is used to map alphabetic characters to either odd or even values based on their positions in the alphabet.

### Output Format

- **Encoded Numeric Message**: The encrypted message represented as a series of numbers.
- **Decrypted Message**: The recovered original message after decoding and reversing the ROT shift.

## Example

### Encryption Example

1. **User Input**:
    - Message: `hello world`
    - ROT value: `5`
    - Key: `234`

2. **Process**:
    - Apply ROT(5): `mjqqt btwqi`
    - Apply numeric encoding: `26 10 16 16 42 -1 4 46 38 16 8`

3. **Output**:
    ```
    Encoded numeric message: 26 10 16 16 42 -1 4 46 38 16 8
    ```

### Decryption Example

1. **User Input**:
    - Encoded numeric message: `26 10 16 16 42 -1 4 46 38 16 8`
    - ROT value: `5`
    - Key: `234`

2. **Process**:
    - Decode numeric values: `mjqqt btwqi`
    - Reverse ROT(5): `hello world`

3. **Output**:
    ```
    Decrypted message: hello world
    ```

## Key Functions

### `applyROT`
```c
void applyROT(char *input, int rot);
```

- Description: Reverses the ROT encryption.
- Parameters:

  - input: The string to be decrypted.
  - rot: The ROT shift value.

### `replaceWithNumeric`
```c
void replaceWithNumeric(char *input, char *key, int *output);
```
- **Description**: Converts the string into numeric values based on the key.
Parameters:

    - input: The string to be encoded.
    - key: The user-defined key.
    - output: The resulting array of numeric values.

### `decryptNumeric`
```c
void decryptNumeric(int *encoded, int length, char *key, char *output);
```
- **Description**: Decodes the numeric message back into characters.
- **Parameters**:

    - `encoded`: The array of numeric values.
    - `length`: The length of the encoded message.
    - `key`: The user-defined key.
    - `output`: The resulting decoded string.

### Error Handling

- If the user enters an invalid option (`E` or `D`), the program will prompt them to enter a valid option.
- If the numeric encoding contains values outside of the expected range or invalid characters, the program will handle these gracefully by preserving non-alphabetic characters.

### Future Improvements

- Add more encryption techniques in combination with ROT for enhanced security.
- Implement the option to handle different character sets (e.g., numbers, punctuation).
- Provide better handling of input sanitization and validation.

## Cryptography Implementation in C

A robust implementation of a custom encryption and decryption system combining ROT cipher with numeric substitution using even/odd number patterns.

## Features

- Custom encryption algorithm combining:
  - ROT cipher (configurable rotation value)
  - Numeric substitution based on even/odd key patterns
- Secure key-based encryption
- Support for alphabetic characters with space preservation
- Interactive menu-driven interface for encryption/decryption choice

## Project Structure

- `devscript.c` - Main implementation with both encryption and decryption functionality
- `Encypt.c` - Standalone encryption implementation
- `Decript.c` - Standalone decryption implementation

## How It Works

### Encryption Process

1. **ROT Cipher**: First layer of encryption using a configurable ROT value
2. **Numeric Substitution**: 
   - Even key digits map to even number sequence: [2,4,6,...,50]
   - Odd key digits map to odd number sequence: [1,3,5,...,51]
3. **Space Preservation**: Non-alphabetic characters are preserved in the output

### Decryption Process

1. **Numeric to Alpha**: Converts numeric values back to letters using the key pattern
2. **ROT Reversal**: Applies reverse ROT transformation using the original ROT value

## Usage

### Using Combined Script (Recommended)

```bash
gcc devscript.c -o cryptography
./cryptography
```

Follow the interactive prompts:
1. Choose operation mode (E for encryption, D for decryption)
2. For encryption:
   - Enter the original message
   - Specify ROT value
   - Enter the encryption key
3. For decryption:
   - Enter the length of the numeric message
   - Input the numeric message (space-separated)
   - Provide the ROT value
   - Enter the decryption key

### Using Standalone Programs

#### Encryption
```bash
gcc Encypt.c -o encrypt
./encrypt
```

#### Decryption
```bash
gcc Decript.c -o decrypt
./decrypt
```

## Security Considerations

- The encryption strength depends on:
  - ROT value complexity
  - Key length and randomness
  - Combined effect of dual encryption layers
- Not recommended for production security-critical applications
- Designed for educational and demonstration purposes

## Requirements

- C compiler (gcc recommended)
- Standard C libraries:
  - stdio.h
  - string.h
  - ctype.h

## Building from Source

```bash
# Build combined encryption/decryption program (recommended)
gcc devscript.c -o cryptography

# Or build standalone programs
gcc Encypt.c -o encrypt
gcc Decript.c -o decrypt
```

## License

This project is open source and available under the MIT License.

## Contributing

Feel free to submit issues and enhancement requests!
