#ifndef LISTA_WINDOW_H
#define LISTA_WINDOW_H

#include <QDialog>
#include <headers/Lista.h>

namespace Ui {
class lista_window;
}

class lista_window : public QDialog
{
    Q_OBJECT

public:
    explicit lista_window(QWidget *parent = nullptr);
    ~lista_window();

private slots:
    void on_btn_push_back_clicked();

    void on_btn_deleteLast_clicked();

    void on_btn_deleteFront_clicked();

    void on_btn_find_clicked();

    void on_btn_max_clicked();

    void on_btn_min_clicked();

private:
    Ui::lista_window *ui;
    ListaS <int> m_Lista;
};

#endif // LISTA_WINDOW_H
