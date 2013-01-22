#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <QTextStream>

QString fileName;
QString mText;
QString suspend = ("manage-bde -protectors -disable ");
QString unlock = ("manage-bde -unlock ");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Suspend");
    ui->comboBox->addItem("Unlock");
    /*ui->comboBox->addItem("Item3");
    ui->comboBox->addItem("Item4");
    ui->comboBox->addItem("Item5"); */

    QProcess process;
    process.start("cmd /c ");
    process.waitForFinished(-1);
    QByteArray out = process.readAllStandardOutput();
    ui->textBrowser->insertHtml(out);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"", tr("Files (*.*)"));
    ui->lineEdit->setText(fileName);
    QFile mfile (fileName);
    QTextStream in (&mfile);
    mText = in.readAll();
    ui->textBrowser->setText(mText);
    mfile.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    if (ui->comboBox->currentText() = "Suspend")
    {
        QMessageBox::information(this, "title", "hei på deg");
    }
    QString currentcombo = ui->comboBox->currentText();
    QMessageBox::information(this, "title", currentcombo);

    //ui->textBrowser->setPlainText("");
}
