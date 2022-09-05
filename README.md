# Phone-Directory
A telephone directory, commonly called a telephone book, telephone address book, phone book.



### About

A `telephone directory`, commonly called a telephone book, telephone address book, phone book.


### Data Structure Used

```TRIE```

In computer science, a `trie`, also called `digital tree` or `prefix tree`, is a type of k-ary search tree, a tree data structure used for locating specific keys from within a set. These keys are most often strings, with links between nodes defined not by the entire key, but by individual characters. In order to access a key (to recover its value, change it, or remove it), the `trie` is traversed depth-first, following the links between nodes, which represent each character in the key.

``
Unlike a binary search tree, nodes in the trie do not store their associated key. Instead, a node's position in the trie defines the key with which it is associated. This distributes the value of each key across the data structure, and means that not every node necessarily has an associated value.
``

<b>Complexities</b>
     1. <b>Time complexity in big O notation<b/>

         | Algorithm          |  Average   |   Worst case   |
         | -----------------  | -----------|--------------- |
         | `Space`            |   O(n)     |   O(n)         |
         | `Search`           |   O(n)	   |   O(n)         |
         | `Insert`           |   O(n)	   |   O(n)         |
         | `Delete`           |   O(n)	   |   O(n)         |
     
     For Ex.
     
       
![image](https://user-images.githubusercontent.com/69418944/188397922-a7548b3e-1948-4665-88cc-574b776fd24c.png)



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

