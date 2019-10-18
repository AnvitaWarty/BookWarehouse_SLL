#include "Book.h" 
#include <iomanip> 

Book::Book(){
  this->title = ""; 
  this->authorCount = Book::MAX_AUTHORS; 
  for(int i = 0; i < authorCount; i++)
    this->authors[i] = ""; 
  this->publisher = ""; 
  this->yearPublish = 0; 
  this->hardcover = 0; 
  this->price = 0.0; 
  this->isbn = ""; 
  this->copies = 0; 
}
 
Book::Book(string title, string authors[], int authorCount, string publisher, short yearPublish, bool hardcover,float price, string isbn, long copies){
  this->title = title; 
  this->authorCount = authorCount; 
  for(int i=0; i < authorCount; i++) 
    this->authors[i] = authors[i]; 
  this->publisher = publisher; 
  this->yearPublish = yearPublish; 
  this->hardcover = hardcover; 
  this->price = price; 
  this->isbn = isbn; 
  this->copies = copies; 
}
 
istream& operator >> (istream& is, Book& book){
  getline(is, book.title);
  
  is >> book.authorCount; 
  is.ignore(); 
  int indexA = 0; 
  int leftoverA = book.authorCount - Book::MAX_AUTHORS; 
  while(indexA < book.authorCount && indexA < Book::MAX_AUTHORS) 
  {
    getline(is, book.authors[indexA]); 
    indexA++; 	  
  }
  
  if(leftoverA > 0)		  
  {
    string* otherAuthors = new string[leftoverA];		 
    for(int i = 0; i < leftoverA; i++) 
	{
      getline(is, otherAuthors[i]); 
    }		 
	delete[] otherAuthors; 
	otherAuthors = nullptr; 
    book.authorCount = Book::MAX_AUTHORS; 
  }
  
  getline(is, book.publisher);
  is >> book.yearPublish; 
  is.ignore(); 
  
  is >> book.hardcover; 
  is.ignore(); 
  
  is >> book.price; 
  is.ignore(); 
  
  getline(is, book.isbn); 
  
  is >> book.copies; 
  is.ignore();   
  
  return is;	
}

ostream& operator << (ostream& os, const Book& book){
  os << "\e[1mTitle: " << book.title << "\e[0m"<<endl;
  
  for(int i = 0; i < book.authorCount; i++) 
	os << "Author: " << book.authors[i] << endl; 
  
  os << "Publisher: " << book.publisher << endl; 
  os << "Year: " << book.yearPublish << endl;
  
  if(book.hardcover == 0) 
    os << "Cover: Hardcover" << endl; 
  else
    os << "Cover: Paperback" << endl; 

  os << "Price: $" << setprecision(2) << fixed <<  book.price << endl;
  os << "Isbn: " << book.isbn << endl; 
  os << "Copies: " << book.copies << endl; 
  
  os<<endl;
  
  return os; 	
}
//relevent getters and setters 
string Book::getTitle(){
  return this->title; 
}
string Book::getIsbn() const{
  return this->isbn; 
}
Book* Book::getNext() const{
  return this->next; 
}

void Book::setNext(Book* next){
  this->next = next; 
}
