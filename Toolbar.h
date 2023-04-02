#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QMainWindow>
#include <QToolBar>
#include <QSpinBox>
#include <QLabel>
#include <QComboBox>

class MainWindow;

class ToolBar : public QToolBar
{
    Q_OBJECT

private:
    MainWindow* mainWindow;

    QAction* newAction;
    QAction* openAction;
    QAction* saveAction;
    QAction* saveAsAction;

    QLabel* fontSizeLabel;
    QSpinBox* fontSizeSelector;

    QLabel* textColorLabel;
    QComboBox* colorList;

    /**
     * Adds actions and widgets to ToolBar.
    */
    void setupToolBar();

    /**
     * Sets up signals and slots to action in ToolBar.
    */
    void setupSignalsAndSlots();

    //Slots

    /**
     * Invoked when "New" action in ToolBar is invoked.
    */
    void newActionTriggerred();

    /**
     * Invoked when "Open" action in ToolBar is invoked.
    */
    void openActionTriggerred();

    /**
     * Invoked when "Save" action in ToolBar is invoked.
    */
    void saveActionTriggerred();

    /**
     * Invoked when "Save as" action in ToolBar is invoked.
    */
    void saveAsActionTriggerred();

    /**
     * Invoked when value in "fontSizeSelector" object is changed.
    */
    void fontSizeChanged();

    /**
     * Invoked when text in "colorList" object is changed.
    */
    void fontColorChanged(QString currentText);

public:
    explicit ToolBar(QMainWindow *parent = nullptr);

    /**
     * Returns a pointer to "fonstSizeSelector" object.
    */
    QSpinBox* getFontSizeSelector() { return fontSizeSelector; }
};

#endif // TOOLBAR_H
