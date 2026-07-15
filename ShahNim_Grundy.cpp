
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
int multiple(vector<int> piles);

int mulitple(vector<int> piles){
    int result = 0;

    for(int i = 0; i < piles.size(); i++){
        result ^= piles[i];
    }

    return result;
}

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

    for (int i = 0; i < grundySet.size(); i++){
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
    int piles = 0;
    int exit = 1;
    int search = 0;
    vector<int> game;

    cout<<"Enter number of piles: ";
    cin>> piles; 

    game.resize(piles);

    for(int i = 0; i < piles; i++){
        cout<<"Enter number of stones in pile "<< i+1<<": ";
        cin>> game[i];

        //update the max number
        if(game[i] > MAX){
            MAX = game[i];
        }
    }
    

    //calculate the grundy numbers we need
    for(int i = 4; i <= MAX; i++){
        findMex(i);
    }


    if(piles > 1){
        if(mulitple(game) != 0)
        {
            cout<< "First player wins this game.\n";
        }else{
            cout<< "Second player wins this game.\n";
        }
    }

    cout<< "Highest Grundy number is: "<<MAX_GRUNDY<<"\n";

    do{
        do{
            cout<<"Which Grundy value up to "<< MAX<<" do you want to know?: ";
            cin>>search;
        }while(search > MAX);

        if(search == -1){
            for(int i = 1; i < grundy.size(); i++ ){
                cout<<grundy[i-1]<<" ";
                if(i%5 == 0){
                    cout<<"\n";
                }
            }
            cout<<"\n";
        }else{
            cout<<grundy[search]<<"\n";
        }

        cout<<"Do you wish to exit? 1 for no, 2 for yes: ";
        cin>> exit;
    }while(exit == 1);

    return 0;
}