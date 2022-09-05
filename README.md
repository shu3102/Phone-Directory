# Phone-Directory
<<<<<<< HEAD

<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>


<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/shu3102/Phone-Directory">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Phone Directory</h3>

  <p align="center">
   A telephone directory, commonly called a telephone book, telephone address book, phone book etc
    <br />
    <a href="https://github.com/shu3102/Phone-Directory"><strong>Explore the docs »</strong></a>
    <br />
    <a href="https://github.com/shu3102/Phone-Directory/tree/main/Output">View Demo</a>
    ·
    <a href="https://github.com/shu3102/Phone-Directory/issues">Report Bug</a>
    ·
    <a href="https://github.com/shu3102/Phone-Directory/issues">Request Feature</a>
  </p>
</div>







<!-- ABOUT THE PROJECT -->
## About The Project

[https://github.com/shu3102/Phone-Directory/blob/main/Output/Screenshot%20(71).png]
![Screenshot]([https://github.com/shu3102/Phone-Directory/blob/main/Output/Screenshot%20(71).png])


This PhoneDirectory Mini Project in C language is a console-based application written in the C programming language. This system is a simple little project that was compiled with the GCC compiler.

This project allows you to add, search, update, and delete like basic operations phonebook information. and advance operations like **PRIVATE PHONEBOOK** and support for **IMPORT AND EXPORT** contact .

The Data Structure used for this project is  
**1. TRIE 2. STACK 3. QUEUE. etc**




<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

This section should list any major frameworks/libraries used to bootstrap your project. Leave any add-ons/plugins for the acknowledgements section. Here are a few examples.

* C Language
* 
* 


<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.
* npm
  ```sh
  npm install npm@latest -g
  ```

### Installation

_Below is an example of how you can instruct your audience on installing and setting up your app. This template doesn't rely on any external dependencies or services._

1. Get a free API Key at [https://example.com](https://example.com)
2. Clone the repo
   ```sh
   git clone https://github.com/your_username_/Project-Name.git
   ```
3. Install NPM packages
   ```sh
   npm install
   ```
4. Enter your API in `config.js`
   ```js
   const API_KEY = 'ENTER YOUR API';
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_

<p align="right">(<a href="#readme-top">back to top</a>)</p>





<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>




<!-- CONTACT -->
## Contact

Your Name - [@your_twitter](https://twitter.com/your_username) - email@example.com

Project Link: [https://github.com/your_username/repo_name](https://github.com/your_username/repo_name)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

=======
A telephone directory, commonly called a telephone book, telephone address book, phone book.



### About

A `telephone directory`, commonly called a telephone book, telephone address book, phone book.


### Run

```
gcc -o executable_files/phonebookNew main.c codes/Excel.c codes/List.c codes/Password.c codes/Phone1.c codes/Stack.c codes/Phone.h
```



### Data Structure Used

```TRIE```

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

