#include "pila_window.h"
#include "ui_pila_window.h"

pila_window::pila_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pila_window)
{
    ui->setupUi(this);
}

pila_window::~pila_window()
{
    delete ui;
}

void pila_window::on_btn_insert_clicked()
{
    ofstream File("tmp.dot");
    m_Pila.Push(ui->txt_dato->toPlainText().toInt());
    m_Pila.Print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    this->ui->display_size->setText(QString::number(m_Pila.Size()));
    string size = "Size = " + to_string(m_Pila.Size());
    this->ui->display_size->setText(QString::fromStdString(size));
}


void pila_window::on_btn_buscar_clicked()
{
    ofstream File("tmp.dot");
    m_Pila.Pop();
    m_Pila.Print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    string size = "Size = " + to_string(m_Pila.Size());
    this->ui->display_size->setText(QString::fromStdString(size));
}

