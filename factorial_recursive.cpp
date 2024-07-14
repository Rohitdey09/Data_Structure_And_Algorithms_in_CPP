//Write a recursive function to calculate the factorial of a number and analyze its time and space complexity.

//Time Complexity-
//Space Complexity-O(n)

#include <iostream> 
using namespace std; 
 
int factorial(int n) { 
    if (n <= 1) { 
        return 1; 
    } 
    return n * factorial(n - 1) ; 
} 
 
int main() { 
    int n; 
    cout << "Enter the number : "; 
    cin >> n; 
 
    int result = factorial(n); 
    cout << "The factorial of " << n << " is: " << result << endl; 
 
    return 0; 
 

}
