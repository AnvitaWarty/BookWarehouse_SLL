#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>

using namespace std;
class Book {
	
 /**
 * @param is the input stream
 * @param book the book object to be filled
 * @return the input stream
 */
 friend istream& operator >> (istream& is, Book& book);
 
 /**
 * @param os the output stream
 * @param book the book object reference * @return the output stream
 */
 friend ostream& operator << (ostream& os, const Book& book);
 
 public:
  static const int MAX_AUTHORS = 35;
  
  Book();
  
  Book(string title, string authors[], int authorCount, string publisher,
  short yearPublish, bool hardcover, float price,
  string isbn, long copies);

  /** add all relevant setter and getter methods **/  
  string getTitle();
  string getIsbn() const; 
  Book* getNext() const;
  void setNext(Book* next);
  
 private:
  string title;
  string authors[Book::MAX_AUTHORS];
  int authorCount; 
  string publisher; 
  short yearPublish; 
  bool hardcover; 
  float price; 
  string isbn;
  long copies; 
  Book* next;
};
#endif /* BOOK_H */
