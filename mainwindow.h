#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "rtfunc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void numBtnPushed(double number);
    void delBtnPushed();
    void reBtnPushed();
    void calcBtnPushed(QString btnName);
    void equalBtnPushed();
    void sqrtBtnPushed();
    double calcHandle(QString calcType);
    void dotBtnPushed();
    void btnPMPushed();
    void rtFuncBtnPushed();
    void baseChangeBtnPushed();
    void base64BtnPushed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
