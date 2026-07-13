#include "ShahNim.h"

vector<int> divisors(int n){

    vector<int> divisor;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            divisor.push_back(i);
        }

    }

    return divisor;
}


//return true if p_position, false if n_position
bool N_Pposition(int n, vector<int> n_position, vector<int> p_position){


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