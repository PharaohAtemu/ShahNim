# ShahNim
C++ programs to aid in research paper on the characteristics of Shah Nim. Shah Nim is a class of Nim games where the players options consist of 1) Taking one stone, or 2) Leaving a proper divisor of the original pile greater than one and less than itself. For purpose of further explaination, a position set is a set Q(n) where all possible next states are elements of Q. For example, 8 has a position set Q = {2,4,7}.

ShahNim_1pile.cpp uses n-1 and the factors of n to decide if n is a N-position (next player wins) or P-position (previous player wins). User can specify normal play (first player left with one stone loses) or misere (first player left with one stone wins), and number of stones. Assumes user will input correct variable type. Possible fix in later renditions.

Program ShahNim_Grundy.cpp uses the P-position numbers to build a vector of n Grundy numbers. The Grundy number for any game n depends on the mex (minimum excluded value) of the Grundy numbers in its position set. User can specify number of piles, and stones in each pile. User can search for a grundy value within the max of all the piles. Program tells user who will win and max grundy value. Code is not opitmized and assumed correct variable input. Possible fix in later renditions. Important to note that grundy numbers will not work with multiple pile misere, so future renditions cannot include that. 

Program divisor_position.cpp houses the function to return all divisors of a number and the function to calculate if a number is a N- or P- position. 

## How to Use
* (Following instructions assumes user has already configured their software to compile and run c++ code. I use [VSCode](https://code.visualstudio.com/download?_exp_download=fb315fc982) with [MSYS2](https://www.msys2.org/))
* Download ShahNim_1pile.cpp, divisor_position.cpp, ShahNim.h, & ShahNim_Grundy.cpp
* compile "g++ ShahNim_1pile.cpp divisor_position.cpp -o [outputname]" (for n_position, p_position)
* compile "g++ ShahNim_Grundy.cpp divisor_position.cpp -o [outputname]" (for grundy numbers)
* .\[outputname]
