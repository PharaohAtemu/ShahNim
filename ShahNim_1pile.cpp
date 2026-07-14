
#include <iostream>
#include "ShahNim.h"


int main(){

    int MAX = 0;
    int normal = 0;
    vector<int> n_position;
    vector<int> p_position;

    while(normal != 1 && normal != 2){
        cout<<"Choose 1 for normal play, 2 for misere: ";
        cin>> normal;
    }

    cout<<"Enter number of stones: ";
    cin>> MAX;

    if(normal == 1){
        n_position.push_back(2);
        p_position.push_back(3);
    }else{
        n_position.push_back(3);
        p_position.push_back(2);
    }

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
