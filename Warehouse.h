// @file Warehouse.h
#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include <iostream>
#include <string>
#include "Book.h"

using namespace std;
class Warehouse {
 /**
 * @param is the input stream
 * @param warehouse the warehouse object reference
 * @return the input stream
 */
 friend istream& operator >> (istream& is, Warehouse& warehouse);

 /**
 * @param os the output stream
 * @param warehouse the warehouse object reference
 * @return the output stream
 */
 friend ostream& operator << (ostream& os, const Warehouse& warehouse);
 
 public:
 
  Warehouse();
  
  ~Warehouse(); 
  
  /**
  * @param isbn the ISBN number to search for
  * @return pointer to the Book object, if found. Otherwise, return NULL
  */
  Book* find (string isbn) const;
  
  /**
  * Prints the inventory of the Warehouse (i.e. list all the books)
  */
  void list () const;
    
  private: /* extra credit */
  void sort_();
  
  private:
  Book* head;
  int bookCount;
};
#endif /* WAREHOUSE_H */

