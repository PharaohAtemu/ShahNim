#include <iostream>
#include <stdlib.h>
#include "ShahNim.h"

/*
    Requires ShahNim.h and divisor_position.cpp
*/

vector <vector<int>> grundy = {
    {0,1,3,5,7},
    {2,17,9,15},
    {4,6,10,14},
    {8,12,18,20},
    {24,28,32,36}
};

vector<int> n_position = {2};
vector<int> p_position = {1,3};

void findMex(int n){

    vector<int> set = divisors(n);
    vector<int> grundySet;

    //add the n-1 position
    set.push_back(n-1);


    if(N_Pposition(n, n_position, p_position) == true){
        grundy[0].push_back(n);
        p_position.push_back(n);
        return;
    }

    n_position.push_back(n);
   
    //populate this number's grundy set
    for (int move : set) {
        for (size_t i = 0; i < grundy.size(); i++) {
            auto it = find(grundy[i].begin(), grundy[i].end(), move);
            if (it != grundy[i].end()) {
                grundySet.push_back(static_cast<int>(i));
                break;
            }
        }
    }
    
    //sort grundyset
    sort(grundySet.begin(), grundySet.end());

    int mex = 1; //no p posiitons, so mex starts at 1

    for (int i = 0; i < grundySet.size(); i++){
        if(grundySet[i] == mex){ 
            mex++;
        }
    }

    if (mex >= static_cast<int>(grundy.size())) {
        grundy.resize(mex + 1);
    }
    grundy[mex].push_back(n);

    return;
}


int main(){

    int MAX = 0;
    int exit = 1;
    int search = 0;
    vector<int> game;



    cout<<"Enter number of stones: ";
    cin>> MAX;

    //calculate the grundy numbers we need
    for(int i = 4; i <= MAX; i++){
        findMex(i);
    }

    for (const auto& row : grundy)
    {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }
    
    return 0;
}