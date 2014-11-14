#ifndef UI_CAMBIARPASSDIALOG_H
#define UI_CAMBIARPASSDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class ui_cambiarPassDialog;
}

class ui_cambiarPassDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ui_cambiarPassDialog(QWidget *parent = 0);
    ~ui_cambiarPassDialog();
    void set_idusr(int val=0){id_usr=val;}

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_lineEdit_nuevoPass_textChanged(const QString &arg1);

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::ui_cambiarPassDialog *ui;
    int id_usr;
};

#endif // UI_CAMBIARPASSDIALOG_H
