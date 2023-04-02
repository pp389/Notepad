#ifndef FINDANDREPLACE_H
#define FINDANDREPLACE_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>

class MainWindow;

/**
* Represents a window which provides 'find and replace' function.
*/
class FindAndReplace : public QDialog
{
    Q_OBJECT
private:
    QHBoxLayout* layout;
    QLabel* findLabel;
    QLabel* replaceWithLabel;
    QLineEdit* stringToBeFound;
    QLineEdit* newString;
    QPushButton* findAndReplaceButton;

    MainWindow* mainWindow;

    /**
    * Finds a string given in the 'stringToBeFound' QLineEdit in the main window's text box and
    * replaces all of its occurences with string given in 'newString' QLineEdit.
    */
    void findAndReplace();

public:
    explicit FindAndReplace(QWidget *parent = nullptr);
    ~FindAndReplace();

};

#endif // FINDANDREPLACE_H
