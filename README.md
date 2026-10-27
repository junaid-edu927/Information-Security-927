##Google Drive: https://drive.google.com/drive/folders/1LtdoFFOUgAfOOKjkgayvlW_bfDC9d8-U?usp=drive_link

# Custom Cipher Implementation

## Overview
This project implements a custom cryptographic algorithm that combines the mathematical properties of the **Hill Cipher** with an **AES-like shifting method** to provide a multi-layered encryption process. The system includes two separate programs: one for encryption and one for decryption.

## Key Concepts (From Report)
* **Letter to Number Conversion**: All alphabetical characters are converted to numerical equivalents before processing (A=0, B=1, ..., Z=25).
* **Hill Cipher Transformation**: Uses matrix multiplication to encrypt pairs of letters.
* **Reversibility**: During decryption, the decrypted number pairs successfully become the original pairs, ensuring data integrity.

---

## Algorithm Steps

### 1. Encryption Process (`encryption.cpp`)
The encryption is performed in three distinct steps:
1. **Step 1: Grouping Preparation** 
   * Converts the input text (uppercase letters only) into numbers (A=0 to Z=25).
   * Groups the numbers into pairs. If the text length is odd, it pads the end with the letter 'X' (value 23).
2. **Step 2: Hill Cipher Application** 
   * Applies a 2x2 key matrix to the number pairs using modulo 26 arithmetic.
3. **Step 3: AES-like Shifting Method** 
   * Performs a positional shift on blocks of 4 numbers to add an extra layer of diffusion, similar to the ShiftRows step in AES.

### 2. Decryption Process (`decryption.cpp`)
The decryption reverses the encryption process in the exact opposite order:
1. **Step 1: Reverse AES-like Shifting** 
   * Reverses the positional shifts applied to the blocks of 4 numbers.
2. **Step 2: Reverse Hill Cipher** 
   * Multiplies the number pairs by the inverse of the 2x2 key matrix modulo 26. The decrypted number pairs become the original pairs.
3. **Step 3: Combine The Text** 
   * Converts the numerical values back into alphabetical characters (A=0 to Z=25).
   * Removes any padding added during the grouping preparation phase.

---

## Compilation and Usage

Ensure you have a C++ compiler (like `g++`) installed on your system.

### Compile the files:
```bash
# Compile Encryption
g++ encryption.cpp -o encrypt

# Compile Decryption
g++ decryption.cpp -o decrypt
