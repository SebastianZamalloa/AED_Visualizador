#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "windows/red_black_window.h"
#include "windows/listadb_window.h"
#include "windows/tree_window.h"
#include "windows/hash_window.h"
#include "windows/avl_window.h"
#include "windows/pila_window.h"
#include "windows/cola_window.h"
#include "windows/esparza_window.h"
#include "windows/grafo_window.h"
#include "windows/binaryheap_window.h"
#include "windows/lista_window.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_tree_clicked();
    void on_btn_redblack_clicked();
    void on_btn_listaDB_clicked();
    void on_btn_hash_clicked();
    void on_btn_avl_clicked();
    void on_btn_cola_clicked();
    void on_btn_pila_clicked();
    void on_btn_esparza_clicked();
    void on_btn_grafo_clicked();

    void on_btn_binaryheap_clicked();

    void on_btn_lista_clicked();

private:
    Ui::MainWindow *ui;
    tree_window * treeDialog;
    red_black_window *redBlackDialog;
    listadb_window *listaDialog;
    hash_window *hashDialog;
    avl_window *alvDialog;
    pila_window *pilaDialog;
    cola_window *colaDialog;
    esparza_window *esparzaDialog;
    grafo_window *grafoDialog;
    binaryheap_window * binaryheapDialog;
    lista_window *listaSDialog;
};
#endif // MAINWINDOW_H
