#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Item1");
    ui->comboBox->addItem("Item2");
    ui->comboBox->addItem("Item3");
    ui->comboBox->addItem("Item4");
    ui->comboBox->addItem("Item5");

    QProcess process;
    process.start("cmd /c \"dir c:\\windows\\system32\"");
    process.waitForFinished(-1);
    QByteArray out = process.readAllStandardOutput();

    /*QMessageBox msgBox;
    msgBox.setText(out);
    msgBox.exec();
    msgBox.setText(fileName);
    msgBox.exec();*/
    ui->textBrowser->insertHtml(out);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"", tr("Files (*.*)"));
    ui->lineEdit->setText(fileName);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString current = ui->comboBox->currentText();
    QMessageBox::information(this, "title", current);
    ui->textBrowser->tex       html = ui->textBrowser->html + "heu";
}
