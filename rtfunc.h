#ifndef RTFUNC_H
#define RTFUNC_H

#include <QWidget>

namespace Ui {class RtFunc;}

class RtFunc : public QWidget
{
    Q_OBJECT
public:
    explicit RtFunc(QWidget *parent = nullptr);
    ~RtFunc();
    void funcBtnPushed(QString func);

private:
    Ui::RtFunc *ui;
};

#endif // RTFUNC_H
