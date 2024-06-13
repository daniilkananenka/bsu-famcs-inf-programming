# QT Labs
Шпаргалка к экзамену
### QLabel
- Зачем: отображает текст на экране
- Signals: не использовались
- Основные методы:
  - clear() - очищает текст
  - setText(QString) - задает текст надписи
    
### QRadioButton
- Зачем: радиокнопка (круглая) с текстом
- Signals:

### QPushButton
- Зачем : кнопка(?)
- Signals:
pressed () — фиксирует факт нажатия 
released() — когда отпускается
clicked() — фиксирует нажатия и отпускания одновременно(т.е сигналит тогда, когда нажалась и отжалась)
clicked(bool) — clicked() + даёт инфу о состоянии кнопки
- Методы: наследуется от нескольких классов ( к примеру, QWidget) , и т.е. — может обладать и их методами
  - QPushButton::QPushButton(const QIcon &icon, const QString &text, QWidget *parent = nullptr) — максимальная вариация конструктора
  - setText() — очевидно, text() — получаешь текст
setIcon() , icon()
  - setGeometry(x,y,w,h) — расположение и размер
  - resize(w,h) — изменить размер


