#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    this->setWindowTitle("Генерация лабиринтов");
    this->setFixedSize(870,700);
    this->setStyleSheet("background-color:rgb(0,3,35);");

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setGeometry(10,20,850,650);
//    ui->graphicsView->setFixedSize(850,650);
    ui->graphicsView->setAlignment(Qt::AlignCenter);
    ui->graphicsView->setBackgroundBrush(QBrush(QColor(0,3,35)));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->graphicsView->setEnabled(false);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    scene->addRect(0,0,800,600,QPen(Qt::white));
    QGraphicsTextItem *text = new QGraphicsTextItem();
    text->setPos(0,200);
    text->setPlainText("\tГенератор\n\t\t\t\t лабиринтов");
    text->setDefaultTextColor(Qt::white);
    text->setFont(QFont("Times", 60, -1));
    scene->addItem(text);
    scene->setSceneRect(0,0,800,600);
    row = col = 10;

    connect(this, SIGNAL(selectedAlgh(MazeGen *)), this, SLOT(slot_gener(MazeGen *)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_gener(MazeGen *alg){
    if(maze) delete maze;
    maze = alg;
    maze->gener();
    maze->solveMaze(0,maze->get_in_point().y());
}

void MainWindow::on_actionSize_triggered()
{
    sizeDialog = new SizeDialog;
    if(sizeDialog->exec()){
        sizeDialog->retData(this->row, this->col);
    }
}

void MainWindow::on_actionRecursive_Backtracking_triggered()
{
    emit selectedAlgh(new RecBackGen(scene, row, col));
}

void MainWindow::on_actionHunt_Hint_triggered()
{

    emit selectedAlgh(new Hunt_and_Hint(scene, row, col));
}

void MainWindow::on_actionBinnary_Tree_triggered()
{
    emit selectedAlgh(new BinTreeGen(scene, row, col));
}

void MainWindow::on_actionWilson_s_Algorithm_triggered()
{
    emit selectedAlgh(new WilsonsAlg(scene,row, col));
}
