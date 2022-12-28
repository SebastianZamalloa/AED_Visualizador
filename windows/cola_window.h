#ifndef COLA_WINDOW_H
#define COLA_WINDOW_H

#include <QDialog>
#include <headers/Cola.h>

namespace Ui {
class cola_window;
}

class cola_window : public QDialog
{
    Q_OBJECT

public:
    explicit cola_window(QWidget *parent = nullptr);
    ~cola_window();

private slots:
    void on_btn_insertar_clicked();

    void on_btn_eliminar_clicked();

private:
    Ui::cola_window *ui;
    Cola <int> m_Cola;
};

#endif // COLA_WINDOW_H
