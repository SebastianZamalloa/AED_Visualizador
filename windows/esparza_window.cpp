#include "esparza_window.h"
#include "ui_esparza_window.h"

esparza_window::esparza_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::esparza_window)
{
    ui->setupUi(this);
}

esparza_window::~esparza_window()
{
    delete ui;
}

void esparza_window::on_btn_insertar_clicked()
{
    ofstream File("tmp.dot");
    //string str = to_string( this->ui->->toPlainText().toInt());
    m_Matrix.Insert(ui->txt_dato->toPlainText().toInt(),ui->txt_fila->toPlainText().toInt(),ui->txt_columna->toPlainText().toInt());

    m_Matrix.Print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    this->ui->lbl_picture->setScaledContents(true);
}


void esparza_window::on_btn_DeleteCell_clicked()
{
    ofstream File("tmp.dot");
    m_Matrix.Delete_Cell(ui->delete_cell_fil->toPlainText().toInt(),ui->delete_cell_col->toPlainText().toInt());

    m_Matrix.Print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    this->ui->lbl_picture->setScaledContents(true);
}

void esparza_window::on_btn_max_row_clicked()
{
    ofstream File("tmp.dot");
   // m_Matrix.Max_Row(ui->txt_max_row_fila->toPlainText().toInt());

    m_Matrix.Print(File,m_Matrix.Max_Row(ui->txt_max_row_fila->toPlainText().toInt()));
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    this->ui->lbl_picture->setScaledContents(true);

}


void esparza_window::on_btn_max_col_clicked()
{
    ofstream File("tmp.dot");

    m_Matrix.Print(File,m_Matrix.Max_Col(ui->txt_max_col_col->toPlainText().toInt()));
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    this->ui->lbl_picture->setScaledContents(true);
}


void esparza_window::on_btn_min_row_clicked()
{
    ofstream File("tmp.dot");

    m_Matrix.Print(File,m_Matrix.Min_Row(ui->txt_min_row_fila->toPlainText().toInt()));
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    this->ui->lbl_picture->setScaledContents(true);
}


void esparza_window::on_btn_min_col_clicked()
{
    ofstream File("tmp.dot");

    m_Matrix.Print(File,m_Matrix.Min_Col(ui->txt_min_col_col->toPlainText().toInt()));
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    this->ui->lbl_picture->setScaledContents(true);
}


void esparza_window::on_btn_sort_row_clicked()
{
    ofstream File("tmp.dot");
    m_Matrix.Sort_Row(ui->txt_sort_row_fila->toPlainText().toInt());
    m_Matrix.Print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    this->ui->lbl_picture->setScaledContents(true);
}


void esparza_window::on_btn_sort_col_clicked()
{
    ofstream File("tmp.dot");
    m_Matrix.Sort_Col(ui->txt_sort_col_col->toPlainText().toInt());
    m_Matrix.Print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    this->ui->lbl_picture->setScaledContents(true);
}


void esparza_window::on_btn_delete_row_clicked()
{
    ofstream File("tmp.dot");
    m_Matrix.Delete_Row(ui->txt_delete_row_row->toPlainText().toInt());
    m_Matrix.Print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    this->ui->lbl_picture->setScaledContents(true);
}


void esparza_window::on_btn_delete_col_clicked()
{
    ofstream File("tmp.dot");
    m_Matrix.Delete_Col(ui->txt_delete_col_col->toPlainText().toInt());
    m_Matrix.Print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    this->ui->lbl_picture->setScaledContents(true);
}


void esparza_window::on_btn_max_clicked()
{
    ofstream File("tmp.dot");

    m_Matrix.Print(File,m_Matrix.Max());
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    this->ui->lbl_picture->setScaledContents(true);
}


void esparza_window::on_btn_mix_clicked()
{
    ofstream File("tmp.dot");

    m_Matrix.Print(File,m_Matrix.Min());
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    this->ui->lbl_picture->setScaledContents(true);
}


void esparza_window::on_btn_transpuesta_clicked()
{
    ofstream File("tmp.dot");
    m_Matrix.Transpose();
    m_Matrix.Print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    this->ui->lbl_picture->setScaledContents(true);
}


void esparza_window::on_btn_test_clicked()
{
    ofstream File("tmp.dot");
    //string str = to_string( this->ui->->toPlainText().toInt());
    m_Matrix.Insert(10,0,2);
    m_Matrix.Insert(12,2,3);
    m_Matrix.Insert(15,3,4);
    m_Matrix.Insert(4,2,2);
    m_Matrix.Insert(9,4,4);
    m_Matrix.Insert(18,5,5);
    m_Matrix.Insert(22,1,5);
    m_Matrix.Insert(41,4,1);
    m_Matrix.Insert(13,1,3);
    m_Matrix.Insert(17,3,2);
    m_Matrix.Insert(81,0,1);
    m_Matrix.Insert(7,3,0);
    m_Matrix.Insert(30,2,5);
    m_Matrix.Insert(11,1,5);

    m_Matrix.Print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    this->ui->lbl_picture->setScaledContents(true);
}

