#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

double firstNum;
bool userIsTypingSecondNum=false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_devide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_devide->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digit_pressed()
{
    QPushButton*Button=(QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    if((ui->pushButton_plus->isChecked() || ui->pushButton_minus->isChecked()
        || ui->pushButton_multiply->isChecked() || ui->pushButton_devide->isChecked()) && (!userIsTypingSecondNum))
    {
        labelNumber= Button->text().toDouble();
        userIsTypingSecondNum=true;
    }
    else
    {
        labelNumber=(ui->label->text() + Button->text()).toDouble();
    }
    newLabel=QString::number(labelNumber,'g',15);
    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_dot_released()
{
    bool CheckForDot=false;
    for(auto i:ui->label->text())
    {
        if(i==".")
        {
            CheckForDot=true;
            break;
        }
    }
    if(!CheckForDot){
    ui->label->setText(ui->label->text()+".");
    }
}


void MainWindow::on_pushButton_clear_clicked()
{
    QString str;
    str=QString::number(0,'g',15);
    ui->label->setText(str);
}


void MainWindow::on_pushButton_plus_clicked()
{
    double PrevNum,NewNum;
    QString label;


}


void MainWindow::on_pushButton_plusminus_clicked()
{
    double num;
    num=ui->label->text().toDouble();
    num*=-1;
     ui->label->setText(QString::number(num,'g',15));
}


void MainWindow::on_pushButton_percent_clicked()
{
    double num=ui->label->text().toDouble();
    num*=0.01;
    ui->label->setText(QString::number(num,'g',15));
}


void MainWindow::on_pushButton_equals_released()
{
    double labelNumber,secondNum;
    QString newLabel;
    secondNum= ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked())
    {
        labelNumber=firstNum+secondNum;
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked())
    {
        labelNumber=firstNum-secondNum;
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked())
    {
        labelNumber=firstNum*secondNum;
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_multiply->setChecked(false);
    }
    else if(ui->pushButton_devide->isChecked())
    {
        labelNumber=firstNum/secondNum;
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_devide->setChecked(false);
    }

    userIsTypingSecondNum=false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton*button=(QPushButton*) sender();

    firstNum=ui->label->text().toDouble();


    button->setChecked(true);
}
