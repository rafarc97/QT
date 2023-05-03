#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Calculator");
    ui->result->setText("0.0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sum_clicked()
{
    ui->result->setText(QString::number(ui->n1->value() + ui->n2->value()));
}


void MainWindow::on_sub_clicked()
{
    ui->result->setText(QString::number(ui->n1->value() - ui->n2->value()));
}


void MainWindow::on_mul_clicked()
{
    ui->result->setText(QString::number(ui->n1->value() * ui->n2->value()));
}


void MainWindow::on_div_clicked()
{
    ui->result->setText(QString::number(ui->n1->value() / ui->n2->value()));
}
