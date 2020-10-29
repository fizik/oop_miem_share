#include <iostream>

using namespace std;

enum SortModes {smProd, smIntr, smWork};

struct Mine{
    int getProduct() const{return 0;};
    int getInterval() const{return 0;};
    
    int interval;
    int produced;
};

void swapMines(Mine &m1, Mine &m2) {
}
 
void sortMines(int Mine::*field, Mine *arr, int len) {
    for( int i=0; i<len-1; i++ )
        for( int j=i+1; j<len; j++ )
            if( arr[i].*field> arr[j].*field )
                swapMines(arr[i], arr[j]);
}


void sortMinesBy(Mine *mns, int mCount, SortModes sortBy) {
    if( sortBy==smProd )
        sortMines( &Mine::produced, mns, mCount);  
    else if( sortBy==smIntr )
        sortMines( &Mine::interval, mns, mCount);
    // and so on
}

int tFunction(float, char){
    return 5;
}


int main() {
    int Mine::*field;
    Mine m1;
    field=NULL;
    cout<<((void*)(&(m1.*field)))<<"\n";
    
    
    m1.*field=0xffff;
    cout<<m1.*field<<"\n";
    cout<<m1.interval<<"\n";
    
    field=&Mine::interval;
    m1.*field=10;
    cout<<((void*)(&(m1.*field)))<<"\n";
    
    cout<< ((void*)((&field)))<<"\n"; //
//  cout<< ((void*)((field)))<<"\n"; //error
    cout<<sizeof(field)<<"\n"; //

    int *pi=&m1.interval;
    cout<<pi<<"\n"; //
    
    
    int (*pt2Function)(float, char);
    pt2Function=tFunction;
    
    
    cout<< ((void*)((pt2Function)))<<"\n"; //

    int (Mine::*pt2Member)() const = NULL;
    
    cout<< ((void*)((pt2Member)))<<"\n"; //
    pt2Member = &Mine::getProduct; 
    cout<< ((void*)((pt2Member)))<<"\n"; //
}
