#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>

namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT
    bool Ok;
public:
    explicit DialogLogin(QWidget *parent = 0);
    ~DialogLogin();
    bool getOk(){return Ok;}
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
public slots:

signals:
    void logOk();

private:
    Ui::DialogLogin *ui;

};

#endif // DIALOGLOGIN_H
