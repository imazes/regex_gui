#include "mainwindow.h"
#include <QApplication>
#include <windows.h>


int main(int argc, char *argv[])
{

#ifdef _DEBUG
    AllocConsole();
    SetConsoleTitle(L"Զ�� ��Ƕ���Կ���̨");//���ñ���
    //���ӿ���̨���������
    FILE* pf;
    freopen_s(&pf, "conin$", "r+t", stdin);
    freopen_s(&pf, "conout$", "w+t", stdout);
    freopen_s(&pf, "conout$", "w+t", stderr);
#endif // __DEBUG


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
