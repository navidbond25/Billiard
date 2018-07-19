#include <iostream>
#include "HeaderFiles/Matching.h"
int main(int argc,char **argv)
{
    QApplication app(argc, argv);

    new Matching;

    return app.exec();
}