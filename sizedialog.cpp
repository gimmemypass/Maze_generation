#include "sizedialog.h"
#include "ui_sizedialog.h"

SizeDialog::SizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SizeDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Установка размера сетки");
    ui->RSpinBox->setValue(10);
    ui->CSpinBox->setValue(10);
    ui->RSpinBox->setRange(2,30);
    ui->CSpinBox->setRange(2,40);
}

SizeDialog::~SizeDialog()
{
    delete ui;
}

void SizeDialog::retData(int &r, int &c){
    r = ui->RSpinBox->value();
    c = ui->CSpinBox->value();
}
