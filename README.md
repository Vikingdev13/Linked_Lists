[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=3506055&assignment_repo_type=AssignmentRepo)
# Creating Linked Lists
## Points: 25

## Submission
`commit` and `push` your code to the `master` branch on the remote GitHub repository **before** the deadline.

## Clone
`clone` this repo to repl.it or your local machine using the link provided on the GitHub repo page.

Use the included files as your template to start the program maintaining the filenames given.

## Description
For this assignment you will perform several tasks:

- [ ] 1. Ask the user to enter in the number of nodes for the linked list
- [ ] 2. Generate a list with the # of nodes specified by the user
	* Each node will contain a random number with the range **0-9999**
- [ ] 3. Print out the generated list **(10 per line)**
- [ ] 4. Ask the user to enter in a number
	* Search the list and see if the number is in the list
- [ ] 5. If the number is in the list, change that node's value to a value specified by the user
	* print the list to verify that the specified node was changed
- [ ] 6. Search the list again for a value, if found, delete that node
	* print the list to verify that the node was deleted
- [ ] 7. Search the list and find out if there are any duplicate values in the list and print them out


### Required Functions
_*Functions that have a `P` are functions you are allowed to print in_

```c
/**
 * create a node for your list
 * return a pointer to that node (node *)
 */  
node *makeNode(int val);

/**
 * add a node to the front of the list
 * return new front of list
 */
node *insertFront(node *head, node *new);

/**
 * P: print out the linked list (10 per line)
 */
void printList(node *head);

/**
 * P: given a value, search the list and remove the node with that value
 */
node *deleteNode(node *head, int val);

/**
 * given a new and old value, search the list for the old value and change it to the new one
 */
node *modifyNode(node *head, int old, int new);

/**
 * given a value, searches the list for that value
 * return true or false (or an integer 0 or 1 that you can use as true or false)
 */
int inList(node *head, int val);

/**
 * P: search the linked list looking for any duplicate values in the list
 */
void lookForDupes(node *L);

/**
 * --Optional--
 * returns the number of nodes in a given list
 */
int length(node *L);
```

### Example Output
```
$ ./a.out
How many nodes? 20
8430 2799 4782 9705 7778 7618  473  878 8270 7042 
4739 8414  188 1474 7954 7162 9796 3059 5374  212 

Enter a number to search for: 2799
Found in list
Change to what value? 1
8430    1 4782 9705 7778 7618  473  878 8270 7042 
4739 8414  188 1474 7954 7162 9796 3059 5374  212 

Enter a number to remove: 1
   1 was deleted from the list
8430 4782 9705 7778 7618  473  878 8270 7042 4739 
8414  188 1474 7954 7162 9796 3059 5374  212 

No Dupes Found :(
```

```
$ ./a.out
How many nodes? 15
9564 6561 7377 2904 4080  255 5940 4604 6782 4102 
  29 1955 5023 5536 8641 

Enter a number to search for: 9564
Found in list
Change to what value? 1111
1111 6561 7377 2904 4080  255 5940 4604 6782 4102 
  29 1955 5023 5536 8641 

Enter a number to remove: 0
No node to delete
1111 6561 7377 2904 4080  255 5940 4604 6782 4102 
  29 1955 5023 5536 8641 

No Dupes Found :(
```

```
$ ./a.out
How many nodes? 10
8163  285 4482 4425 5799 6812 7003 5507 1190 6958 

Enter a number to search for: 0
Not in list

Enter a number to remove: 8163
8163 was deleted from the list
 285 4482 4425 5799 6812 7003 5507 1190 6958 

No Dupes Found :(
```

```
$ ./a.out
How many nodes? 5
8667 5337 2002 2216 4007 

Enter a number to search for: 4007
Found in list
Change to what value? 8667
8667 5337 2002 2216 8667 

Enter a number to remove: 2002
2002 was deleted from the list
8667 5337 2216 8667 

Dupe found: 8667
Dupe found: 8667
```
