#include "rename-page.h"
#include "ui_rename-page.h"

#include <thread>
#include <QStandardItemModel>
#include <QMessageBox>

RenamePage::RenamePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RenamePage)
{
    ui->setupUi(this);
    ui->edit_search->setPlaceholderText("match text content");
    ui->edit_replace->setPlaceholderText("replace text content");
    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::tr("Original,Renamed").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);
    ui->names_table->setModel(model);
    ui->names_table->show();

    ui->button_cancel->clicked(this->close());

    connect(ui->button_rename, &QPushButton::clicked, this, &RenamePage::reformat_names);
    connect(ui->button_cancel, &QPushButton::clicked, this, &RenamePage::exit);
}

RenamePage::~RenamePage()
{
    delete ui;
}

void RenamePage::FileNamesInput(std::vector<std::string> names)
{
    file_names = names;
    file_nums = names.size();

    QStandardItemModel *model = (QStandardItemModel *)ui->names_table->model();
    for (int i=0;i<file_nums;i++) {
        model->setItem(i,0,new QStandardItem(names[i].c_str()));
    }
}

void RenamePage::reformat_names()
{
    std::string origin = ui->edit_search->text().toStdString();
    std::string replace = ui->edit_replace->text().toStdString();

    auto lambda_fun = [&](int i) -> void {
            auto match_begin = file_names[i].find(origin, 0);
            if (match_begin != std::string::npos){
                file_names[i].replace(match_begin, match_begin+(origin.size()-1), replace);
            }
    };

    for(int i = 0; i < file_nums; ++i){
        // QStandardItemModel *model = (QStandardItemModel *)ui->names_table->model();
        std::thread t(lambda_fun, i);
        t.join();
    }
    if (origin.size()==0){
        QMessageBox::StandardButton result;
        result = QMessageBox::critical(this, "Error","search content can't be empty", QMessageBox::Ok);
    } else {
        content_search = origin;
        content_replace = replace;
    }
    this->close();
}

void RenamePage::exit()
{
    this->close();
}
