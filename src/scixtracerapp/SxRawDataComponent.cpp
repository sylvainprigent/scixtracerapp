/// \file SxRawDataComponent.cpp
/// \brief SxRawDataComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxRawDataComponent.h"
#include "SxRawDataStates.h"

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
    SxRawData* data = m_container->get_rawdata();
    data->set_name(m_nameEdit->text());
    data->set_format(new SxFormat(m_formatEdit->text()));
    data->set_date(new SxDate(m_dateEdit->text()));
    data->set_author(new SxUser(m_authorEdit->text()));

    /// \todo implement tags widget
    //for key in self.tagWidgets:
    //    self.container.rawdata.metadata.tags[key] = self.tagWidgets[key].text()

    m_container->send(SxRawDataStates::SaveClicked);
}

void SxRawDataComponent::update(SxfAction* action)
{
    if (action->state() == SxRawDataStates::Loaded)
    {
        // metadata
        m_nameEdit->setText(m_container->get_rawdata()->get_name());
        m_formatEdit->setText(m_container->get_rawdata()->get_format()->get_name());
        m_dateEdit->setText(m_container->get_rawdata()->get_date()->get_to_string("YYYY-MM-DD"));
        m_authorEdit->setText(m_container->get_rawdata()->get_author()->get_username());
        m_uriEdit->setText(m_container->get_rawdata()->get_md_uri());

        // tags
        for(int i = m_tagsLayout->count()-1 ; i >= 0 ; --i)
        {
            m_tagsLayout->itemAt(i)->widget()->deleteLater();
        }
        m_tagWidgets.clear();
        int row_idx = -1;
        SxTags* tags = m_container->get_rawdata()->get_tags();   
        QStringList keys = tags->get_keys();
        for (int i = 0 ; i < tags->get_count() ; ++i)
        {
            QLabel* label = new QLabel(keys[i]);
            QLineEdit* edit = new QLineEdit(tags->get_tag(keys[i]));
            row_idx += 1;
            m_tagsLayout->addWidget(label, row_idx, 0);
            m_tagsLayout->addWidget(edit, row_idx, 1); 
            m_tagWidgets[keys[i]] = edit;
        }
    }

    if (action->state() == SxRawDataStates::Saved)
    {
        QMessageBox msgBox;
        msgBox.setText("Metadata have been saved.");
        msgBox.exec();
    }

}          

QWidget* SxRawDataComponent::getWidget()
{
    return m_widget;  
}