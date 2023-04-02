#include <QMessageBox>
#include "FindAndReplace.h"
#include "MainWindow.h"

FindAndReplace::FindAndReplace(QWidget *parent)
    : QDialog {parent} {

    mainWindow = dynamic_cast<MainWindow*>(parent);
    layout = new QHBoxLayout(this);
    findLabel = new QLabel("Find: ", this);
    replaceWithLabel = new QLabel("Replace with: ", this);
    stringToBeFound = new QLineEdit(this);
    newString = new QLineEdit(this);
    findAndReplaceButton = new QPushButton("Find and replace", this);

    layout->addWidget(findLabel);
    layout->addWidget(stringToBeFound);
    layout->addWidget(replaceWithLabel);
    layout->addWidget(newString);
    layout->addWidget(findAndReplaceButton);
    this->setLayout(layout);
    this->setWindowTitle("Find and replace...");

    connect(findAndReplaceButton, &QPushButton::clicked, this, &FindAndReplace::findAndReplace);
}

void FindAndReplace::findAndReplace() {
    QString stringToBeReplaced = stringToBeFound->text();
    QString newPhrase = newString->text();
    QString textInTextBox = mainWindow->getTextBox()->toPlainText();

    textInTextBox.replace(stringToBeReplaced, newPhrase);

    mainWindow->getTextBox()->setText(textInTextBox);
}

FindAndReplace::~FindAndReplace() {
    delete findLabel;
    delete replaceWithLabel;
    delete stringToBeFound;
    delete newString;
    delete findAndReplaceButton;
    delete layout;
}
