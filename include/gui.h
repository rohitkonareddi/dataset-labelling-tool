#ifndef GUI_H
#define GUI_H
#include "maincontroller.h"
#include <iostream>
#include <string>
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QLineEdit>
#include "ui_gui.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class gui;
}
QT_END_NAMESPACE

class gui : public QMainWindow {
Q_OBJECT

public:
    //------GUI initialization functions------//
    gui(QWidget* parent = nullptr);
    ~gui();

private slots:
    //------On Buttons Click Callbacks------//
    void on_ImageBrowseButton_clicked();
    void on_CropSaveButton_clicked();
    void on_ClassBrowseButton_clicked();
    void on_BBoxBrowseButton_clicked();
    void on_SaveYOLOButton_clicked();
    void on_RestoreButton_clicked();
    //------On click on a item in a list pane------//
    void on_ImageList_itemClicked(QListWidgetItem* item);
    void on_ImageList_itemDoubleClicked(QListWidgetItem* item);
    void on_ClassesList_itemClicked(QListWidgetItem *item);
    void on_ClassesList_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::gui* ui;
    void clearGui();
    MainController *controller;

};
#endif // GUI_H
