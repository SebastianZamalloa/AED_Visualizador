#include "cola_window.h"
#include "ui_cola_window.h"

cola_window::cola_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cola_window)
{
    ui->setupUi(this);
}

cola_window::~cola_window()
{
    delete ui;
}

void cola_window::on_btn_insertar_clicked()
{
    ofstream File("tmp.dot");
    m_Cola.Push(ui->txt_dato->toPlainText().toInt());

    m_Cola.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}


void cola_window::on_btn_eliminar_clicked()
{
    ofstream File("tmp.dot");
    m_Cola.Pop();
    m_Cola.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
     this->ui->lbl_picture->setPixmap(img);
}

