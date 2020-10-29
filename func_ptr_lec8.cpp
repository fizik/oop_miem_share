#include <iostream>
using namespace std;

enum cSortBy {sortByProd, sortByInterval};

int f1(float a, char b) {
    cout<<a<<"; "<<b<<"\n";
    return 1;
}

int f2(float a, char b) {
    cout<<b<<"; "<<a<<"\n";
    return 2;
}

struct Mine{
    int getProduct() const{return 0;};
    int getInterval() const{return 0;};
};

void swapMines(Mine &m1, Mine &m2) {
}
    
int cmpMines1(const Mine &m1, const Mine &m2) {
    return(m1.getProduct() - m2.getProduct());
}

int cmpMines2(const Mine &m1, const Mine &m2) {
    return(m1.getInterval() - m2.getInterval());
}

void sortMines(Mine *mines, 
               int count, 
               int  (*cmpFunc) (const Mine &m1, const Mine &m2)
              )
{
    for( int i=0; i<count; i++ )
        for( int j=i+1; j<count; j++ )
            if(cmpFunc(mines[i],mines[j])<0)
                swapMines(mines[i], mines[j]);
}


void sortMinesBy(Mine *mns, int mCount, cSortBy sortBy) {
    if( sortBy==sortByProd )
        sortMines( mns, mCount, cmpMines1);  
    else if( sortBy==sortByInterval )
        sortMines( mns, mCount, cmpMines2);
    // and so on
}


int main() {
    int (*pt2Function)(float, char);
    pt2Function=f1;
    pt2Function(1.1, 'd');
}
