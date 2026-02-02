# Morse Code Translator (C Language)

A lightweight, efficient command-line utility written in C that translates English text to Morse code and decodes Morse code back into English.

## 🚀 Features
- **Bi-directional Translation:** Convert English (A-Z, 0-9) to Morse and vice versa.
- **Input Cleaning:** Handles mixed-case English input and cleans trailing newlines for robust processing.
- **Efficient Mapping:** Uses parallel arrays and index-based searching for $O(N)$ translation performance.
- **Tokenization:** Utilizes `strtok` for advanced string manipulation of Morse symbols.

## 🛠️ Technical Concepts Used
* **Pointers & Arrays:** Managed a collection of Morse strings using an array of pointers (`const char *MORSE[]`).
* **String Manipulation:** Implemented `string.h` functions including `strtok`, `strcmp`, and `strcspn`.
* **Nested Logic:** Used nested loops to map characters from the `ALPHA` dictionary to the `MORSE` dictionary.

## 📋 How to Use
1. **Compile the code:**
   ```bash
   gcc main.c -o MorseTranslator
