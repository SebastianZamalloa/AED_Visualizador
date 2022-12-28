#ifndef BINARYHEAP_WINDOW_H
#define BINARYHEAP_WINDOW_H

#include <QDialog>
#include <headers/BinaryHeap.h>

namespace Ui {
class binaryheap_window;
}

class binaryheap_window : public QDialog
{
    Q_OBJECT

public:
    explicit binaryheap_window(QWidget *parent = nullptr);
    ~binaryheap_window();

private slots:
    void on_btn_insertar_clicked();

    void on_btn_makemin_clicked();

    void on_btn_makemax_clicked();


    void on_btn_heapsort_clicked();

    void on_btn_heap_sort_Max_clicked();

    void on_btn_test_clicked();

private:
    Ui::binaryheap_window *ui;
    BinaryHeap <int> A;
};

#endif // BINARYHEAP_WINDOW_H
