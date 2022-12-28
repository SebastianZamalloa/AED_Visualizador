#ifndef AVL_WINDOW_H
#define AVL_WINDOW_H

#include <QDialog>
#include <headers/Avl.h>

namespace Ui {
class avl_window;
}

class avl_window : public QDialog
{
    Q_OBJECT

public:
    explicit avl_window(QWidget *parent = nullptr);
    ~avl_window();

private slots:

    void on_btn_insertar_clicked();

    void on_btn_buscar_clicked();

private:
    Ui::avl_window *ui;
    AVLTree <int> m_Tree;
};

#endif // AVL_WINDOW_H
