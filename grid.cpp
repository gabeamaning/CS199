#include "grid.hpp"
#include <iostream>

using namespace std;

class Grid {

  // The default constructor
  Grid::Grid();

  // Creates a square grid with the side of the square being equal to the parameter
  Grid::Grid(int ndimension) {
    this->dimension = ndimension;
    arr = new int*[ndimension];
    
    for(int i =0; i < dimension; i++){
    arr[i]= new int [dimension];
    }
  }

  // Copy Constructor
  Grid::Grid(const Grid & obj){
    this->dimension = obj.dimension;
    arr = new int*[dimension];
    
    for(int i=0; i < dimension; i++){
      arr[i] = new int[dimension];
    }
    
    for(int i=0; i < dimension; i++){
      int * x = arr[i];
      int * y = obj.arr[i];
    }
    
    for(int j=0; j < dimension; j++) {
      x[j] = y[j];
    }
  }

  // Destructor
  Grid::~Grid() {
    for(int i=0; i < dimension; i++){
      delete [] arr[i];
    }
    
    delete [] arr;
  }

  // Overloaded assigment operator. In this method you have to overload the assigment operator for the grid class such that when I do something like Grid a = Grid b, it should make "a" = "b"
  const Grid & Grid::operator=(const Grid & obj){
    if (this != &obj) {
    clear();
    this->dimension = obj.dimension;
    arr = new int*[dimension];
    
    for (int i=0; i < dimension; i++) {
      arr[i] = new int[dimension];
      
    for(int i=0; i<dimension; i++) {
      int*x = arr[i];
      int*y = obj.arr[i];
      
      for(int j = 0; j < dimension; j++) {
        x[j] = y[j];
        }
      }
    }
    return *this;
  }
  
  void Grid::clear(){
  for(int i = 0; i < dimension; i++) {
      delete [] arr[i];
    }
    delete [] arr;
    }

  // This function will take two integers and swap the values in the rows of the Grid object
  void Grid::swapRows(int row1, int row2) {
  
  int*a = new int[this->dimension];
  int*b = new int[this->dimension];
  
  for(int i =0; i < this->dimension; i++) {
    int*y = this->arr[row1];
    int*x = this->arr[row2];
    a[i] = y[i];
    b[i] = x[i];
    }
    
    for(int i =0; i < this->dimension; i++) {
    int*y = this->arr[row1];
    int*x = this->arr[row2];
    y[i] = b[i];
    x[i] = a[i];
    }
    
   }
  const Grid operator+(const Grid &obj2) {
    if(this->dimension > obj2.dimension) {
    
    Grid newGrid(this->dimension);
    
    for(int i =0; i < obj2.dimension; i++) {
    int*x;
    int*y;
    int*x;
    x = this->arr[i];
    y = obj2.arr[i];
    z = newGrid.arr[i];
      for(int j=0; j <obj2.dimension; j++){
        z[j] = x[j]+y[j];
        }
      }
      
      for(int i=obj2.dimension; i< this->dimension; i++) {
      int*x;
      int*y;
      x = this->arr[i];
      y = newGrid.arr[i];
        for(int j = obj2.dimension; j < this->dimension; j++) {
        y[j] = x[j];
        }
      }
      return newGrid;
     }
  else if(this->dimension < obj2.dimension) {
    Grid newGrid(obj2.dimension);
    
    for(int i=obj2.dimension; i< this->dimension; i++) {
      int*x;
      int*y;
      int*z;
      x = this->arr[i];
      y = obj2.arr[i];
      z = newGrid.arr[i];
        for(int j = 0; j < this->dimension; j++) {
        z[j] = y[j] = x[j];
        }
      }
      
      for(int i=obj2.dimension; i< this->dimension; i++) {
      int*x;
      int*y;
      x = obj2.arr[i];
      y = newGrid.arr[i];
        for(int j = this->dimension; j < obj2.dimension; j++) {
        y[j] = x[j];
        }
      }
      return newGrid;
     }
     else {
      Grid newGrid(this->dimension);
      
      for(int i=obj2.dimension; i< this->dimension; i++) {
      int*x;
      int*y;
      int*z;
      x = this->arr[i];
      y = obj2.arr[i];
      z = newGrid.arr[i];
        for(int j = 0; j < this->dimension; j++) {
        z[j] = y[j] = x[j];
        }
      }
      return newGrid;
      }
     }

  // The function will take two integers and swap the values in the columns of the Grid object.
  void swapColumns(int col1, int col2) {
  
    int* a = new int[this->dimension];
    int* b = new int[this->dimension];
    
    for(int i = 0; i <this->dimension; i++){
      int*x = this->arr[i];
      int*y = this->arr[i];
      a[i] = x[column1];
      b[i] = y[column2];
      
      }
      
      for(int i = 0; i <this->dimension; i++){
      int*x = this->arr[i];
      int*y = this->arr[i];
      x[column1] = b[column2];
      y[column2] = a[column1];
      }
      }

  // This function takes in a Grid object by reference and creates a new Grid object with the values in the grid being set to the product of the indices of the cell and the value in the Grid object. Example - if the 2-D grid had the value at 5 at index (2,5). The value of the cell at (2,5) in the new grid would be 2*5*5
  Grid Grid::multCoords(Grid & obj){
    Grid newGrid(obj);
    for(int i = 0; i <this->dimension; i++) {
      int*x= newGrid.arr[i];
        for(int j=0; j<this->dimension; j++) {
        x[j]=x[j] * i*j;
        }
        }
        return newGrid;
  }

  // Responsible for printing the grid
  void Grid::printGrid(){
    for(int i=0; i <this->dimension; i++){
      int*x = this->arr[i];
        for(int j =0; j < this->dimension; j++) {
        count << x[j] << "";
        }
        count <<""<<end1;
        }
  
  }



 private:
     
  int ** arr; // A double pointer for creating the grid
  int dimension; // The dimension of the grid


};
