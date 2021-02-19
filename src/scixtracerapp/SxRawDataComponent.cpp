/// \file SxRawDataComponent.cpp
/// \brief SxRawDataComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxRawDataComponent.h"

SxRawDataComponent::SxRawDataComponent(SxRawDataContainer* container) : SxfComponent()
{
    m_objectName = "SxMetadataRawDataComponent";
    m_container = container;
    m_container->subscribe(this);

    m_widget = new QScrollArea();
    m_widget->setObjectName("SxWidget");
    m_widget->setWidgetResizable(true);
    m_widget->setMinimumWidth(150);

    QWidget* widget = new QWidget();
    widget->setAttribute(Qt::WA_StyledBackground, true);
    widget->setObjectName("SxSideBar");
    QGridLayout* layout = new QGridLayout();
    widget->setLayout(layout);
    m_widget->setWidget(widget);

    QLabel* uriLabel = new QLabel("URI");
    QLineEdit* m_uriEdit = new QLineEdit();
    m_uriEdit->setEnabled(false);

    QLabel* nameLabel = new QLabel("Name");
    m_nameEdit = new QLineEdit();

    QLabel* formatLabel = new QLabel("Format");
    QLineEdit* m_formatEdit = new QLineEdit();

    QLabel* dateLabel = new QLabel("Date");
    QLineEdit* m_dateEdit = new QLineEdit();

    QLabel* authorLabel = new QLabel("Author");
    QLineEdit* m_authorEdit = new QLineEdit();

    QWidget* tagsWidget = new QWidget();
    m_tagsLayout = new QGridLayout();
    m_tagsLayout->setContentsMargins(0,0,0,0);
    tagsWidget->setLayout(m_tagsLayout);

    QPushButton* saveButton = new QPushButton(m_widget->tr("Save"));
    saveButton->setObjectName("btnPrimary");
    connect(saveButton, SIGNAL(released()), this, SLOT(saveButtonClicked()));

    QLabel* descLabel = new QLabel("Description");
    descLabel->setObjectName("SxMetadataTitle");
    QLabel* tagsLabel = new QLabel("Tags");
    tagsLabel->setObjectName("SxMetadataTitle");

    layout->addWidget(descLabel, 0, 0, 1, 2);
    layout->addWidget(uriLabel, 1, 0);
    layout->addWidget(m_uriEdit, 1, 1);
    layout->addWidget(nameLabel, 2, 0);
    layout->addWidget(m_nameEdit, 2, 1);
    layout->addWidget(formatLabel, 3, 0);
    layout->addWidget(m_formatEdit, 3, 1);
    layout->addWidget(dateLabel, 4, 0);
    layout->addWidget(m_dateEdit, 4, 1);
    layout->addWidget(authorLabel, 5, 0);
    layout->addWidget(m_authorEdit, 5, 1);
    layout->addWidget(tagsLabel, 6, 0, 1, 2);
    layout->addWidget(tagsWidget, 7, 0, 1, 2);
    layout->addWidget(saveButton, 8, 0, 1, 2);
    layout->addWidget(new QWidget(), 9, 0, 1, 2, Qt::AlignTop);
    layout->setAlignment(Qt::AlignTop);
}

void SxRawDataComponent::saveButtonClicked()
{
    /*
        self.container.rawdata.metadata.name = self.nameEdit.text()
        self.container.rawdata.metadata.format = self.formatEdit.text()
        self.container.rawdata.metadata.date = self.dateEdit.text()
        self.container.rawdata.metadata.author = self.authorEdit.text()

        for key in self.tagWidgets:
            self.container.rawdata.metadata.tags[key] = self.tagWidgets[key].text()

        self.container.emit(BiRawDataStates.SaveClicked)
        */
}

void SxRawDataComponent::update(SxfAction* action)
{
    /*
        if action.state == BiRawDataStates.Loaded:
            self.nameEdit.setText(self.container.rawdata.metadata.name)
            self.formatEdit.setText(self.container.rawdata.metadata.format)
            self.dateEdit.setText(self.container.rawdata.metadata.date)
            self.authorEdit.setText(self.container.rawdata.metadata.author)
            self.uriEdit.setText(self.container.rawdata.metadata.uri)

            # tags
            for i in reversed(range(self.tagsLayout.count())): 
                self.tagsLayout.itemAt(i).widget().deleteLater()
            self.tagWidgets = {}
            row_idx = -1    
            for key in self.container.rawdata.metadata.tags:
                label = QLabel(key)
                edit = QLineEdit(self.container.rawdata.metadata.tags[key])
                row_idx += 1
                self.tagsLayout.addWidget(label, row_idx, 0) 
                self.tagsLayout.addWidget(edit, row_idx, 1)
                self.tagWidgets[key] = edit

        if action.state == BiRawDataStates.Saved:
            msgBox = QMessageBox()
            msgBox.setText("Metadata have been saved")
            msgBox.exec()  
            */
}          

QWidget* SxRawDataComponent::getWidget()
{
    return m_widget;  
}