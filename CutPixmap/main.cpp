#include "CutPixmap.h"
#include <QtWidgets/QApplication>
#include"TransToolBar.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CutPixmap w;
	w.show();
    return a.exec();
}
