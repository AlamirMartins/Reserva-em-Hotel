#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QObject>
#include <QVector>
#include <algorithm>
#include <QFile>
#include <QDate>
#include "hospede.h"
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int suites[11]={0,1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<11;i++){
    ui->suites->addItem(QString::number(suites[i]));
    }
    int solteiros[11]={0,1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<11;i++){
    ui->solteiro->addItem(QString::number(solteiros[i]));
    }
}

MainWindow::~MainWindow()
{
    delete ui;

}




void MainWindow::on_Inserir_clicked()
{


QDate inicio = ui->checkin->date();
QDate final = ui->checkout->date();

//qDebug()<<inicio.daysTo(final);
int q= inicio.daysTo(final);

objeto.setAdultos(ui->nadultos->text());
objeto.setCriancas(ui->ncrian->text());

int a=ui->suites->currentText().toInt()*100*q + ui->solteiro->currentText().toInt()*50*q;
objeto.setValor(a);
QString b = QString::number(a);
ui->valor->setText((b)+ " Reais");

hotel.inserirHospede(objeto);

inserirdados();


}



void MainWindow::on_reserva_clicked()
{
    int linha = ui->tabela->rowCount();
    ui->tabela->insertRow(linha);
    ui->tabela->setItem(linha,0,new QTableWidgetItem(objeto.getTitular()));
    ui->tabela->setItem(linha,1,new QTableWidgetItem(objeto.getEmail()));
    ui->tabela->setItem(linha,2,new QTableWidgetItem(objeto.getFone()));
    ui->tabela->setItem(linha,3,new QTableWidgetItem(objeto.getCheckin()));
    ui->tabela->setItem(linha,4,new QTableWidgetItem(objeto.getCheckout()));
    ui->tabela->setItem(linha,5,new QTableWidgetItem(QString::number((objeto.getValor()))+ " Reais"));

    //apagar suite e solteiro a partir da quantidade escolhida

    ui->titular->clear();
    ui->email->clear();
    ui->fone->clear();
    ui->valor->clear();


}

void MainWindow::on_oalfabeto_clicked()
{

    ui->tabela->clearContents();
   /* for ( int i = 0; i < ui->tabela->rowCount(); ++i )
    {
        ui->tabela->removeRow(i);
    }
    */for(int i=0;i<hotel.size();i++){
        inserirtabela(hotel[i]);
        hotel.ordenarPorNome();
        qDebug() << i;

    }
}

void MainWindow::inserirdados()
{

    if((ui->titular->text()=="")|(ui->titular->text().size()<4)){
        QMessageBox::warning(this,"TITULAR NÂO INSERIDO!","Preencha todos os campos");
        ui->titular->clear();


    }
    else if(ui->email->text()==""){
        QMessageBox::warning(this,"EMAIL NÂO INSERIDO!","Preencha todos os campos");
        ui->titular->clear();
        ui->email->clear();
        ui->fone->clear();
        ui->checkin->clear();
        ui->checkout->clear();

    }
     else if(ui->fone->text()==""){
        QMessageBox::warning(this,"FONE NÂO INSERIDO!","Preencha todos os campos");
        ui->titular->clear();
        ui->email->clear();
        ui->fone->clear();
        ui->checkin->clear();
        ui->checkout->clear();
    }
     else if((ui->fone->text().size())!=11){
        QMessageBox::warning(this,"NÚMERO INVÁLIDO","Preencha todos os campos");
         ui->fone->clear();

    }
    else if(ui->nadultos->text()=='0'){
        QMessageBox::warning(this,"QUANTIDADE NÂO INSERIDA!","Preencha todos os campos");
        ui->titular->clear();
        ui->email->clear();
        ui->fone->clear();
        ui->checkin->clear();
        ui->checkout->clear();

    }
    else if(ui->ncrian->text()==""){
        QMessageBox::warning(this,"NÂO INSERIDO!","Preencha todos os campos");
        ui->titular->clear();
        ui->email->clear();
        ui->fone->clear();
        ui->checkin->clear();
        ui->checkout->clear();

    }
   else if(ui->suites->currentText()==""){
        QMessageBox::warning(this,"NÂO INSERIDO!","Preencha todos os campos");
        ui->titular->clear();
        ui->email->clear();
        ui->fone->clear();
        ui->checkin->clear();
        ui->checkout->clear();

    }
    else if(ui->solteiro->currentText()==""){
        QMessageBox::warning(this,"NÂO INSERIDO!","Preencha todos os campos");
        ui->titular->clear();
        ui->email->clear();
        ui->fone->clear();
        ui->checkin->clear();
        ui->checkout->clear();

    }

objeto.setTitular(ui->titular->text());
objeto.setEmail(ui->email->text());
objeto.setFone(ui->fone->text());
objeto.setCheckin(ui->checkin->date().toString());
objeto.setCheckout(ui->checkout->date().toString());
}

void MainWindow::on_opreco_clicked()
{
    ui->tabela->clearContents();

    inserirdados();
}

void MainWindow::inserirtabela(Hospede objeto)
{

    int linha = ui->tabela->rowCount();
    ui->tabela->insertRow(linha);
    ui->tabela->setItem(linha,0,new QTableWidgetItem(objeto.getTitular()));
    ui->tabela->setItem(linha,1,new QTableWidgetItem(objeto.getEmail()));
    ui->tabela->setItem(linha,2,new QTableWidgetItem(objeto.getFone()));
    ui->tabela->setItem(linha,3,new QTableWidgetItem(objeto.getCheckin()));
    ui->tabela->setItem(linha,4,new QTableWidgetItem(objeto.getCheckout()));
    ui->tabela->setItem(linha,5,new QTableWidgetItem(QString::number((objeto.getValor()))+ " Reais"));

}
//Ordenar Tabela
//Editar ''
//Carregar Arquivo
//Ajustar quarto por data
