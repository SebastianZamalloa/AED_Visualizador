#ifndef RED_BLACK_WINDOW_H
#define RED_BLACK_WINDOW_H

#include <QDialog>
#include <headers/Red_black.h>
namespace Ui {
class red_black_window;
}

class red_black_window : public QDialog
{
    Q_OBJECT

public:
    explicit red_black_window(QWidget *parent = nullptr);
    ~red_black_window();

private slots:
    void on_btn_insertar_clicked();
    void on_btn_buscar_clicked();

private:
    Ui::red_black_window *ui;
    RBTree <int> m_Tree;
};

#endif // RED_BLACK_WINDOW_H
