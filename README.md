# Phone-Directory




<br />
<div align="center">
  <a href="https://github.com/shu3102/Phone-Directory">
    ![image](https://user-images.githubusercontent.com/69418944/188409541-b16abd0b-9459-458e-9a8b-cc0762960848.png)
  </a>

  <h3 align="center">Phone Directory</h3>

</div>







<!-- ABOUT THE PROJECT -->
## About The Project


A `telephone directory`, commonly called a telephone book, telephone address book, phone book.

[https://github.com/shu3102/Phone-Directory/blob/main/Output/Screenshot%20(71).png]
![Screenshot]([https://github.com/shu3102/Phone-Directory/blob/main/Output/Screenshot%20(71).png])


This PhoneDirectory Mini Project in C language is a console-based application written in the C programming language. This system is a simple little project that was compiled with the GCC compiler.

This project allows you to add, search, update, and delete like basic operations phonebook information. and advance operations like **PRIVATE PHONEBOOK** and support for **IMPORT AND EXPORT** contact .






### Run

```
gcc -o executable_files/phonebookNew main.c codes/Excel.c codes/List.c codes/Password.c codes/Phone1.c codes/Stack.c codes/Phone.h
```



### Data Structure Used

```TRIE```

**1. TRIE 2. STACK 3. QUEUE. etc**


In computer science, a `trie`, also called `digital tree` or `prefix tree`, is a type of k-ary search tree, a tree data structure used for locating specific keys from within a set. These keys are most often strings, with links between nodes defined not by the entire key, but by individual characters. In order to access a key (to recover its value, change it, or remove it), the `trie` is traversed depth-first, following the links between nodes, which represent each character in the key.

``
Unlike a binary search tree, nodes in the trie do not store their associated key. Instead, a node's position in the trie defines the key with which it is associated. This distributes the value of each key across the data structure, and means that not every node necessarily has an associated value.
``

  
For Ex.
     
       
![image](https://user-images.githubusercontent.com/69418944/188397922-a7548b3e-1948-4665-88cc-574b776fd24c.png)



### Complexities

     1. Time complexity in big O notation
     

         | Algorithm          |  Average   |   Worst case   |
         | -----------------  | -----------|--------------- |
         | `Space`            |   O(n)     |   O(n)         |
         | `Search`           |   O(n)     |   O(n)         |
         | `Insert`           |   O(n)     |   O(n)         |
         | `Delete`           |   O(n)     |   O(n)         |
     
   


## Available Functions

- `Phone Directory` You can save names, email addresses, phone numbers, and more in Phone Directory.

- Add, move contacts
- Edit or delete contacts
- View contacts, group.

- Import contacts from `csv file`
- Export contacts to `csv file`, back up, or restore contacts.

- Hiding Contacts (Private Phonebook)


## Commands

   1. ```Commands Available```

      1. Commands and their Description

         | Function          | Description                                          |
         | ----------------- | ---------------------------------------------------- |
         | `add`             | to add the contact to phonebook                      |
         | `edit`            | to edit the contact of phonebook                     |    
         | `modify`          | to modify the contact of phonebook                   |
         | `mfev`            | to make current contact favourite                    |
         | `show`            | to print all the contacts to phonebook               |
         | `delete`          | to delete the contact from phonebook                 |
         | `ispresent`       | to check is the contact present in phonebook         |
         | `search`          | to prefix search                                     |
         | `rexcel`          | to import excel file to phonebook                    |
         | `wexcel`          | to export the phonebook                              |
         | `prinsert`        | to insert the contact to Private phonebook           |
         | `prshow`          | to print the contact of Private phonebook            |
         | `showrd`          | to print the recently deleted contact of phonebook   |
         | `showfc`          | to print the Favourite contact of phonebook          |
         | `sortfev`         | to sort the fevourite contact of phonebook           |
         

![image](https://user-images.githubusercontent.com/69418944/188403095-f077413e-2017-4000-bffd-d0171a072012.png)


## References

- [TRIE](https://en.wikipedia.org/wiki/Trie)
- [Directory](https://en.wikipedia.org/wiki/Telephone_directory)
>>>>>>> 8c1b546fee124c7e02a08cd23bd61ce4c725f4f3

