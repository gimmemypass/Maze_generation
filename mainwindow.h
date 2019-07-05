#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsTextItem>


#include "mazegen.h"

#include "recbackgen.h"
#include "hunt_and_hint.h"
#include "bintreegen.h"
#include "wilsonsalg.h"

#include "sizedialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionRecursive_Backtracking_triggered();

    void on_actionSize_triggered();

    void on_actionHunt_Hint_triggered();

    void on_actionBinnary_Tree_triggered();

    void slot_gener(MazeGen *);

    void on_actionWilson_s_Algorithm_triggered();

signals:
    void selectedAlgh(MazeGen *maze);

private:
    int row,
        col;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    MazeGen *maze;
    SizeDialog *sizeDialog;
};

#endif // MAINWINDOW_H
