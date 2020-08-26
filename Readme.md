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


## AES

**Key Expansion Algorithm**:

The AES key expansion algorithm takes as input a four-word (16-byte) key and produces a linear array of 44 words (176 bytes).

![AES-Encryption-1-A-AES-The-Advanced-Encryption-Standard-AES-standard-became](https://user-images.githubusercontent.com/33808300/91316932-b3d0e800-e7b9-11ea-81d4-3ae90f878ec8.png)
