    #include "hash_window.h"
#include "ui_hash_window.h"

hash_window::hash_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hash_window)
{
    ui->setupUi(this);
}

hash_window::~hash_window()
{
    delete ui;
}

void hash_window::on_btn_insertar_clicked()
{
    ofstream File("tmp.dot");
    string str = to_string( this->ui->txt_string->toPlainText().toInt());
    m_Hash.Insert(str,ui->txt_obj->toPlainText().toInt());

    //m_Hash.Insert(ui->text_string->toPlainText(),ui->text_obj->toPlainText().toInt());
    m_Hash.Print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);

    //this->ui->lbl_picture->setScaledContents(true);

    //this->ui->lbl_picture->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}

