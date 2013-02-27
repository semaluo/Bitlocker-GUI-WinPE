#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <QTextStream>
#include <QFile>
#include <stdlib.h>

QString fileName;
QString mText;
QFile bfile;
QString drive;
QString endcommand;
QString suspend = ("manage-bde.exe -protectors -disable ");
QString unlock = ("manage-bde.exe -unlock -recoverypassword ");


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Legger til Item i comboboxene.
    ui->comboBox->addItem("Unlock");
    ui->comboBox->addItem("Suspend");
    ui->comboBox_2->addItem("A");
    ui->comboBox_2->addItem("B");
    ui->comboBox_2->addItem("C");
    ui->comboBox_2->addItem("D");
    ui->comboBox_2->addItem("E");
    ui->comboBox_2->addItem("F");
    ui->comboBox_2->addItem("G");
    ui->comboBox_2->addItem("H");
    ui->comboBox_2->addItem("I");
    ui->comboBox_2->addItem("J");
    ui->comboBox_2->addItem("K");
    ui->comboBox_2->addItem("L");
    ui->comboBox_2->addItem("M");
    ui->comboBox_2->addItem("N");
    ui->comboBox_2->addItem("O");
    ui->comboBox_2->addItem("P");
    ui->comboBox_2->addItem("Q");
    ui->comboBox_2->addItem("R");
    ui->comboBox_2->addItem("S");
    ui->comboBox_2->addItem("T");
    ui->comboBox_2->addItem("U");
    ui->comboBox_2->addItem("V");
    ui->comboBox_2->addItem("W");
    ui->comboBox_2->addItem("X");
    ui->comboBox_2->addItem("Y");
    ui->comboBox_2->addItem("Z");
    //ui->comboBox_2->setItemText("D");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"", tr("Files (*.*)"));
    ui->lineEdit->setText(fileName);
    QFile bfile (fileName);

    if(!bfile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(this, "Error", "have not selected file or file is unreadable");
    }
    QTextStream in (&bfile);
    mText = in.readAll();
    bfile.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    drive = ui->comboBox_2->currentText() + ":";
    if (ui->comboBox->currentText() == ("Suspend"))
    {
        endcommand = (suspend + " " + drive);
    }

    if (ui->comboBox->currentText() == ("Unlock"))
    {
        endcommand = (unlock + mText + " " + drive);
    }
    ui->textBrowser->setText(endcommand);
    system(qPrintable(endcommand));
}
