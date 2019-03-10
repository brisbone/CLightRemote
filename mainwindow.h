//
// Created by brisbone on 10.03.19.
//

#ifndef CLIGHTREMOTE_MAINWINDOW_H
#define CLIGHTREMOTE_MAINWINDOW_H
#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "Getsensor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
    QString curFile;
    QAction *newAct;
    QAction *saveAct;
    QMenu *myMenu;
    QAction *exitAct;

private slots:
    void change();
};
#endif //CLIGHTREMOTE_MAINWINDOW_H
