#include <iostream>
#include "time.h"
using namespace std;





/*


is_valid() * Must check if the time is valid or not. 
interval between 0, 23 & 0,59 & 0,59 
 */

bool is_Valid(Time const& t){
 
  if ((t.SS > 59 || t.SS < 0))   {
    return false;
  }

  if ((t.MM > 59 || t.MM < 0))   {
    return false;
  } 

  if ((t.HH > 23 || t.HH < 0 ))   {
    return false;
  }

  return true;
  
   
   
}
