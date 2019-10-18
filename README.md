# BookWarehouse_SLL
This project implements a book warehouse by reading in an input file from the command line.  This project can check for an empty and return an error message if this is the case. Otherwise,  the file is expected to contain certain information on each successive line. For one book object,  the first line must be the title. After the first line, the following lines contain the following information: the number of authors, the authors, the publisher, the publishing date, a boolean value that indicates whether a book is a hardcover or paperback, the price, the ISBN number, and the number  of copies. The project reads each book by overloading the extraction operator, and then inserts these  book objects into a growing singly linked list. The project automatically sorts the books based on the ISBN numbers. Afterwards, the user can choose to either locate a book or list the books. The project reads the books and displays them on the screen by using and overloading the insertion operator. Users simply  need to write one command line with additional tags, specifically, the name of the file they are inputting, and  the function they'd like ("list" or "find"). 
