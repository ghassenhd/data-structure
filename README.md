# data-structure
Data structure manipulation in C
This is a set of functions for handling a singly linked list

Pros:
 - easy to read and short.
 - the linked list data is generic (can be any type of struct).
 - the comparition between data is up to you to define and can be changed between tow calls of the same function .

Limitation :
 - the definition of the linked list data needs to be in the same file.
 - only 1 definition of the linked list data.

Next goals:
  - changing the type of linked list data to a void pointer ( ll_data--> void *) so a multiple definition of data can be used.
  - add include header file so this function can be compiled alone and used as a library.
  - add support for other type data structures.
