#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <QTextStream>
#include <QFile>

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
    ui->comboBox->addItem("Suspend");
    ui->comboBox->addItem("Unlock");
    /*ui->comboBox->addItem("Item3");
    ui->comboBox->addItem("Item4");
    ui->comboBox->addItem("Item5");*/

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




    /*QProcess process;
    process.start("cmd /c ");
    process.waitForFinished(-1);
    QByteArray out = process.readAllStandardOutput();
    ui->textBrowser->insertHtml(out);*/
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
        QMessageBox::information(this, "lol", "can't read");
    }

    QTextStream in (&bfile);
    mText = in.readAll();
    bfile.close();

    ui->textBrowser->insertHtml(mText);
    QMessageBox::information(this, "filename", fileName);
    QMessageBox::information(this, "mText", mText);
}

void MainWindow::on_pushButton_2_clicked()
{
    if (ui->comboBox->currentText() == ("Suspend"))
    {
        drive = ui->comboBox_2->currentText() + ":";
        endcommand = (suspend + " " + drive);
        ui->textBrowser->insertHtml(endcommand);
        QMessageBox::information(this, "endcommand", endcommand);
        //QMessageBox::information(this, "title", "Suspend...");
        QMessageBox::information(this, "prosess", endcommand);
        QProcess process;
        //process.start(endcommand);
        process.start("cmd", QStringList() << endcommand);
        //process.waitForFinished(-1);
        QByteArray out = process.readAll();
        ui->textBrowser->insertHtml(out);
    }

    if (ui->comboBox->currentText() == ("Unlock"))
    {
        drive = ui->comboBox_2->currentText() + ":";
        endcommand = (unlock + mText + " " + drive);
        QProcess process;

        //process.start("cmd", QStringList() << endcommand);
        //process.start("cmd");
        //process.waitForFinished(-1);
        //QByteArray out = process.readAll();


        system("cmd");
            //process.waitForFinished(-1);
            //QByteArray out = process.readAll();
        //QByteArray out = process.readAllStandardOutput();
        //ui->textBrowser->insertHtml(out);

        QMessageBox::information(this, "title", mText);
        //QFileSystemWatcher

        //QString drive = ui->comboBox_2->currentText() + ":";
        QMessageBox::information(this, "title", drive);
        //QMessageBox::information(this, "title", "Unlock mæ");
        //endcommand = (unlock + mText + drive);
        QMessageBox::information(this, "title", endcommand);
        //ui->textBrowser->insertHtml("Hei fra unlock ");


    }

   /* if (ui->comboBox->currentText() == ("Suspend"))
    {
        QMessageBox::information(this, "title", "hei på deg");
    } */

    //QString currentcombo = ui->comboBox->currentText();
    //QMessageBox::information(this, "title", currentcombo);

    //ui->textBrowser->setPlainText("");
}
