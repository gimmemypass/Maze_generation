#ifndef SIZEDIALOG_H
#define SIZEDIALOG_H

#include <QDialog>

namespace Ui {
class SizeDialog;
}

class SizeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SizeDialog(QWidget *parent = nullptr);
    ~SizeDialog();
    void retData(int &r, int &c);

private:
    Ui::SizeDialog *ui;
};

#endif // SIZEDIALOG_H
