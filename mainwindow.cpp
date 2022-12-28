#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_redblack_clicked()
{
    redBlackDialog = new red_black_window(this);
    redBlackDialog->setModal(1);
    redBlackDialog->show();
}


void MainWindow::on_btn_listaDB_clicked()
{
    listaDialog = new listadb_window(this);
    listaDialog->setModal(1);
    listaDialog->show();
}


void MainWindow::on_btn_tree_clicked()
{
    treeDialog = new tree_window(this);
    treeDialog->setModal(1);
    treeDialog->show();
}


void MainWindow::on_btn_hash_clicked()
{
    hashDialog = new hash_window(this);
    hashDialog->setModal(1);
    hashDialog->show();
}


void MainWindow::on_btn_avl_clicked()
{
    alvDialog = new avl_window(this);
    alvDialog->setModal(1);
    alvDialog->show();
}

void MainWindow::on_btn_cola_clicked()
{
    colaDialog = new cola_window(this);
    colaDialog->setModal(1);
    colaDialog->show();
}


void MainWindow::on_btn_pila_clicked()
{
    pilaDialog = new pila_window(this);
    pilaDialog->setModal(1);
    pilaDialog->show();
}


void MainWindow::on_btn_esparza_clicked()
{
    esparzaDialog = new esparza_window(this);
    esparzaDialog->setModal(1);
    esparzaDialog->show();
}


void MainWindow::on_btn_grafo_clicked()
{
    grafoDialog = new grafo_window(this);
    grafoDialog->setModal(1);
    grafoDialog->show();
}


void MainWindow::on_btn_binaryheap_clicked()
{
    binaryheapDialog = new binaryheap_window(this);
    binaryheapDialog->setModal(1);
    binaryheapDialog->show();
}


void MainWindow::on_btn_lista_clicked()
{
    listaSDialog = new lista_window(this);
    listaSDialog->setModal(1);
    listaSDialog->show();
}

