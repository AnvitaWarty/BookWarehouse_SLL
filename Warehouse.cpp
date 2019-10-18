#include "Warehouse.h" 

Warehouse::Warehouse(){
  this->head = nullptr; 
  this->bookCount = 0;   
}

Warehouse::~Warehouse(){
  if(bookCount==0) 
    head = nullptr; 
  else{
    Book* temp; 
	while(head!=nullptr){
	  temp = head;  
	  head = head->getNext(); 
	  delete temp;
    }	
  }
}

istream& operator >> (istream& is, Warehouse& warehouse){
  int i = 0; 
  string title; 
  
  //create head and set to first book
  warehouse.head = new Book(); 
  Book* temp = warehouse.head; 
  Book* prev; 
  
  while(!is.eof()){
    is >> *temp;
    title = (*temp).getTitle(); 

    if(title.empty()){	
      continue; 
    }  
	
    temp->setNext(new Book());
    prev = temp; 
    temp = temp->getNext(); 
    i++; 
  }
  
  prev->setNext(nullptr); 
  delete temp;
  warehouse.bookCount = i;
  warehouse.sort_();
  return is; 
}

ostream& operator << (ostream& os, const Warehouse& warehouse){
  int index = 0;
  Book* temp = warehouse.head; 
  while(index < warehouse.bookCount){
	os << *temp;
	temp = temp->getNext();
    index++; 	
  }
  
  return os; 
}

Book* Warehouse::find(string isbn) const{
  int index = 0; 
  Book* temp = this->head; 
  
  while(index < this->bookCount && (*temp).getIsbn()!=isbn){
    temp = temp->getNext(); 
	index++;
  }
  
  if(index >= this->bookCount)
	return nullptr; 

  return temp; 
}	

void Warehouse::list() const{
  cout << *this; 
}

void Warehouse::sort_ () {
  bool flag = true;
  while (flag) {
    flag = false;
    Book* temp = head;
	Book* prev = temp; 
	Book* next; 
	

    while (prev->getNext()!=nullptr && temp->getNext() != nullptr){
      if(temp == head && (*temp).getIsbn() > (*temp->getNext()).getIsbn()){ 
		 Book* focus = temp->getNext(); 
		 temp->setNext(focus->getNext()); 
		 focus->setNext(temp); 
		 head = focus; 
		 temp = prev = head;  
		 continue;
	  }
      if ((*temp).getIsbn() > (*temp->getNext()).getIsbn()){
        next = temp->getNext()->getNext(); 
		temp->getNext()->setNext(temp);
		prev->setNext(temp->getNext()); 
		temp->setNext(next);	
        flag = true;
      }
	  
	  prev = temp;
      temp = temp->getNext();

    } 
  }
  
}
