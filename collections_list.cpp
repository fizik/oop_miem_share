#include <iostream>
using namespace std;

// Прототип класса данных
class TheData {
  public:  
    TheData(){};
    ~TheData(){};
    // заменить текущий объект передаваемым
    void replace(TheData &obj){};
    // скопировать в текущий объект передаваемый
    void copy(const TheData &obj){};
    // сдвинуть все объекты на один вперед, начиная с указанного
    void move(int i){};
  private:
    // данные
};

// На списках
class TheCollection {
  public:  
    TheCollection();
    TheCollection(const TheCollection&);
    ~TheCollection();
    void add(const TheData &obj);
    void del(int pos);
    void insert(int pos, const TheData &d);
    TheData &get(int pos) const;
    void set(int pos, const TheData&);
    int getCount() const;
    // Или так (лучше). 
  private:
    // Этот тип доступен только изнутри.
    struct ListElement {
        TheData obj;
        ListElement *next;
        ListElement();
        ListElement(const TheData&){
            // конструктор копирования
        };
    };
    ListElement *first;
};

TheData &TheCollection::get(int pos) const{
    auto cur=first; // Если он есть.
    for(auto i=0; i<pos && cur; i++, cur=cur->next);
    if( cur )
        return cur->obj;
    cout<<"not enough elements\n";
    return first->obj; // Если он есть.
    //В чем опасность такой реализации?
    //Как ее исправить?
}
// А интерфейс ведь не изменился!

void TheCollection::add(const TheData &d) {
    auto cur=first; // Почему до цикла?
    while(cur->next) cur=cur->next;
    cur->next=new ListElement(d);
}
// А интерфейс ведь не изменился!

void TheCollection::insert(int pos, const TheData &d) {
    // Найти нужную позицию.
    // Вставить.
}
// А интерфейс ведь не изменился!


int TheCollection::getCount() const {
    int count=0;
    // Найти последний элемент
    return count;
}
    
TheCollection::TheCollection() {
    //...
}

TheCollection::TheCollection(const TheCollection &c) {
    //...
}

TheCollection::~TheCollection() {
    //...
}

int main() {
    TheCollection j;
    //...
}
