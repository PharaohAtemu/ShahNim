
#include <iostream>
#include <stdlib.h>
#include "ShahNim.h"

/*
    Requires ShahNim.h and divisor_position.cpp
*/

vector<int> grundy = {0,0,1,0};
vector<int> n_position = {2};
vector<int> p_position = {1,3};
int MAX_GRUNDY = 1;

void findMex(int n);

void findMex(int n){

    vector<int> set = divisors(n);
    vector<int> grundySet;

    //add the n-1 position
    set.push_back(n-1);


    if(N_Pposition(n, n_position, p_position) == true){
        grundy.push_back(0);
        p_position.push_back(n);
        return;
    }

    n_position.push_back(n);
   
    //populate this number's grundy set
    for(int i = 0; i < set.size(); i++){
        grundySet.push_back(grundy[set[i]]);
    }
    
    //sort grundyset
    sort(grundySet.begin(), grundySet.end());

    int mex = 1; //no p posiitons, so mex starts at 1

    for (int i = 0; i < set.size(); i++){
        if(grundySet[i] == mex){ 
            mex++;
        }
    }

    if(mex > MAX_GRUNDY){
        MAX_GRUNDY = mex;
    }

    grundy.push_back(mex);
    return;
}

int main(){
    int MAX = 0;

    cout<<"Enter number of stones:";
    cin>> MAX;
    
    
    for(int i = 4; i <= MAX; i++){
        findMex(i);
    }

    for(int i = 0; i<= MAX; i++){
        cout<< i << " mex = "<< grundy[i]<< "\n";
    }

    cout<< "Highest Grundy number is: "<<MAX_GRUNDY;

    return 0;
}