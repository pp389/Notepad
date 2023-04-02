#include <QMessageBox>
#include <QFileDialog>
#include <QCoreApplication>
#include "MenuBar.h"
#include "MainWindow.h"


MenuBar::MenuBar(QMainWindow* mainWindow)
    : QMenuBar(mainWindow) {

    this->mainWindow = dynamic_cast<MainWindow*>(mainWindow);

    fileMenu = this->addMenu("File");
    editMenu = this->addMenu("Edit");
    helpMenu = this->addMenu("Help");

    //fileMenu actions
    newAction = new QAction("New", this);
    openAction = new QAction("Open", this);
    saveAction = new QAction("Save", this);
    saveAsAction = new QAction("Save as", this);
    exitAction = new QAction("Exit", this);

    //editMenu actions
    undoAction = new QAction("Undo", this);
    cutAction = new QAction("Cut", this);
    copyAction = new QAction("Copy", this);
    pasteAction = new QAction("Paste", this);
    findAndReplaceAction = new QAction("Find and replace", this);

    //helpMenu actions
    helpAction = new QAction("Help", this);

    setupMenus();
    setupSignalsAndSlots();
}

void MenuBar::setupMenus() {
    //setup shortcuts
    newAction->setShortcut(Qt::CTRL | Qt::Key_N);
    openAction->setShortcut(Qt::CTRL | Qt::Key_O);
    saveAction->setShortcut(Qt::CTRL | Qt::Key_S);
    saveAsAction->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_S);
    undoAction->setShortcut(Qt::CTRL | Qt::Key_Z);
    cutAction->setShortcut(Qt::CTRL | Qt::Key_X);
    copyAction->setShortcut(Qt::CTRL | Qt::Key_C);
    pasteAction->setShortcut(Qt::CTRL | Qt::Key_V);
    findAndReplaceAction->setShortcut(Qt::CTRL | Qt::Key_F);

    //add fileMenu actions
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    //add editMenu actions
    editMenu->addAction(undoAction);
    editMenu->addSeparator();
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addSeparator();
    editMenu->addAction(findAndReplaceAction);

    //add helpMenu actions
    helpMenu->addAction(helpAction);
}

void MenuBar::setupSignalsAndSlots() {
    //fileMenu actions
    connect(newAction, &QAction::triggered, this, &MenuBar::newActionTriggerred);
    connect(openAction, &QAction::triggered, this, &MenuBar::openActionTriggerred);
    connect(saveAction, &QAction::triggered, this, &MenuBar::saveActionTriggerred);
    connect(saveAsAction, &QAction::triggered, this, &MenuBar::saveAsActionTriggerred);
    connect(exitAction, &QAction::triggered, this, [=]{ QCoreApplication::quit(); });

    connect(undoAction, &QAction::triggered, this, &MenuBar::undoActionTriggerred);
    connect(cutAction, &QAction::triggered, this, &MenuBar::cutActionTriggerred);
    connect(copyAction, &QAction::triggered, this, &MenuBar::copyActionTriggerred);
    connect(pasteAction, &QAction::triggered, this, &MenuBar::pasteActionTriggerred);
    connect(findAndReplaceAction, &QAction::triggered, this, &MenuBar::findAndReplaceActionTriggerred);
}

void MenuBar::newActionTriggerred() {
    if(mainWindow->getTextBox()->wasTextChanged())
    {
        QMessageBox messageBox(mainWindow);
        messageBox.setWindowTitle("Warning");
        messageBox.setText("Changes in text were not saved. Do you want to save them?");
        messageBox.setStandardButtons(QMessageBox::StandardButton::Yes | QMessageBox::StandardButton::No);
        messageBox.setDefaultButton(QMessageBox::StandardButton::Yes);

        if(messageBox.exec() == QMessageBox::StandardButton::Yes)
            mainWindow->getTextBox()->saveCurrentFileContent();
    }

    mainWindow->getTextBox()->setText("");
}

void MenuBar::openActionTriggerred() {
    mainWindow->getTextBox()->showFileContent();
}

void MenuBar::saveActionTriggerred() {
    mainWindow->getTextBox()->saveCurrentFileContent();
}

void MenuBar::saveAsActionTriggerred() {
    mainWindow->getTextBox()->saveTextAsFile();
}

void MenuBar::undoActionTriggerred() {
    mainWindow->getTextBox()->undo();
}

void MenuBar::cutActionTriggerred() {
    mainWindow->getTextBox()->cut();
}

void MenuBar::copyActionTriggerred() {
    mainWindow->getTextBox()->copy();
}

void MenuBar::pasteActionTriggerred() {
    mainWindow->getTextBox()->paste();
}

void MenuBar::findAndReplaceActionTriggerred() {
    findAndReplaceWindow = new FindAndReplace(mainWindow);
    findAndReplaceWindow->show();
}

void MenuBar::helpActionTriggerred() {
    QMessageBox::information(mainWindow, "About", "Notepad-like application developed using C++ and Qt framework.");
}

MenuBar::~MenuBar() {
    delete newAction;
    delete openAction;
    delete saveAction;
    delete saveAsAction;
    delete exitAction;
    delete helpAction;
    delete findAndReplaceWindow;
}
