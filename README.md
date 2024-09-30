Bill Machine - Market Shopping Checklist System
Project Overview
This project is a simple yet functional bill machine system designed to manage a market shopping checklist. The system allows users to add items with prices to a pricelist, create a shopping checklist by selecting items from the pricelist, and view or modify the checklist. The project is written in C and makes use of file handling to store and retrieve data.

The project consists of three core files:

functions.h - Header file with function declarations and struct definitions.
functions.c - Implementation of the functions that handle the pricelist, checklist operations, and file handling.
program.c - The main program that provides an interactive command-line interface for users.
Additionally, the system uses two data files:

checklist.txt - Stores the user's final shopping list.
pricelist.txt - Stores the list of items available with their prices.
Features
Pricelist Management:

Add new items to the pricelist.
View the current pricelist.
Refresh the pricelist to start from scratch.
Checklist Management:

Add items from the pricelist to the shopping checklist.
View the checklist with all items and their respective prices.
Delete items from the checklist.
Upload and save the final checklist to a file.
File Handling:

The project saves the pricelist and checklist to files, ensuring data persistence between sessions.
How to Use
Compile both program.c and functions.c together using the command:
bash
Copy code
gcc program.c functions.c -o bill_machine
Run the compiled program:
bash
Copy code
./bill_machine
Commands Available:
new: Renew the entire pricelist.
add_price: Add new items to the existing pricelist.
price: View the current pricelist.
add: Add items from the pricelist to your shopping checklist.
list: View all the items in your checklist.
del: Delete an item from your checklist.
update: Upload and save the checklist to a file.
view: View your saved checklist from the file.
options: Review all the available commands.
end: Exit the program.
