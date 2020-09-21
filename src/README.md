Project 1: Tokenizer
====================
# What the program does:

  The user will be asked to enter a sentence that he would like tokenized.
  After inputting the sentence, the program will print the tokenized version
  of the sentence.
  From there, it will add it to the history linked list.
  The program will ask the user if they want to see the history.

# Explanation of how some functions work:

  # In work_strings.c:
     space_char(); checks if the current character is a whitespace using if
     statement.
     
     non_space_char(); checks if the current character is not a whitespace
     using if statement.
     
     word_start(); uses a while loop to traverse through whitespaces to return
     a pointer at the start of the string.
     
     word_terminator(); uses a while loop to traverse through a word and
     returns a pointer at the first whitespace.
     
     count_words(); first finds the start of the string and then traverses
     through the string using a for loop with an if statements that checks if
     there is a space in between characters and increments count.
     
     copy_str(); this function uses a for loop to traverse through the entire
     string and make a copy of each character.
     
     tokenize(); first initialize character pointers to start and end to only
     add one word into each token. a for loop will start to traverse through
     the string. An if statement is added to add memory the same size as the
     first word to the first token index. Else, every word after, it
     calculates the new start and new end of each word and adds new memory to
     the next index of the token. For each token, a for loop is created to
     start adding each character from the word.
     print_tokens(); uses for loop to iterate through the tokens and print
     each.
     
     free_tokens(); uses for loop to iterate through the tokens and free each.

  # In history.c:
    init_history(); simply initializes the linked list.

    add_history(); first checks to see if the list is empty. If it is, it will
    add the first item to the root. It adds the number 0, the string and
    assigned next to NULL. Then a while loop is used to traverse through the
    end of the list. Once the end is found, a new item will be created and the
    new id and the new string will be added.

    get_history(); first assigns the root of the list to a temp variable. a
    while loop then is creating to iterate through the linked list. and if
    statement is added inside to check if the id is found. if it is, it will
    return the string. if the id was never found, a message will return
    telling the user that the id was not found.

    print_history(); assings root to temp variable. while loop to iterate
    through the entire linked list and prints each item.

    free_history(); assigns root to temp then a while loop is implemented to
    traverse the entire linked list while at the same time is is assigning the
    new root to temp and frees each item it finds. For here, I had to change
    the root first if not it will lose the pointer.
