#ifndef ESPARZA_WINDOW_H
#define ESPARZA_WINDOW_H

#include <QDialog>
#include <headers/Esparza.h>

namespace Ui {
class esparza_window;
}

class esparza_window : public QDialog
{
    Q_OBJECT

public:
    explicit esparza_window(QWidget *parent = nullptr);
    ~esparza_window();

private slots:
    void on_btn_insertar_clicked();

    void on_btn_DeleteCell_clicked();

    void on_btn_max_row_clicked();

    void on_btn_max_col_clicked();

    void on_btn_min_row_clicked();

    void on_btn_min_col_clicked();

    void on_btn_sort_row_clicked();

    void on_btn_sort_col_clicked();

    void on_btn_delete_row_clicked();

    void on_btn_delete_col_clicked();

    void on_btn_max_clicked();

    void on_btn_mix_clicked();

    void on_btn_transpuesta_clicked();

    void on_btn_test_clicked();

private:
    Ui::esparza_window *ui;
    Matrix <int,6,6> m_Matrix;
};

#endif // ESPARZA_WINDOW_H
