//
// Created by brisbone on 10.03.19.
//
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    QObject::connect(ui -> pushButton, SIGNAL(clicked()), this, SLOT(change()));
    ui -> lineEdit -> setText("test");
    createActions();
    createMenus();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::change(){
    Getsensor *getsender = new Getsensor;
    char url[] = "http://ras.uwxy.de/sender.json";
    QString buffer = QString::fromStdString(getsender->fetchSender(url));

    ui -> result -> setText(buffer);
}

void MainWindow::createActions(){
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenus(){
//    myMenu->addAction(men)
//    ui->menuDatei->addMenu(myMenu);
}
