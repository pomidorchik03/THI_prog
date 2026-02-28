// #include "transport.h"
// #include <QVBoxLayout>

// AddEditFrom::AddEditFrom(QWidget *parent) : QWidget(parent)
// {
//     setWindowTitle("Test");
//     resize(400,300);

//     input = new QLineEdit(this);
//     result = new QLabel(this);
//     button = new QPushButton("Show",this);

//     input->setPlaceholderText("Enter text");

//     QVBoxLayout *mainLayout = new QVBoxLayout(this);
//     mainLayout->addWidget(input);
//     mainLayout->addWidget(result);
//     mainLayout->addWidget(button);

//     connect(button, &QPushButton::clicked, this, &AddEditFrom::show_text);
// }

// void AddEditFrom::show_text()
// {
//     QString entered = input->text();
//     result->setText(entered);
// }

