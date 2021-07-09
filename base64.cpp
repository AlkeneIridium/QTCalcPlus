#include "base64.h"
#include "ui_base64.h"

Base64::Base64(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Base64)
{
    ui->setupUi(this);
    connect(ui->btnEncode,&QPushButton::clicked,this,[=]{Base64::btnEncodePushed();});
    connect(ui->btnDecode,&QPushButton::clicked,this,[=]{Base64::btnDecodePushed();});
}

void Base64::btnEncodePushed()
{
    QString inputText = ui->inputBox->toPlainText();
    QString outputText = inputText.toUtf8().toBase64();
    ui->outputBox->setText(outputText);
}

void Base64::btnDecodePushed()
{
    QByteArray inputText = ui->inputBox->toPlainText().toLocal8Bit();
    inputText = QByteArray::fromBase64(inputText);
    QString outputText = QString::fromLocal8Bit(inputText);
    ui->outputBox->setText(outputText);
}

Base64::~Base64()
{
    delete ui;
}
