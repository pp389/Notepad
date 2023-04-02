#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QTextEdit>
#include "MenuBar.h"
#include "TextBox.h"
#include "StatusBar.h"
#include "Toolbar.h"

/**
 * MainWindow class represents main window of the application. It contains pointers to
 * its componets as the private fields.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    MenuBar* menuBar;

    /**
     * centralWidget is a parent widget for textBox and statusBar objects
    */
    QWidget* centralWidget;

    QVBoxLayout* centralWidgetLayout;
    TextBox* textBox;
    StatusBar* statusBar;
    ToolBar* toolBar;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /**
     * Returns a pointer to an TextBox object which belongs to MainWindow
     * @return pointer to TextBox object
    */

    TextBox* getTextBox() const { return textBox; }
    /**
     * Returns a pointer to an StatusBar object which belongs to MainWindow
     * @return pointer to StatusBar object
    */
    StatusBar* getStatusBar() const { return statusBar; }

    /**
     * Returns a pointer to an MenuBar object which belongs to MainWindow
     * @return pointer to MenuBar object
    */
    MenuBar* getMenuBar() const { return menuBar; }

    /**
     * Returns a pointer to an ToolBar object which belongs to MainWindow
     * @return pointer to ToolBar object
    */
    ToolBar* getToolBar() const { return toolBar; }
};
#endif // MAINWINDOW_H
