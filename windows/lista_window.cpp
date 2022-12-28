#include "lista_window.h"
#include "ui_lista_window.h"

lista_window::lista_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lista_window)
{
    ui->setupUi(this);
}

lista_window::~lista_window()
{
    delete ui;
}

void lista_window::on_btn_push_back_clicked()
{
    ofstream File("tmp.dot");
    m_Lista.pushBack(ui->txt_dato->toPlainText().toInt());
    m_Lista.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}


void lista_window::on_btn_deleteLast_clicked()
{
    ofstream File("tmp.dot");
    m_Lista.deleteLast();
    m_Lista.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}


void lista_window::on_btn_deleteFront_clicked()
{
    ofstream File("tmp.dot");
    m_Lista.deleteFront();
    m_Lista.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}


void lista_window::on_btn_find_clicked()
{
    ofstream File("tmp.dot");
    m_Lista.print(File,m_Lista.findIt(ui->txt_dato->toPlainText().toInt()));
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}


void lista_window::on_btn_max_clicked()
{
    ofstream File("tmp.dot");
    m_Lista.print(File,m_Lista.maximumIt());
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}


void lista_window::on_btn_min_clicked()
{
    ofstream File("tmp.dot");
    m_Lista.print(File,m_Lista.minumunIt());
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}

