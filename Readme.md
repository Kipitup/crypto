## Introduction

Cryptography Implementation Library in C

IMPORTANT - This should not be used for anything important!
The goal of this library was to learn the basics of cryptography
but it has not been audited or protected against other attacks. When using cryptography for
any professional purpose, follow this cardinal rule - "don't roll your own crypto!"  

This library was built from the ground up. No external library was used.


This is designed to be a small, flexible and convenient wrapper for a variety of crypto algorithms.
Also, it provides several custom hybrid algorithms that combine different crypto algorithms to solve common complex cryptographic problems in an easy way.

## Features

This library is decomposed into small libraries with specific purposes.

### Library: Foundation

This library contains basic cryptographic algorithms and can be used as building blocks for complex solutions.

| Algorithm Type              | Algorithm Purpose           | Implementation details                                       |
| --------------------------- | --------------------------- | ------------------------------------------------------------ |
| Block Cypher | Symmetric Algorithms        | AES |
| Block Cypher | Symmetric Algorithms | Feistel cypher|
|Functions | Key Derivation              | to be filled |


## How to use

#### Pre required: Make, GCC. Optionally python3 for the tester.

First of all, open a terminal, go into the project and build it:   
```  
make -j8
```

We provided a python script to test all algorithms.
```
python3 test/ultimate_testor.py
```

## AES

**Key Expansion Algorithm**:

The AES key expansion algorithm takes as input a four-word (16-byte) key and produces a linear array of 44 words (176 bytes).

![AES-Encryption-1-A-AES-The-Advanced-Encryption-Standard-AES-standard-became](https://user-images.githubusercontent.com/33808300/91316932-b3d0e800-e7b9-11ea-81d4-3ae90f878ec8.png)


## Feistel Cypher

> In cryptography, a Feistel cipher is a symmetric structure used in the construction of block ciphers, named after the German-born physicist and cryptographer Horst Feistel who did pioneering research while working for IBM (USA); it is also commonly known as a Feistel network. A large proportion of block ciphers use the scheme, including the Data Encryption Standard (DES). The Feistel structure has the advantage that encryption and decryption operations are very similar, even identical in some cases, requiring only a reversal of the key schedule. Therefore, the size of the code or circuitry required to implement such a cipher is nearly halved. https://en.wikipedia.org/wiki/Feistel_cipher

![511px-Feistel_cipher_diagram_en svg](https://user-images.githubusercontent.com/33808300/91319110-48d4e080-e7bc-11ea-8f19-5a3605278ceb.png)
