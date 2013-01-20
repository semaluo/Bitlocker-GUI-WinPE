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
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"", tr("Files (*.*)"));
    QProcess process;
    process.start("cmd /c dir C:\\Windows");
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

