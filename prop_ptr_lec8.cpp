#include <iostream>

using namespace std;


struct Mine{
    int getProduct() const{return 0;};
    int getInterval() const{return 0;};
    
    int interval;
};

void swapMines(Mine &m1, Mine &m2) {
}
 
void sortMines(int Mine::*field, Mine *arr, int len) {
    for( int i=0; i<len-1; i++ )
        for( int j=i+1; j<len; j++ )
            if( arr[i].*field> arr[j].*field )
                swapMines(arr[i], arr[j]);
}

int main() {
    int Mine::*field;
    Mine m1;
    field=NULL;
    cout<<(long) ((void*)(&(m1.*field)))<<"\n";
    
    
    m1.*field=0xffff;
    cout<<m1.*field<<"\n";
    cout<<m1.interval<<"\n";
    
    field=&Mine::interval;
    m1.*field=10;
    cout<<(long) ((void*)(&(m1.*field)))<<"\n";
    
//    cout<<(long) ((void*)((field)))<<"\n"; //error
}
