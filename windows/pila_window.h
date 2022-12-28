#ifndef PILA_WINDOW_H
#define PILA_WINDOW_H

#include <QDialog>
#include <headers/Pila.h>

namespace Ui {
class pila_window;
}

class pila_window : public QDialog
{
    Q_OBJECT

public:
    explicit pila_window(QWidget *parent = nullptr);
    ~pila_window();

private slots:
    void on_btn_insert_clicked();

    void on_btn_buscar_clicked();

private:
    Ui::pila_window *ui;
    Pila <int> m_Pila;

};

#endif // PILA_WINDOW_H
