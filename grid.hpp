#include <iostream>

class Grid {

  // The default constructor
  Grid();

  // Creates a square grid with the side of the square being equal to the parameter
  Grid(int dimension);

  // Copy Constructor
  Grid(const Grid & obj);

  // Destructor
  ~Grid();

  // Overloaded assigment operator. In this method you have to overload the assigment operator for the grid class such that when I do something like Grid a = Grid b, it should make "a" = "b"
  const Grid & operator=(const Grid & obj);

  // This function will take two integers and swap the values in the rows of the Grid object
  void swapRows(int row1, int row2);

  /** This function takes in a grid object and adds the values in the cells of the two grids. Remember this operator will translate to:
  *
  *  Grid a;
  *  Grid b;
  *  a+b -> a.operator+(b)
  *  Store the result in a new grid object and return that object by value
  */
  const Grid operator+(const Grid &obj2);


  // The fuction will take two integers and swap the values in the columns of the Grid object.
  void swapColumns(int col1, int col2);

  // This function takes in a Grid object by reference and creates a new Grid object with the values in the grid being set to the product of the indices of the cell and the value in the Grid object. Example - if the 2-D grid had the value at 5 at index (2,5). The value of the cell at (2,5) in the new grid would be 2*5*5
  Grid multCoords(Grid & obj);

  // Responsible for printing the grid
  void printGrid();



 private:
     
  int ** arr; // A double pointer for creating the grid
  int dimension; // The dimension of the grid


};
