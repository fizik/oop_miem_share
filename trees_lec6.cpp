#include <iostream>
#include <cstring>
using namespace std;

class EquipmentTree {
  public:
    EquipmentTree(const char *_infoString, const char *_childString);
    // Здесь д.б. 4 конструктора и деструктор
    int getChildCount() const;
    void AddChild(EquipmentTree *et);
    void delChild(int);
    EquipmentTree &getChild(int);
    // Возвращает потомка по его имени.
    EquipmentTree &getChild(const char *);

    void setInfoString(const char*);  
    char *getInfoString();
    void setChildString(const char*);  
    char *getChildString();
    // Возвращает оборудование – массив строк.
    // cnt возвращает размер списка.
    char **getEquipmentList(int &cnt);
    // Возвращает оборудование в заданной единице
    // аналогично предыдущей функции.
    char **getEquipmentList(char **, int&);
    // Выводит оборудование с текущего узла
    void getEquipmentList();
  private:
    void mergeLists(char **&res, int &cnt, char **tmp, int c);
    EquipmentTree **childs;  
    int childCount;
    char *infoString;
    char *childString;
};

EquipmentTree::EquipmentTree(const char *_infoString, const char *_childString) {
    infoString=new char[strlen(_infoString) + 1];
    strcpy(infoString, _infoString);
    childString=new char[strlen(_childString) + 1];
    strcpy(childString, _childString);
    childCount=0;
    childs=NULL;
}

void EquipmentTree::AddChild(EquipmentTree *et){
    EquipmentTree **newchilds=new EquipmentTree*[childCount+1];
    auto i=0;
    for(; i<childCount; i++)
        newchilds[i]=childs[i];
    newchilds[i]=et;
    childCount++;
    delete [] childs;
    childs=newchilds;
}

char **EquipmentTree::getEquipmentList(int &cnt) {
    char **res;
    if( !childCount ) {
        res=new char*[1];
        res[0] = new char[strlen(infoString) + 1]; 
        strcpy(res[0], infoString);
        cnt=1;
    } else {
        char **tmp;  
        int c;  
        res=NULL;  
        cnt=0;
        for( auto i=0; i<childCount; i++ ) {
            tmp=childs[i]->getEquipmentList(c);
            mergeLists(res, cnt, tmp, c);
        }
    }
    return res;
}

void EquipmentTree::mergeLists(char **&res, int &cnt, char **tmp, int c) {
    char **nres=new char*[cnt+c];
    for(auto i=0; i<cnt; i++)
        nres[i]=res[i];
    for(auto i=0; i<c; i++)
        nres[i+cnt]=tmp[i];
    delete [] res;
    res=nres;
    cnt+=c;
}

void EquipmentTree::getEquipmentList() {
    cout<<infoString;
    for(auto i=0; i<childCount; i++) {
        cout<<";"<<childString<<" ";
        childs[i]->getEquipmentList();
    }
}


int main() {
    EquipmentTree e01("Таллинская 34, учебн.", "Этаж"),
        e11("Первый", "Комната"),
        e21("101", ""),
        e31("Принтер 56", ""),
        e32("Ноутбук 57", "");
        
    e01.AddChild(&e11);
    e11.AddChild(&e21);
    e21.AddChild(&e31);
    e21.AddChild(&e32);
    
    e01.getEquipmentList();
    cout<<"\n\n";
    
    int cnt=0;
    char **listEquipment=e01.getEquipmentList(cnt);
     for(auto i=0; i<cnt; i++)
         cout<<listEquipment[i]<<"\n";

}
