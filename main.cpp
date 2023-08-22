#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>
#include <functional>
#include "list.hpp"
using namespace std;


int main(){
    List <int,100000> myList;
    default_random_engine generator (chrono::system_clock::now().time_since_epoch().count());
                uniform_int_distribution<int> distribution(0,1000000);
                auto dice = bind(distribution,generator);


                int datos;

                int i(0);

                while(i<100){

                 datos = dice();

               myList.insertData(myList.getFirstPos(),datos);

                    i++;

                }

            cout << " Imprimiendo datos " << endl;
            myList.print();
    cout << " Hola ya estpy jalando chido " << endl;
}


