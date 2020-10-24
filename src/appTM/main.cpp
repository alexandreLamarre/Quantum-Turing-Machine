#include "mainwindow.h"
#include "dictionary.h"
#include "DTM.h"
#include <QApplication>

void test_all(){
    if(testState() == -1) std::cout << "Tests failed for State object\n";
    else std::cout << "Tests passed for State object\n";

    if(testStates() == -1) std::cout << "Tests failed for States object\n";
    else std::cout << "Tests passed for States Object\n";

    if(testDict() == -1)std::cout << "Tests failed for Dictionary object\n";
    else std::cout << "Tests passed for Dictionary object\n";

    if(testAction() == -1) std::cout << "Tests failed for Action object\n";
    else std::cout << "Tests passed for Action Object\n";

    if(testDTM() == -1) std::cout << "Tests failed for DTM object\n";
    else std::cout << "Tests passed for DTM Object\n";
}


int main(int argc, char *argv[])
{
    test_all();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
