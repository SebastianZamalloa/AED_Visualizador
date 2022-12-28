#ifndef LISTADB_WINDOW_H
#define LISTADB_WINDOW_H

#include <QDialog>
#include <headers/ListaDB.h>

namespace Ui {
class listadb_window;
}

class listadb_window : public QDialog
{
    Q_OBJECT

public:
    explicit listadb_window(QWidget *parent = nullptr);
    ~listadb_window();

private slots:
    void on_btn_insertar_clicked();

    void on_btn_eliminar_clicked();

    void on_btn_next_clicked();

    void on_btn_previous_clicked();

    void on_btn_pushback_clicked();

    void on_btn_test_clicked();

    void on_btn_begin_clicked();

    void on_btn_end_clicked();

private:
    Ui::listadb_window *ui;
    Lista <int> m_Lista;
};

#endif // LISTADB_WINDOW_H
