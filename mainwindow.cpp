#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sql.h"

Sql sql;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel(ui->databaseView);
    DataBaseName = sql.getDatabaseName();
    DataBase_lenght = DataBaseName.length();

    model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("Databases")<<QStringLiteral("Tables"));
    ui->databaseView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::searchDatabaseInfo()
{

    QStandardItem* itemProject = new QStandardItem(m_publicIconMap[QStringLiteral("Databases")],QStringLiteral("项目"));
    model->appendRow(itemProject);
    QStandardItem* itemChild = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("文件夹1"));
    itemProject->appendRow(itemChild);
}
