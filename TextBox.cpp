#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include "TextBox.h"
#include "MainWindow.h"

TextBox::TextBox(QWidget* parent, QMainWindow* mWindow)
    : QTextEdit(parent) {
    parentWidget = parent;
    notSaved = true;
    textChanged = false;
    mainWindow = dynamic_cast<MainWindow*>(mWindow);

    this->setFontPointSize(20);
    //mainWindow->getToolBar()->getFontSizeSelector()->setValue(this->fontPointSize());

    connect(this, &QTextEdit::textChanged, this, &TextBox::onTextChanged);
    connect(this, &QTextEdit::cursorPositionChanged, this, &TextBox::onCursorPositionChanged);
}

void TextBox::onTextChanged() {
    textChanged = true;
}

void TextBox::showFileContent() {
    QString fileName = QFileDialog::getOpenFileName(parentWidget, "Open file...", QString(), "Text files (*.txt)");

    currentFile.close();
    currentFile.setFileName(fileName);
    if(currentFile.open(QFile::OpenModeFlag::Text | QFile::OpenModeFlag::ReadWrite))
    {
        QTextStream textStream(&currentFile);
        this->setPlainText(textStream.readAll());
    }
    else
        QMessageBox::critical(parentWidget, "Error", "Unable to open file " + fileName);

    notSaved = false;

    mainWindow->getStatusBar()->updateFileName(fileName);

    currentFile.close();
}

void TextBox::saveCurrentFileContent() {
    if(notSaved) {
        saveTextAsFile();
        return;
    }

    if(!currentFile.open(QFile::OpenModeFlag::WriteOnly | QFile::OpenModeFlag::Truncate)) {
        QMessageBox::critical(parentWidget, "Error", "Unable to open file " + currentFile.fileName());
        return;
    }

    QTextStream textStream(&currentFile);
    textStream << this->toPlainText();

    notSaved = false;

    mainWindow->getStatusBar()->updateFileName(currentFile.fileName());

    currentFile.close();
}

void TextBox::saveTextAsFile() {
    QString fileName = QFileDialog::getSaveFileName(parentWidget, "Save as...", QString(), "Text files (*.txt)");
    currentFile.close();
    currentFile.setFileName(fileName);
    if(currentFile.open(QFile::OpenModeFlag::Text | QFile::OpenModeFlag::ReadWrite))
    {
        QTextStream textStream(&currentFile);
        textStream << this->toPlainText();
    }
    else
        QMessageBox::critical(parentWidget, "Error", "Unable to open file " + fileName);

    notSaved = false;

    mainWindow->getStatusBar()->updateFileName(fileName);

    currentFile.close();
}

void TextBox::onCursorPositionChanged() {
    int x = this->textCursor().blockNumber(), y = this->textCursor().positionInBlock();
    mainWindow->getStatusBar()->updateCursorPosition(x, y);
}

TextBox::~TextBox() {
    currentFile.close();
}
