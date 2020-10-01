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
    // массив данных
};

/*
// На динамическом массиве без оптимизации
class TheCollection {
  public:  
    TheCollection();
    TheCollection(const TheCollection&);
    TheCollection(const TheCollection&&);
    ~TheCollection();
    void add(const TheData &obj);
    void del(int pos);
    void del(const TheData &obj);
    TheData &get(int pos);
    void set(int pos, const TheData&);
  private:
    TheData *objects;// Массив объектов
    int count; // Число объектов.
};
*/

// На динамическом массиве с оптимизацией
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
    int getCount() const {return count;};
    // Или так (лучше). 
  private:
    TheData *objects;// Массив объектов
    int count; // Число объектов.
    int allocated; // Выделено объектов.
    // Выделять, освобождать память долго.
    // Резервируем дополнительную память на  несколько (а не один) объектов.
    void grow(); // Выделяем здесь.
};
/*
// Выберите одно решение из двух.
TheCollection::TheCollection() {
    objects=NULL; 
    count=allocated=0;
}
*/
// В стиле С++98 можно так:
TheCollection::TheCollection() :objects(NULL),count(0),allocated(0) {
}

TheCollection::TheCollection(const TheCollection &c) {
    count=c.getCount();
    objects=new TheData[count];
    allocated=count;
    for(auto i=0; i<count; i++)
        objects[i].copy(c.get(i));
}

TheCollection::~TheCollection() {
    if(allocated)
        delete [] objects;
}

TheData &TheCollection::get(int pos) const {
    if(pos<0 || pos>=count) {
        cout<<"not enough elements\n";
        pos=0;
    }
    return objects[pos];
}

void TheCollection::grow() {
    TheData *tmp=new TheData[count+4]; // лучше использовать realloc для стандартных типов
    for(auto i=0; i<count; i++)
        tmp[i].replace(objects[i]);
    delete [] objects;
    objects=tmp;
    allocated+=4;
}
// Тип переменной auto i определяется автоматически компилятором стандарта C++11

void TheCollection::add(const TheData &d) {
    if(count==allocated)
        grow();
    objects[count++].copy(d);
}

void TheCollection::insert(int pos, const TheData &d) {
    if(++count>=allocated)
        grow();
    move(pos); // Сдвигаем объекты
    objects[pos].copy(d);
}
// Вот только эффективно ли это  решение?

int main() {
    TheCollection j;
    //...
}
