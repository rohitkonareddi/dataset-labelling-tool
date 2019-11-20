#include "gui.h"
#include "ui_gui.h"
#include <fmt/format.h>
#include <string>

//------GUI initialization functions------//
gui::gui(QWidget* parent)
        : QMainWindow(parent)
        , ui(new Ui::gui)
{
    ui->setupUi(this);
    imageBrowser = new ImageBrowser;

}

gui::~gui()
{
    delete ui;
}

//------On Buttons Click Callbacks------//
void gui::on_ImageBrowseButton_clicked()
{
    imageBrowser = new ImageBrowser;
    QString directory = QFileDialog::getExistingDirectory(this,
                                                          tr("Find Files"), QDir::currentPath());
    imageBrowser->browseFolderForSupportedFiles(directory.toStdString());
    auto i =imageBrowser->returnImages();
    imageListAdd(&i);


}

void gui::on_CropSaveButton_clicked()
{
}

void gui::on_ClassBrowseButton_clicked()
{
}

void gui::on_BBoxBrowseButton_clicked()
{
}

void gui::on_SaveYOLOButton_clicked()
{
}

void gui::on_RestoreButton_clicked()
{
}

//------On click on a item in a list pane------//
void gui::on_ImageList_itemClicked(QListWidgetItem* item)
{
}

void gui::on_ImageList_itemDoubleClicked(QListWidgetItem* item)
{
}

void gui::on_ClassesList_itemClicked(QListWidgetItem* item)
{
}

void gui::on_ClassesList_itemDoubleClicked(QListWidgetItem* item)
{
}

//------Functions to change text of labels------//
void gui::imageListAdd(std::string text)
{
    ui->ImageList->addItem(strToQstr(text));
}

void gui::imageListAdd(const QString& text)
{
    ui->ImageList->addItem(text);
}

void gui::imageListAdd(LinkedList<std::basic_string<char>> *a)
{
    for(int i = 0; i<a->length();i++){

        imageListAdd(imageBrowser->returnImageName(a->at(i)));
    }
}

void gui::setImageInfoLabel(std::string& text)
{
    ui->ImageInfoLabel->setText(strToQstr(text));
}

void gui::setImageInfoLabel(std::string& resolution, std::string& size)
{
    std::string a = fmt::format("{0} {1}", resolution, size);
    ui->ImageInfoLabel->setText(strToQstr(a));
}

void gui::setImageInfoLabel(unsigned short& resoultion_x, unsigned short& resoultion_y, unsigned short& size,
                            std::string& size_units)
{
    std::string a = fmt::format("{0}x{1}, {2} {3}", resoultion_x, resoultion_y, size, size_units);
    ui->ImageInfoLabel->setText(strToQstr(a));
}

//------Other helper functions------//
QString gui::strToQstr(std::string& text)
{
    return QString(QString::fromStdString(text));
}

void gui::setImageFolderLabel(const QString& text)
{
    ui->ImageFolderLabel->setText(text);
}
