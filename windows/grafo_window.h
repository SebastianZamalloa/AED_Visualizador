#ifndef GRAFO_WINDOW_H
#define GRAFO_WINDOW_H

#include <QDialog>
#include <headers/Grafo.h>

namespace Ui {
class grafo_window;
}

class grafo_window : public QDialog
{
    Q_OBJECT

public:
    explicit grafo_window(QWidget *parent = nullptr);
    ~grafo_window();

private slots:
    void on_btn_insert_vertice_clicked();

    void on_btn_insert_arista_clicked();

    void on_btn_test_clicked();

    void on_btn_dijsktra_clicked();

    void on_btn_BFS_clicked();

    void on_btn_DFS_clicked();

private:
    Ui::grafo_window *ui;
    Graph <string , int> m_Graph;
};

#endif // GRAFO_WINDOW_H
