#include <fstream>
#include "Book.h"
#include "Warehouse.h" 

using namespace std; 
bool checkFile(ifstream&); 

int main(int argc, char** argv){
  string filename, command, isbn; 
  
  //check if there are at least three arguments
  if(argc < 3){
    cout<<"Usage 1: " << argv[0] << " <input file> find <isbn>"<<endl; 
    cout<<"Usage 2: "<< argv[0] <<" <input file> list"<<endl; 	  
    return -1; 
  }
  
  //open file and check validity of file
  filename = argv[1]; 
  ifstream bookFile(filename); 
  if(!checkFile(bookFile)){
    cout<<"File either does not exist or is empty."<<endl; 
	return -1;
  }	

  Warehouse warehouse;
  bookFile >> warehouse;
  command=argv[2];   
  if(command=="find"){
	if(argc < 4){
	  cout<<"Usage 1: "<< argv[0] <<" <input file> find <isbn>"<<endl; 
	  return -1; 
    } 
    else{
	  isbn = argv[3]; 
	  Book* found = warehouse.find(isbn); 
	  
	  if(found!=nullptr){
        cout<<"ISBN: "<< isbn << " -- FOUND"<<endl;
		cout<<(*found); 
	  } 
	  else{
        cout<<"ISBN: "<< isbn << " -- NOT FOUND"<<endl;
		return -1; 
	  }
    }		
  } 
  else if(command=="list"){
    warehouse.list();
  }
  else{
    cout<<"Unrecognized command: " << command <<endl; 
	return -1; 
  }	  
   
  //close file 
  bookFile.close();  
  return 0; 	
}

bool checkFile(ifstream& file){
  if(file.fail() || file.peek()==ifstream::traits_type::eof()) 
    return false; 
  return true; 
}
