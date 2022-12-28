#include "listadb_window.h"
#include "ui_listadb_window.h"

listadb_window::listadb_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listadb_window)
{
    ui->setupUi(this);
}

listadb_window::~listadb_window()
{
    delete ui;
}

void listadb_window::on_btn_insertar_clicked()
{
    ofstream File("tmp.dot");
    m_Lista.push_front(ui->txt_dato->toPlainText().toInt());
    m_Lista.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}



void listadb_window::on_btn_pushback_clicked()
{
    ofstream File("tmp.dot");
    m_Lista.push_back(ui->txt_dato->toPlainText().toInt());
    m_Lista.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}

void listadb_window::on_btn_eliminar_clicked()
{
    ofstream File("tmp.dot");
    m_Lista.pop_front();
    m_Lista.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}


void listadb_window::on_btn_next_clicked()
{
    ofstream File("tmp.dot");
    ++m_Lista;
    m_Lista.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}


void listadb_window::on_btn_previous_clicked()
{
    ofstream File("tmp.dot");
    --m_Lista;
    m_Lista.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}


void listadb_window::on_btn_test_clicked()
{
    ofstream File("tmp.dot");
    m_Lista.push_back(14);
    m_Lista.push_back(53);
    m_Lista.push_back(64);
    m_Lista.push_back(21);
    m_Lista.push_back(37);
    m_Lista.push_back(44);

    m_Lista.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}


void listadb_window::on_btn_begin_clicked()
{
    ofstream File("tmp.dot");
    m_Lista.begin();
    m_Lista.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}


void listadb_window::on_btn_end_clicked()
{
    ofstream File("tmp.dot");
    m_Lista.end();
    m_Lista.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}

