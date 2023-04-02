#include <QDebug>
#include "Toolbar.h"
#include "MainWindow.h"


ToolBar::ToolBar(QMainWindow *parent)
    : QToolBar(parent) {

    mainWindow = dynamic_cast<MainWindow*>(parent);

    newAction = new QAction("New", this);
    openAction = new QAction("Open", this);
    saveAction = new QAction("Save", this);
    saveAsAction = new QAction("Save As", this);

    fontSizeLabel = new QLabel("Font size:", this);
    fontSizeSelector = new QSpinBox(this);

    textColorLabel = new QLabel("Text color: ");
    colorList = new QComboBox(this);

    setupToolBar();
    setupSignalsAndSlots();
}

void ToolBar::setupToolBar() {
    this->addAction(newAction);
    this->addAction(openAction);
    this->addAction(saveAction);
    this->addAction(saveAsAction);

    this->addSeparator();
    this->addWidget(fontSizeLabel);
    this->addWidget(fontSizeSelector);
    this->addSeparator();
    this->addWidget(textColorLabel);
    this->addWidget(colorList);

    fontSizeSelector->setValue(20);
    fontSizeSelector->setRange(0, 50);

    colorList->addItem("Black");
    colorList->addItem("White");
    colorList->addItem("Red");
    colorList->addItem("Green");
    colorList->addItem("Blue");
    colorList->addItem("Cyan");
    colorList->addItem("Magenta");
    colorList->addItem("Yellow");
    colorList->addItem("Gray");
}

void ToolBar::setupSignalsAndSlots() {
    connect(newAction, &QAction::triggered, this, &ToolBar::newActionTriggerred);
    connect(openAction, &QAction::triggered, this, &ToolBar::openActionTriggerred);
    connect(saveAction, &QAction::triggered, this, &ToolBar::saveActionTriggerred);
    connect(saveAsAction, &QAction::triggered, this, &ToolBar::saveAsActionTriggerred);
    connect(fontSizeSelector, &QSpinBox::valueChanged, this, &ToolBar::fontSizeChanged);
    connect(colorList, &QComboBox::currentTextChanged, this, &ToolBar::fontColorChanged);
    //connect(fontSizeSelector, &QSpinBox::textChanged, this, &ToolBar::fontSizeChanged);
}

void ToolBar::newActionTriggerred() {
    mainWindow->getMenuBar()->newActionTriggerred();
}

void ToolBar::openActionTriggerred() {
    mainWindow->getTextBox()->showFileContent();
}

void ToolBar::saveActionTriggerred() {
    mainWindow->getTextBox()->saveCurrentFileContent();
}

void ToolBar::saveAsActionTriggerred() {
    mainWindow->getTextBox()->saveTextAsFile();
}

void ToolBar::fontSizeChanged() {
    mainWindow->getTextBox()->setFontPointSize(this->fontSizeSelector->value());
}

void ToolBar::fontColorChanged(QString currentText) {
    if(currentText.compare("Black") == 0)
        mainWindow->getTextBox()->setTextColor(QColor(QColorConstants::Black));
    else if(currentText.compare("White") == 0)
        mainWindow->getTextBox()->setTextColor(QColor(QColorConstants::White));
    else if(currentText.compare("Red") == 0)
        mainWindow->getTextBox()->setTextColor(QColor(QColorConstants::Red));
    else if(currentText.compare("Green") == 0)
        mainWindow->getTextBox()->setTextColor(QColor(QColorConstants::Green));
    else if(currentText.compare("Blue") == 0)
        mainWindow->getTextBox()->setTextColor(QColor(QColorConstants::Blue));
    else if(currentText.compare("Cyan") == 0)
        mainWindow->getTextBox()->setTextColor(QColor(QColorConstants::Cyan));
    else if(currentText.compare("Magenta") == 0)
        mainWindow->getTextBox()->setTextColor(QColor(QColorConstants::Magenta));
    else if(currentText.compare("Yellow") == 0)
        mainWindow->getTextBox()->setTextColor(QColor(QColorConstants::Yellow));
    else if(currentText.compare("Gray") == 0)
        mainWindow->getTextBox()->setTextColor(QColor(QColorConstants::Gray));
}
