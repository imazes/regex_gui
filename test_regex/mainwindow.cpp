#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initial_window();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initial_window()
{

    regex_tools regtool;

    auto des_list = regtool.get_regex_method_des();

    for (auto val : des_list)
    {
        ui->regex_method->addItem(val.c_str());
    }

     //ui->regex_method->addItems(val);

}


QStringList  MainWindow::get_txt_src()
{

    QStringList res;

    //��ȡ��������������
    auto txt = ui->txt_src->toPlainText();

    if (ui->cb_regex_on_line->checkState())
    {
        //puts("�����н���");
        auto stringlist = txt.split("\n");

        return stringlist;
    }

    res.append(txt);
    return res;
}


void MainWindow::on_regex_match_clicked()
{

    QStringList string_list = get_txt_src();
    regex_tools c_regextools;

    std::string res;

    for (auto val : string_list)
    {
        std::string regex_method = ui->regex_method->currentText().toStdString();
        bool ingore_caps = ui->cb_regex_ingore_vaps->isChecked();
        std::string src = utf8_2_ansi(
            (const char*)val.toStdString().c_str()
        );
        std::string regular = utf8_2_ansi(
            (const char*)(ui->txt_regex_match->toPlainText().toStdString().c_str())
        );
        

        bool ret=c_regextools.match(
            regex_method,
            ingore_caps,
            src,
            regular
        );

        if (ret)
        {
            //printf("%s\r\n", src.c_str());

            res.append(src.append("\n"));
        }
    }
    std::string res_utf8 = ansi_2_utf8(res.c_str());
    QString qres = res_utf8.c_str();
    ui->txt_dst->setPlainText(qres);
}
void MainWindow::on_regex_replace_clicked()
{

    QStringList string_list = get_txt_src();
    regex_tools c_regextools;

    std::string res;

    for (auto val : string_list)
    {
        std::string regex_method = ui->regex_method->currentText().toStdString();
        bool ingore_caps = ui->cb_regex_ingore_vaps->isChecked();
        std::string src = utf8_2_ansi(
            (const char*)val.toStdString().c_str()
        );
        std::string regular = utf8_2_ansi(
            (const char*)(ui->txt_regex_match->toPlainText().toStdString().c_str())
        );

        std::string replace = utf8_2_ansi(
            (const char*)(ui->txt_regex_replace->toPlainText().toStdString().c_str())
        );
        std::string  tmp_ret = c_regextools.replace(
            regex_method,
            ingore_caps,
            src,
            regular,
            replace
        );

        if (tmp_ret.size()!=0)
        {
            //printf("%s\r\n", src.c_str());

            res.append(tmp_ret.append("\n"));
        }
    }
    std::string res_utf8 = ansi_2_utf8(res.c_str());
    QString qres = res_utf8.c_str();
    ui->txt_dst->setPlainText(qres);
}
