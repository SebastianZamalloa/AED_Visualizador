#include "tree_window.h"
#include "ui_tree_window.h"

tree_window::tree_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tree_window)
{
    ui->setupUi(this);
}

tree_window::~tree_window()
{
    delete ui;
}

void tree_window::on_btn_insertar_clicked()
{
    ofstream File("tmp.dot");
    m_Tree.insert(ui->txt_dato->toPlainText().toInt());

    m_Tree.mostrar(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    //m_Tree.rec_amplitud();
    this->ui->lbl_picture->setPixmap(img);
}


void tree_window::on_btn_buscar_clicked()
{
    ofstream File("tmp.dot");
    m_Tree.Find(File, ui->txt_dato->toPlainText().toInt());

    cout<<"Find.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    //m_Tree.rec_amplitud();
    this->ui->lbl_picture->setPixmap(img);
}

