//Author: PharaohAtemu (github username)
/*
Purpose: To analyze the first n p and n-positions for the game Shah-Nim. 
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector> 
#include <algorithm>

using namespace std;


//global vectors
vector <int>p_position = {3};
vector <int>n_position = {2};

//functions
bool N_Ppostion(int n); //checking if number is p or n
vector<int> divisors(int n); //get the divisors of n

vector<int> divisors(int n){

    vector<int> divisors;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
        }

    }

    return divisors;
}


//return true if p_position, false if n_position
bool N_Pposition(int n){

    //if the n-1 option is a p_position, then n is a n_position
    auto it = find(p_position.begin(), p_position.end(), (n-1));
    if(it != p_position.end()){
        return false;
    }

    //all divisors need to be in n_position
    for(auto i: divisors(n)){
        auto it = find(p_position.begin(), p_position.end(), i);

        if(it != p_position.end())
        {
            return false;
        }
    }

    return true;
}


int main(){

    int MAX = 100; //change this to explore higher numbers

    for(int i = 4; i <= MAX; i++)
    {
        if(N_Pposition(i) == true){
            p_position.push_back(i);
        }else{
            n_position.push_back(i);
        }
    }

    //print vectors
    cout<< "p_position numbers: ";
    for(auto i : p_position){
        cout<< i <<" ";
    }
    
    cout<< "\nn_position numbers: ";
    for(auto i: n_position){
        cout<< i << " ";
    }

    return 0;
}
