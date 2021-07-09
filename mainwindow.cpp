#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QString>
#include <cmath>
#include <QMessageBox>
#include "rtfunc.h"
#include <QAction>
#include "basechange.h"
#include "base64.h"

QString strCurrentNumber = "";
double number1 = 0;
double number2 = 0;
QString calcType = "";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //数字按钮信号连接
    connect(ui->button0,&QPushButton::clicked,this,[=]{MainWindow::numBtnPushed(0);});
    connect(ui->button1,&QPushButton::clicked,this,[=]{MainWindow::numBtnPushed(1);});
    connect(ui->button2,&QPushButton::clicked,this,[=]{MainWindow::numBtnPushed(2);});
    connect(ui->button3,&QPushButton::clicked,this,[=]{MainWindow::numBtnPushed(3);});
    connect(ui->button4,&QPushButton::clicked,this,[=]{MainWindow::numBtnPushed(4);});
    connect(ui->button5,&QPushButton::clicked,this,[=]{MainWindow::numBtnPushed(5);});
    connect(ui->button6,&QPushButton::clicked,this,[=]{MainWindow::numBtnPushed(6);});
    connect(ui->button7,&QPushButton::clicked,this,[=]{MainWindow::numBtnPushed(7);});
    connect(ui->button8,&QPushButton::clicked,this,[=]{MainWindow::numBtnPushed(8);});
    connect(ui->button9,&QPushButton::clicked,this,[=]{MainWindow::numBtnPushed(9);});
    connect(ui->btnDot,&QPushButton::clicked,this,[=]{MainWindow::dotBtnPushed();});
    //操作按钮信号连接
    connect(ui->btnDel,&QPushButton::clicked,this,[=]{MainWindow::delBtnPushed();});
    connect(ui->init,&QPushButton::clicked,this,[=]{MainWindow::reBtnPushed();});
    connect(ui->btnPM,&QPushButton::clicked,this,[=]{MainWindow::btnPMPushed();});
    //运算按钮信号连接
    connect(ui->btnPlus,&QPushButton::clicked,this,[=]{MainWindow::calcBtnPushed("plus");});
    connect(ui->btnMinus,&QPushButton::clicked,this,[=]{MainWindow::calcBtnPushed("minus");});
    connect(ui->btnMul,&QPushButton::clicked,this,[=]{MainWindow::calcBtnPushed("mul");});
    connect(ui->btnDiv,&QPushButton::clicked,this,[=]{MainWindow::calcBtnPushed("div");});
    connect(ui->btnEqu,&QPushButton::clicked,this,[=]{MainWindow::equalBtnPushed();});
    connect(ui->btnSqrt,&QPushButton::clicked,this,[=]{MainWindow::sqrtBtnPushed();});
    //菜单按钮信号连接
    connect(ui->actionRtFunc,&QAction::triggered,this,[=]{MainWindow::rtFuncBtnPushed();});
    connect(ui->actionBaseChange,&QAction::triggered,this,[=]{MainWindow::baseChangeBtnPushed();});
    connect(ui->actionBase64,&QAction::triggered,this,[=]{MainWindow::base64BtnPushed();});
}

void MainWindow::numBtnPushed(double number)
{
    strCurrentNumber += QString::number(number);
    ui->screen->setText(strCurrentNumber);
}

void MainWindow::delBtnPushed()
{
    strCurrentNumber.chop(1);
    ui->screen->setText(strCurrentNumber);
}

void MainWindow::reBtnPushed()
{
    number1 = 0;
    number2 = 0;
    strCurrentNumber = "";
    ui->screen->setText("");
}

void MainWindow::calcBtnPushed(QString btnName)
{
    double currentNumber = strCurrentNumber.toDouble();
    number1 = currentNumber;
    calcType = btnName;
    strCurrentNumber = "";
}

void MainWindow::equalBtnPushed()
{
    double currentNumber = strCurrentNumber.toDouble();
    number2 = currentNumber;
    currentNumber = calcHandle(calcType);
    ui->screen->setText(QString::number(currentNumber));
    strCurrentNumber = QString::number(currentNumber);
}

void MainWindow::sqrtBtnPushed()
{
    double currentNumber = strCurrentNumber.toDouble();
    currentNumber = sqrt(currentNumber);
    ui->screen->setText(QString::number(currentNumber));
    strCurrentNumber = QString::number(currentNumber);
}

double MainWindow::calcHandle(QString calcType)
{
    if(calcType == "plus"){
        return number1 + number2;
    }
    else if(calcType == "minus"){
        return number1 - number2;
    }
    else if(calcType == "mul"){
        return number1 * number2;
    }
    else if(calcType == "div"){
        return number1 / number2;
    }
    else{
        abort();
    }
}

void MainWindow::dotBtnPushed()
{
    if(strCurrentNumber.contains(".")){
        QMessageBox::information(NULL,"提示","已有小数点");
    }
    else{
        strCurrentNumber += ".";
    }
}

void MainWindow::btnPMPushed()
{
    double currentNumber = strCurrentNumber.toDouble();
    if(currentNumber == 0){
        QMessageBox::information(NULL,"ERROR","此操作无效");
    }
    else{
        currentNumber = -currentNumber;
    }
    strCurrentNumber = QString::number(currentNumber);
    ui->screen->setText(strCurrentNumber);
}

void MainWindow::rtFuncBtnPushed()
{
    RtFunc *ui = new RtFunc();
    ui->show();
}

void MainWindow::baseChangeBtnPushed()
{
    baseChange *ui = new baseChange();
    ui->show();
}

void MainWindow::base64BtnPushed()
{
    Base64 *ui = new Base64();
    ui->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

