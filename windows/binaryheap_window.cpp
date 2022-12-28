#include "binaryheap_window.h"
#include "ui_binaryheap_window.h"

binaryheap_window::binaryheap_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::binaryheap_window)
{
    ui->setupUi(this);
}

binaryheap_window::~binaryheap_window()
{
    delete ui;
}

void binaryheap_window::on_btn_insertar_clicked()
{
    ofstream File("tmp.dot");
    A.Push_Back(ui->txt_dato->toPlainText().toInt());
    A.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_array->setPixmap(img);
}


void binaryheap_window::on_btn_makemin_clicked()
{
    ofstream File("tmp.dot");
    A.make_heap(0);
    A.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_array->setPixmap(img);



    ofstream File1("tmpT.dot");
    A.printT(File1);
    File1.close();

    string comando1 = "dot -Tjpeg tmpT.dot  -o tmpT.jpeg";

    system(comando1.c_str());
    QPixmap img1("tmpT.jpeg");
    this->ui->lbl_arbol->setPixmap(img1);
}


void binaryheap_window::on_btn_makemax_clicked()
{
    ofstream File("tmp.dot");
    A.make_heap(1);
    A.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_array->setPixmap(img);



    ofstream File1("tmpT.dot");
    A.printT(File1);
    File1.close();

    string comando1 = "dot -Tjpeg tmpT.dot  -o tmpT.jpeg";

    system(comando1.c_str());
    QPixmap img1("tmpT.jpeg");
    this->ui->lbl_arbol->setPixmap(img1);
}


void binaryheap_window::on_btn_heapsort_clicked()
{
    ofstream File("tmp.dot");
    A.HeapSort(1);
    A.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_array->setPixmap(img);

    ofstream File1("tmpT.dot");
    A.printT(File1);
    File1.close();

    string comando1 = "dot -Tjpeg tmpT.dot  -o tmpT.jpeg";

    system(comando1.c_str());
    QPixmap img1("tmpT.jpeg");
    this->ui->lbl_arbol->setPixmap(img1);
}


void binaryheap_window::on_btn_heap_sort_Max_clicked()
{
    ofstream File("tmp.dot");
    A.HeapSort(0);
    A.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_array->setPixmap(img);

    ofstream File1("tmpT.dot");
    A.printT(File1);
    File1.close();

    string comando1 = "dot -Tjpeg tmpT.dot  -o tmpT.jpeg";

    system(comando1.c_str());
    QPixmap img1("tmpT.jpeg");
    this->ui->lbl_arbol->setPixmap(img1);
}


void binaryheap_window::on_btn_test_clicked()
{
    ofstream File("tmp.dot");
    A.Push_Back(12);
    A.Push_Back(21);
    A.Push_Back(34);
    A.Push_Back(2);
    A.Push_Back(15);
    A.Push_Back(38);
    A.Push_Back(40);

    A.print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_array->setPixmap(img);
}

