#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <regex>
#include "regex_tools.h"
#include "code_conv.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //初始化界面
    void initial_window();

    //根据 用户选择 解析 输入为
    //多行 或者一个整体
    QStringList  get_txt_src();



private slots:
    void on_regex_match_clicked();

    void on_regex_replace_clicked();

private:
    Ui::MainWindow *ui;
    

};

#endif // MAINWINDOW_H
