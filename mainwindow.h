#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hospede.h"
#include <QDate>
#include <QDebug>
#include "hotel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Inserir_clicked();

    void on_reserva_clicked();

    void on_oalfabeto_clicked();

    void inserirdados();

    void on_opreco_clicked();
    void inserirtabela(Hospede objeto);

private:
    Ui::MainWindow *ui;
    Hospede objeto;
    Hotel hotel;
};

#endif // MAINWINDOW_H
