#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QMainWindow>
#include "FindAndReplace.h"

class MainWindow;

class MenuBar : public QMenuBar
{
    Q_OBJECT
private:

    //Pointer to main window
    MainWindow* mainWindow;

    //Menus
    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* helpMenu;

    //fileMenu actions
    QAction* newAction;
    QAction* openAction;
    QAction* saveAction;
    QAction* saveAsAction;
    QAction* exitAction;

    //editMenu actions
    QAction* undoAction;
    QAction* cutAction;
    QAction* copyAction;
    QAction* pasteAction;
    QAction* findAndReplaceAction;

    //helpMenu actions
    QAction* helpAction;

    FindAndReplace* findAndReplaceWindow;

    /**
     * Adds actions to appropriate menus and sets shortcuts to them.
    */
    void setupMenus();

    /**
     * Sets up signals and slots for corresponding actions.
    */
    void setupSignalsAndSlots();

public:
    MenuBar(QMainWindow* mainWindow);
    ~MenuBar();

    //Slots

    /**
     * Invoked when "New" action in "File" menu is triggerred.
    */
    void newActionTriggerred();

    /**
     * Invoked when "Open" action in "File" menu is triggerred.
    */
    void openActionTriggerred();

    /**
     * Invoked when "Save" action in "File" menu is triggerred.
    */
    void saveActionTriggerred();

    /**
     * Invoked when "Save as" action in "File" menu is triggerred.
    */
    void saveAsActionTriggerred();

    /**
     * Invoked when "Undo" action in "Edit" menu is triggerred.
    */
    void undoActionTriggerred();

    /**
     * Invoked when "Cut" action in "Edit" menu is triggerred.
    */
    void cutActionTriggerred();

    /**
     * Invoked when "Copy" action in "Edit" menu is triggerred.
    */
    void copyActionTriggerred();

    /**
     * Invoked when "Paste" action in "Edit" menu is triggerred.
    */
    void pasteActionTriggerred();

    /**
     * Invoked when "Find and replace" action in "Edit" menu is triggerred.
    */
    void findAndReplaceActionTriggerred();

    /**
     * Invoked when "Help" action in "Help" menu is triggerred.
    */
    void helpActionTriggerred();
};

#endif // MENUBAR_H
