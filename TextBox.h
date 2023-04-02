#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <QTextEdit>
#include <QFile>
#include <QMainWindow>

class MainWindow;

class TextBox : public QTextEdit
{
    Q_OBJECT
private:
    //File which content is shown in text box.
    QFile currentFile;

    QWidget* parentWidget;
    MainWindow* mainWindow;

    //"true" if the current file was not saved, "false" otherwise
    bool notSaved;

    //"true" if the current text in TextBox was changed
    bool textChanged;

    /**
     * Invoked when text in TextBox was changed.
    */
    void onTextChanged();

    /**
     * Invoked when cursor position in TextBox was changed.
    */
    void onCursorPositionChanged();


public:
    TextBox(QWidget* parent, QMainWindow* mWindow);
    ~TextBox();

    /**
     * Returns state of the "textChanged" variable.
     * @return true if text in TextBox was changed, false otherwise
    */
    bool wasTextChanged() const { return textChanged; };

    /**
     * Shows content of file in TextBox.
    */
    void showFileContent();

    /**
     * Saves content of TextBox to current file which is being edited.
    */
    void saveCurrentFileContent();

    /**
     * Saves text in TextBox as file.
    */
    void saveTextAsFile();
};

#endif // TEXTBOX_H
