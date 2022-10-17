#ifndef RENAMEPAGE_H
#define RENAMEPAGE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class RenamePage; }
QT_END_NAMESPACE

class RenamePage : public QWidget
{
    Q_OBJECT
    int file_nums = 0;
    std::vector<std::string> file_names;
    std::string content_search;
    std::string content_replace;
    std::string content_regex;

public:
    RenamePage(QWidget *parent = nullptr);
    void FileNamesInput(std::vector<std::string> names);
    ~RenamePage();

private:
    Ui::RenamePage *ui;
    void reformat_names();
    void exit();
};
#endif // RENAMEPAGE_H
