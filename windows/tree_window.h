#ifndef TREE_WINDOW_H
#define TREE_WINDOW_H

#include <QDialog>
#include "headers/Tree.h"
namespace Ui {
class tree_window;
}

class tree_window : public QDialog
{
    Q_OBJECT

public:
    explicit tree_window(QWidget *parent = nullptr);
    ~tree_window();

private slots:
    void on_btn_insertar_clicked();

    void on_btn_buscar_clicked();

private:
    Ui::tree_window *ui;
    Tree <int> m_Tree;
};

#endif // TREE_WINDOW_H
