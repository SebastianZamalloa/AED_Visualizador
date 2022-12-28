#include "grafo_window.h"
#include "ui_grafo_window.h"

grafo_window::grafo_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::grafo_window)
{
    ui->setupUi(this);
}

grafo_window::~grafo_window()
{
    delete ui;
}

void grafo_window::on_btn_insert_vertice_clicked()
{
    ofstream File("tmp.dot");
    //string str = to_string( this->ui->->toPlainText().toInt());
    m_Graph.Insert(ui->txt_vertice->toPlainText().toStdString());

    m_Graph.Print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";

    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    //this->ui->lbl_picture->setScaledContents(true);
}


void grafo_window::on_btn_insert_arista_clicked()
{
    ofstream File("tmp.dot");
    m_Graph.Insert_Edge(ui->txt_vertice1->toPlainText().toStdString(),ui->txt_vertice2->toPlainText().toStdString(),ui->txt_distancia->toPlainText().toInt());

    m_Graph.Print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";
    m_Graph.Print();
    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
    //this->ui->lbl_picture->setScaledContents(true);
}


void grafo_window::on_btn_test_clicked()
{
     ofstream File("tmp.dot");
     m_Graph.Insert("Arequipa");
        m_Graph.Insert("Lima");
        m_Graph.Insert("Cusco");
        m_Graph.Insert("Puno");
        m_Graph.Insert("Tacna");
        m_Graph.Insert("Ica");
        m_Graph.Insert_Edge("Arequipa","Cusco",100);
        m_Graph.Insert_Edge("Arequipa","Puno",160);
        m_Graph.Insert_Edge("Arequipa","Lima",1500);
        m_Graph.Insert_Edge("Puno","Ica",1500);
        m_Graph.Insert_Edge("Puno","Tacna",1070);
        m_Graph.Insert_Edge("Cusco","Puno",400);
        m_Graph.Insert_Edge("Cusco","Tacna",600);
        m_Graph.Insert_Edge("Tacna","Lima",600);
        m_Graph.Insert_Edge("Tacna","Arequipa",600);
        m_Graph.Insert_Edge("Lima","Puno",600);
        m_Graph.Insert_Edge("Ica","Arequipa",600);

       m_Graph.Print(File);
       cout<<"Paso.."<<endl;
       File.close();
       string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";
       m_Graph.Print();
       system(comando.c_str());
       QPixmap img("tmp.jpeg");
       this->ui->lbl_picture->setPixmap(img);
}


void grafo_window::on_btn_dijsktra_clicked()
{
    ofstream File("tmp.dot");


    m_Graph.Print(File,m_Graph.disjtrak_alg(ui->txt_origen_dj->toPlainText().toStdString(), ui->txt_destino_dj->toPlainText().toStdString()));
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";
    m_Graph.Print();
    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);
}



void grafo_window::on_btn_BFS_clicked()
{
    ofstream File("tmp.dot");


    m_Graph.Print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";
    m_Graph.Print();
    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);


    ofstream File2("tmp2.dot");
    m_Graph.Print(File2,m_Graph.BFS());
    File2.close();
    string comando2 = "dot -Tjpeg tmp2.dot  -o tmp2.jpeg";

    system(comando2.c_str());
    QPixmap img2("tmp2.jpeg");
    this->ui->lbl_picture2->setPixmap(img2);


}


void grafo_window::on_btn_DFS_clicked()
{
    ofstream File("tmp.dot");


    m_Graph.Print(File);
    cout<<"Paso.."<<endl;
    File.close();
    string comando = "dot -Tjpeg tmp.dot  -o tmp.jpeg";
    m_Graph.Print();
    system(comando.c_str());
    QPixmap img("tmp.jpeg");
    this->ui->lbl_picture->setPixmap(img);


    ofstream File3("tmp3.dot");
    m_Graph.Print(File3,m_Graph.DFS());
    File3.close();
    string comando3 = "dot -Tjpeg tmp3.dot  -o tmp3.jpeg";

    system(comando3.c_str());
    QPixmap img3("tmp3.jpeg");
    this->ui->lbl_picture3->setPixmap(img3);


}

