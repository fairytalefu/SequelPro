#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void searchDatabaseInfo();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStringList DataBaseName;
    int DataBase_lenght;
    QStandardItem items;
    QStandardItemModel* model;
    QMap<QString, QIcon> m_publicIconMap;
};

#endif // MAINWINDOW_H
