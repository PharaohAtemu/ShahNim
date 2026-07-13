
#include <iostream>
#include "ShahNim.h"


int main(){

    int MAX = 0;
    cout<<"Enter number of stones: ";
    cin>> MAX;

    vector<int> n_position = {2};
    vector<int> p_position = {1,3};

    for(int i = 4; i <= MAX; i++)
    {
        if(N_Pposition(i, n_position, p_position) == true){
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
