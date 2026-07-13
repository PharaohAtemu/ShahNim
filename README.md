# ShahNim
C++ program to categorize the first n (user chosen, the given code stops at 100 but that is easily changed through the variable MAX in main) numbers into n-position or p-position. P-position is a game position where the previous player has a win with optimal play, implies all available moves are N-positions. N-position is a game position where the next player has a win with optimal play, implies at least 1 p-position move. 

Program ShahNim_1.cpp uses the factors and n-1 to decide if n is n-position or p-position. This follows rules of play. Players can take 1 stone, or leave a divisor of stones greater than one. One stone left is considered end of game. Player left with 1 stone loses. Program asks for a number of stones to analyse up to.

Program ShahNim_Grundy.cpp uses the p-position numbers to build a vector of Grundy numbers according to the mex of grundy numbers for each number of stones. P-positions are all 0. Program asks for a number of stones to analyse up to.

## How to Use
* (Following instructions assumes user has already configured their software to compile and run c++ code. I use [VSCode](https://code.visualstudio.com/download?_exp_download=fb315fc982) with [MSYS2](https://www.msys2.org/))
* Download ShahNim_1pile.cpp, divisor_position.cpp, ShahNim.h, & ShahNim_Grundy.cpp
* compile "g++ ShahNim_1pile.cpp divisor_position.cpp -o [outputname]" (for n_position, p_position)
* compile "g++ ShahNim_Grundy.cpp divisor_position.cpp -o [outputname]" (for grundy numbers)
* .\[outputname]
