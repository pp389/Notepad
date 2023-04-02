#include <QAction>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    menuBar = new MenuBar(this);
    this->setMenuBar(menuBar);

    statusBar = new StatusBar(this);
    this->setStatusBar(statusBar);

    toolBar = new ToolBar(this);
    this->addToolBar(toolBar);

    centralWidget = new QWidget(this);
    centralWidgetLayout = new QVBoxLayout(centralWidget);
    this->setCentralWidget(centralWidget);

    textBox = new TextBox(centralWidget, this);

    centralWidgetLayout->addWidget(textBox);
    centralWidgetLayout->addWidget(statusBar);

    this->resize(1000, 700);
    this->setWindowTitle("Notepad");
}

MainWindow::~MainWindow() {
    delete menuBar;
    delete centralWidgetLayout;
    delete textBox;
}

