#include <QObject>
class Counter : public QObject {
  Q_OBJECT // макрос определяет связку функций и статический QMetaObject
 public:
  Counter() { m_value = 0; }
  int value() const { return m_value; }
 public slots: 
  void setValue(int value);
 signals: 
  void valueChanged(int newValue);
 private: 
  int m_value;
};

void Counter::setValue(int value) {
    if (value != m_value) {  
        m_value = value;
        emit valueChanged(value);
    }
}

// emit - пустой макрос, служит для отличия сигналов от обычных методов

Counter a, b;
QObject::connect(&a, &Counter::valueChanged, &b, &Counter::setValue);
a.setValue(12); // a.value() == 12, b.value() == 12
b.setValue(48); // a.value() == 12, b.value() == 48


Counter a, b, c, d;
QObject::connect(&a, &Counter::valueChanged,  &b, &Counter::setValue);
QObject::connect(&a, &Counter::valueChanged,  &c, &Counter::setValue);  
QObject::connect(&b, &Counter::valueChanged,  &d, &Counter::setValue);
a.setValue(12); // a==12, b==12, c==12, d==12  
b.setValue(48); // a==12, b==48, c==12, d==48
