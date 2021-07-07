Project 1: Tokenizer
====================
Overview:
The objective of this program is to build a tokenizer that divides strings
into tokens. In other words, when given a string, the program should split each
word of that string and insert them into tokens. Take for example the string
"My dog has fleas." Then the result for such string will be:
["My", "dog", "has", "fleas"].
It should also keep history of each word where the user can call each item by
addressing it with a number. For example, if the user were to input "!4" then
the program will print or recall the word "fleas".

Tokenizer.c:
This file defines the tokenizer used in this program. Included in this c file
there are helper methods such as:
      space_char - Determines if a character is a blank space or a tab.
      non_space_char - Negation of space_char.
      word_start - Returns a pointer to the first character of the next
      		  space-separated word.
      Word_terminator - Returns pointer that is the end of a word.
      count_words - Gets the total number of words in a string.
      copy_str - Copies a whole word into an allocated space.

The actual tokenizer method implements all the helper methods to create the
tokenizer. The tokenizer is defined by a double pointer where each pointer
will point to a word in from the string. In addition to helper methods, there
are two other methods, print_tokens and free_tokens that prints all the words
that was tokenized and free all the sapced used in the tokenizer, respectevly.

History.c:
The history can be represented as a linked list data structure where each node
contains a previous word from a string, its id based on its place in the
linked list, and a pointer pointing to the next node. With this in mind, we
define two different structures:
       List - Represents the linked list and contains the root or head node of
       	      the list.
       Item - Represents the nodes in the list which contains the id, the word
       	      string, and a pointer to the next node.

For the data structure to be functional, we implemented:
       init_history - Initalizes the linked list and sets the head node as zero.
       add_history - Creates a new node with its respective id and the word
       		     being added and insert the node to the end of the list.
       get_history - Retieves the string stores in the node with a specific id.
       
And such like the tokenizer, we have two methods that print and frees the contents of
the linked list.

Main.c:
The main method recieves the input of the user and creates a tokenizer from
that string input. It will also create a linked list where every token of the
tokenizer is saved. Afterwards, the user can type some commands to recall or
print out previous words from the string inputted.

User Commands:
The user have three specific commands to navigate thru this program:
    "!h" - Print all the words in history and their respective id's for user to
       	 use as referance.
    "!<id>" - Prints the word associated with that the inputted id. If id
    	    doesn't exists then nothing is printed.
    '0' - Exits and ends program.
