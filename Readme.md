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
| Block Cypher | Symmetric Algorithms        | [AES-256-GCM](http://nvlpubs.nist.gov/nistpubs/Legacy/SP/nistspecialpublication800-38d.pdf) |
| Block Cypher | Symmetric Algorithms | Feistel cypher|
|Functions | Key Derivation              | to be filled |
