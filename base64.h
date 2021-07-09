#ifndef BASE64_H
#define BASE64_H

#include <QWidget>

namespace Ui {
class Base64;
}

class Base64 : public QWidget
{
    Q_OBJECT

public:
    explicit Base64(QWidget *parent = nullptr);
    ~Base64();
    void btnEncodePushed();
    void btnDecodePushed();

private:
    Ui::Base64 *ui;
};

#endif // BASE64_H
