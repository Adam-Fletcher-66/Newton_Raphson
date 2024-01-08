/* Name: Adam_Fletcher
   Date: 5/2/2022
   Purpose: To find the roots of a non-linear equation using Newton-Raphson
            iteration. For the function 3cos(5x)+2x=0 there are 5 roots:

    #      Root         Initial guess     Epsilom       No. of iterations
    1      -1.34758          -2.0       0.0000000001          43
    2      -1.10887          -1.0       0.0000000001           5
    3      -0.277011         -0.5       0.0000000001           6 
    4       0.363052          0.5       0.0000000001           5
    5       0.825867          1.0       0.0000000001           4

*/

#include <iostream>
#include <cmath>
#include <limits>

int main() {

                // Variable Dictionary  
  double xold;               // Old root estimate
  double xnew;               // New root estimate
  double y_old;              // Value of function at xold
  double dy_old;             // Value of derivative function at xold 
  double eps;                // Convergence criteria
  bool converge;             // Logical operator if true = convergence
  int n_iter{1};             // Number of iterations of loop
  const int MAX_N = 300;     // Initialize max no. of iterations in loop
  
 
                             // Prompt user for intial x guess and epsilom
  std::cout << "Enter initial guess for root 'x' and epsilom" << std :: endl;
  std::cin >> xold >> eps;
  

  while (n_iter < MAX_N) {   // Initialize iteration loop
    y_old = 3.0 * cos(5.0 * xold) + 2.0 * xold;   // Calc function 
    dy_old = -15.0 * sin(5.0 * xold) + 2.0;       // Calc der. function

    if (fabs(dy_old) < 1.0) {   // Begin if construct to check overflow
      
       if (fabs(dy_old) > fabs(dy_old) * std::numeric_limits<double>::max()) {
    	std :: cout << "dy_old is about 0.0 and method overflows." << y_old
		    << dy_old;
    	return 2;

      }

      }

    xnew = xold - y_old/dy_old;   // Calc value of xnew variable

    if (xold != 0.0) {          // Begin if  construct to determine status 
                                // of converge logical variable
      converge = fabs(xnew - xold) < eps * fabs(xold);
      
    }
  
    else {

      converge = fabs(xnew - xold) < eps;
      
	}

  if (converge) {
                                // Write out value of root 
    std :: cout << "The root is: " << xnew;

    return 0;                   // End program with a 0 error code
      
  }

  xold = xnew;                   // Declare value of the intial guess
  n_iter = n_iter + 1;           // to be new estimate and count the
                                 // number of iterations
  std :: cout << "number of iterations: " << n_iter << std :: endl;
    }

  std :: cout << "Method failed, too many iterations." << std :: endl;

  return 1;                      // End program with an error code
                                 // 1 to show error in computing

}

