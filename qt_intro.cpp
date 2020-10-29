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
