# ShahNim
C++ program to categorize the first n (user chosen, the given code stops at 100 but that is easily changed through the variable MAX in main) numbers into n-position or p-position. P-position is a game position where the previous player has a win with optimal play, implies all available moves are N-positions. N-position is a game position where the next player has a win with optimal play, implies at least 1 p-position move. 

Program uses the factors and n-1 to decide if n is n-position or p-position. This follows rules of play. Players can take 1 stone, or leave a divisor of stones greater than one. One stone left is considered end of game. Player left with 1 stone loses. 

