#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QStatusBar>
#include <QLabel>
#include <QMainWindow>
#include <QTextCursor>

class MainWindow;

class StatusBar : public QStatusBar
{
private:
    MainWindow* mainWindow;

    //This label contains name of the current file which is viewed in TextBox.
    QLabel* currentFileName;

    //This label contains position of the cursor in TextBox..
    QLabel* cursorPosition;

public:
    StatusBar(QMainWindow* parent);
    ~StatusBar();

    /**
     * Changes the text in currentFileName label to this contained in newFileName QString object.
     * @param newFileName - name of the file which is viewed in textBox.
    */
    void updateFileName(QString newFileName);

    /**
     * Changes the text in cursorPositipn label to other coordinates of the cursor in TextBox.
     * @param x - x coordinate of cursor in TextBox.
     * @param y - y coordinate of cursor in TextBox.
    */
    void updateCursorPosition(int x, int y);
};

#endif // STATUSBAR_H
