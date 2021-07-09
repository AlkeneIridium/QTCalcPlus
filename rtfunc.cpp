#include "rtfunc.h"
#include "ui_rtfunc.h"
#include <QString>
#include <cmath>
#include <QPushButton>

RtFunc::RtFunc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RtFunc)
{
    ui->setupUi(this);
    connect(ui->btnSin,&QPushButton::clicked,this,[=]{RtFunc::funcBtnPushed("sin");});
    connect(ui->btnCos,&QPushButton::clicked,this,[=]{RtFunc::funcBtnPushed("cos");});
    connect(ui->btnTan,&QPushButton::clicked,this,[=]{RtFunc::funcBtnPushed("tan");});
    connect(ui->btnCot,&QPushButton::clicked,this,[=]{RtFunc::funcBtnPushed("cot");});
    connect(ui->btnSec,&QPushButton::clicked,this,[=]{RtFunc::funcBtnPushed("sec");});
    connect(ui->btnCsc,&QPushButton::clicked,this,[=]{RtFunc::funcBtnPushed("csc");});
}

void RtFunc::funcBtnPushed(QString func)
{
    QString strNumber = ui->inputText->text();
    double number = strNumber.toDouble();
    double result = 0;
    if(func == "sin"){
        result = sin(number);
    }
    else if(func == "cos"){
        result = cos(number);
    }
    else if(func == "tan"){
        result = tan(number);
    }
    else if(func == "cot"){
        result = pow(tan(number),-1);
    }
    else if(func == "sec"){
        result = pow(cos(number),-1);
    }
    else if(func == "csc"){
        result = pow(sin(number),-1);
    }
    else{
        abort();
    }
    ui->outputText->setText(QString::number(result));
}

RtFunc::~RtFunc()
{
    delete ui;
}
