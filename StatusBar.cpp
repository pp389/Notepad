#include "StatusBar.h"
#include "MainWindow.h"

StatusBar::StatusBar(QMainWindow* parent) {
    mainWindow = dynamic_cast<MainWindow*>(parent);

    currentFileName = new QLabel(this);
    currentFileName->setText("File not saved");
    this->addPermanentWidget(currentFileName);

    cursorPosition = new QLabel(this);
    this->addPermanentWidget(cursorPosition);
    cursorPosition->setText("y: 0 x: 0");
}

void StatusBar::updateFileName(QString newFileName) {
    currentFileName->setText(newFileName);
}

void StatusBar::updateCursorPosition(int x, int y) {
    cursorPosition->setText("y: " + QString::number(x) + " x: " + QString::number(y));
}

StatusBar::~StatusBar() {
    delete currentFileName;
    delete cursorPosition;
}
