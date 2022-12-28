#ifndef HASH_WINDOW_H
#define HASH_WINDOW_H

#include <QDialog>
#include <headers/Hash.h>

namespace Ui {
class hash_window;
}

class hash_window : public QDialog
{
    Q_OBJECT

public:
    explicit hash_window(QWidget *parent = nullptr);
    ~hash_window();

private slots:
    void on_btn_insertar_clicked();

private:
    Ui::hash_window *ui;
    Hash <int,5> m_Hash;
};

#endif // HASH_WINDOW_H
