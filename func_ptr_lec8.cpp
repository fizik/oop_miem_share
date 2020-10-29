#include <iostream>
using namespace std;

struct Mine{
    int getProduct() const{return 0;};
    int getInterval() const{return 0;};
};

typedef int (*cmpFuncType) (const  Mine &m1, const Mine &m2);

enum SortModes {smProd, smIntr, smWork};


class MinesCollection {
  public:
    // Some code here  
    void setSortingMode(SortModes mode);  
    void sortMines();
  private: 
    cmpFuncType ptr;
};

int cmpMines1(const Mine &m1, const Mine &m2) {
    return(m1.getProduct() - m2.getProduct());
}

int cmpMines2(const Mine &m1, const Mine &m2) {
    return(m1.getInterval() - m2.getInterval());
}

void MinesCollection::setSortingMode(SortModes mode) { 
    switch( mode ) {
        case smProd: ptr=cmpMines1; return;  
        case smIntr: ptr=cmpMines2; return;
        // А еще добавить по возрастанию или убыванию.
    }
}


int f1(float a, char b) {
    cout<<a<<"; "<<b<<"\n";
    return 1;
}

int f2(float a, char b) {
    cout<<b<<"; "<<a<<"\n";
    return 2;
}

void swapMines(Mine &m1, Mine &m2) {
}
    
void sortMines(Mine *mines, 
               int count, 
               int  (*cmpFunc) (const Mine &m1, const Mine &m2)
              )
{
    for( int i=0; i<count; i++ )
        for( int j=i+1; j<count; j++ )
            if(cmpFunc(mines[i], mines[j])<0)
                swapMines(mines[i], mines[j]);
}

void sortMinesBy(Mine *mns, int mCount, SortModes sortBy) {
    if( sortBy==smProd )
        sortMines( mns, mCount, cmpMines1);  
    else if( sortBy==smIntr )
        sortMines( mns, mCount, cmpMines2);
    // and so on
}


int main() {
    int (*pt2Function)(float, char);
    pt2Function=f1;
    pt2Function(1.1, 'd');
}
