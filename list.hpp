#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED
#include <iostream>
#include <string>
#include "list.hpp"
#include "listexception.hpp"

template<class T,int ARRAYSIZE = 100000>
class List{
private:
    T data[ARRAYSIZE];
    int last;

    bool isValidPos(const T&) const;
    void copyAll(const List< T,ARRAYSIZE >&);

public:

    List();
    List(const List< T,ARRAYSIZE >&);
    bool isEmpty();
    bool isFull();

    void insertData(const T&, const T&); // se les pasa la posicion y un elemento
    void deleteData(const T&);

    void bubbleSortData();
    void insertSortData();
    void swapData(const T&,const T&);

    int getFirstPos();
    int getLastPos();
    int getPrevPos(const T&);
    int getNextPos(const T&);

    int retrieve(const T&);

    std::string toString();

    void print();
    void deleteAll();

    List& operator = (const List< T,ARRAYSIZE >&);



};

template<class T, int ARRAYSIZE>
bool List< T,ARRAYSIZE >::isValidPos(const T&p) const
{
    //F A L T A _ A C O M O D A R
}
template<class T, int ARRAYSIZE>
void List< T,ARRAYSIZE >::copyAll(const List<T, ARRAYSIZE>&)
{

}
template<class T, int ARRAYSIZE>
List< T,ARRAYSIZE >::List()
{
    last = -1;
}
template<class T, int ARRAYSIZE>
List< T,ARRAYSIZE >::List(const List<T, ARRAYSIZE>&)
{

}
template<class T, int ARRAYSIZE>
bool List< T,ARRAYSIZE >::isEmpty()
{
    return last == ARRAYSIZE-1;
}
template<class T, int ARRAYSIZE>
bool List< T,ARRAYSIZE >::isFull()
{

}
template<class T, int ARRAYSIZE>
void List< T,ARRAYSIZE >::insertData(const T&p, const T&e)
{
    if( !isValidPos(p) or p!= -1 or isFull()){
        throw ListException("Invalid Position, InsertData");
    }
    int i(last);
    while(i>p){
        data[i]=data[i];
        i--;
    }
    data[p+1]=e;
    last ++;
}
template<class T, int ARRAYSIZE>
void List< T,ARRAYSIZE >::deleteData(const T&p)
{
    if(!isValidPos(p)){
        throw ListException("Invalid Position, DeleteData");
    }
    int i(p);
    while(i<last){
        data[i]= data[i+1];
        i++;
    }
    last --;
}

template<class T, int ARRAYSIZE>
int List< T,ARRAYSIZE >::getFirstPos()
{
    if(isEmpty()){
        return -1;
    }

}
template<class T, int ARRAYSIZE>
int List< T,ARRAYSIZE >::getLastPos()
{
    return last;
}
template<class T, int ARRAYSIZE>
int List< T,ARRAYSIZE >::getPrevPos(const T&p)
{
    if(!isValidPos(p) or p== 0){
        return -1;
    }
    return p-1;
}
template<class T, int ARRAYSIZE>
int List< T,ARRAYSIZE >::getNextPos(const T&)
{

}
template<class T, int ARRAYSIZE>
int List< T,ARRAYSIZE >::retrieve(const T& p)
{
    if(!isValidPos(p)){
        throw ListException("Invalid Position, retrieve");
    }
    return data[p];
}
template<class T, int ARRAYSIZE>
std::string List< T,ARRAYSIZE >::toString()
{

}
template<class T, int ARRAYSIZE>
void List< T,ARRAYSIZE >::print()
{
    int i(0);
    while(i<= last){
        std::cout << data[i];
        i++;
    }
}
template<class T, int ARRAYSIZE>
void List< T,ARRAYSIZE >::deleteAll()
{
    last =-1;
}
template<class T, int ARRAYSIZE>
List< T,ARRAYSIZE >& List< T,ARRAYSIZE >::operator=(const List<T, ARRAYSIZE>&)
{

}
template<class T, int ARRAYSIZE>
void List< T,ARRAYSIZE >::swapData(const T&a, const T&b)
{
    T aux(a);
    a=b;
    b=aux;
}

template<class T, int ARRAYSIZE>
void List< T,ARRAYSIZE >::bubbleSortData()
{
    int i(last),j;
    bool flag;
    do{

        flag = false;
        j=0;
        while(j<i){
            if(data[j]>data[j+1]){
                swapData(data[j],data[j+1]);
                flag = true;
            }
            j++;
        }
        i--;
    }while(flag);
}
template<class T, int ARRAYSIZE>
void List< T,ARRAYSIZE >::insertSortData()
{
    int i(1),j;
    T aux;
    while(i<=last){
        aux = data[i];
        j=i;
        while(j>0 and aux < data[j-1]){
            data[j]= data[j-1];
            j--;
        }
        if(i!=j){
            data[j]= aux;
        }
        i++;
    }
}


#endif // LIST_HPP_INCLUDED
