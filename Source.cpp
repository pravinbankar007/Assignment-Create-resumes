#include <iostream>
#include<vector>
#include "Student.h"
#include "storedVector.h"

using namespace std;
using namespace libxl;


int main()
{
  //storing students data in vector which is read from excel file
    storedVector V1;
    vector<Student> V = V1.storedStudentData();

    //Displaying students data
    V1.DisplayStudentData(V);

    //Writing this data into individual student resume files
    V1.WriteStudentData(V);
         

}

