#include <iostream>

using namespace std;
int gi;
/* Взято с  http://www.newty.de/fpt/fpt.html*/  
class TMyClass {
  public:
    int DoIt(float a, char b, char c);
    int DoMore(float a, char b, char c) const;
    // more code
};

int (*pt2Function)(float, char, char) = NULL; 
int (TMyClass::*pt2Member)(float, char,  char) = NULL;
int (TMyClass::*pt2ConstMember)(float,  char, char) const = NULL;

int TMyClass::DoIt(float a, char b, char c){
    cout<<"DoIt\n";
    int result;
    TMyClass instance1;
    result = (instance1.*pt2Member)(12, 'a',  'b');
    result = (*this.*pt2Member)(12, 'a', 'b');
    
    TMyClass* instance2 = new TMyClass;  
    result = (instance2->*pt2Member)(12, 'a', 'b');
    delete instance2;
    return 0;
}

int TMyClass::DoMore(float a, char b, char c) const{cout<<"DoMore\n"; return 0;}
    
int main() {
    pt2ConstMember = &TMyClass::DoMore;  
    pt2Member = &TMyClass::DoIt;
    TMyClass instance1;
    (instance1.*pt2ConstMember)(12, 'a',  'b');
    
    cout<<(long) ((void*)(&instance1))<<"\n";
    cout<<(long) ((void*)(pt2ConstMember))<<"\n";
    cout<<(long) ((void*)(pt2Member))<<"\n";
//    cout<<(int)pt2Member;
}
