/// \file SxProcessedDataComponent.cpp
/// \brief SxProcessedDataComponent class
/// \author Sylvain Prigent
/// \version 0.1
/// \date 2021

#include "SxProcessedDataComponent.h"
#include "SxProcessedDataStates.h"

SxProcessedDataComponent::SxProcessedDataComponent(SxProcessedDataContainer* container) : SxfComponent()
{
    m_objectName = "SxProcessedDataComponent";
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
    m_uriEdit = new QLineEdit();
    m_uriEdit->setReadOnly(true);

    QLabel* nameLabel = new QLabel("Name");
    m_nameEdit = new QLineEdit();
    m_nameEdit->setReadOnly(true);

    QLabel* authorLabel = new QLabel("Author");
    m_authorEdit = new QLineEdit();
    m_authorEdit->setReadOnly(true);

    QLabel* dateLabel = new QLabel("Date");
    m_dateEdit = new QLineEdit();
    m_dateEdit->setReadOnly(true);

    QLabel* formatLabel = new QLabel("Format");
    m_formatEdit = new QLineEdit();
    m_formatEdit->setReadOnly(true);

    QLabel* outlabelLabel = new QLabel("Label");
    m_outlabelEdit = new QLineEdit();
    m_outlabelEdit->setReadOnly(true);

    QLabel* originLabel = new QLabel("Parent");
    m_originEdit = new QLineEdit();
    m_originEdit->setReadOnly(true);

    QLabel* runLabel = new QLabel("Run");
    QPushButton* runButton = new QPushButton("Show info");
    runButton->setObjectName("btnDefault");
    connect(runButton, SIGNAL(released()), this, SLOT(emitRun()));

    QLabel* descLabel = new QLabel("Description");
    descLabel->setObjectName("SxMetadataTitle");
    QLabel* tagsLabel = new QLabel("Tags");
    tagsLabel->setObjectName("SxMetadataTitle");
    QLabel* originTitleLabel = new QLabel("Origin");
    originTitleLabel->setObjectName("SxMetadataTitle");

    QWidget* tagsWidget = new QWidget();
    m_tagsLayout = new QGridLayout();
    m_tagsLayout->setContentsMargins(0,0,0,0);
    tagsWidget->setLayout(m_tagsLayout);

        layout->addWidget(descLabel, 0, 0, 1, 2, Qt::AlignTop);
        layout->addWidget(uriLabel, 1, 0, Qt::AlignTop);
        layout->addWidget(m_uriEdit, 1, 1, Qt::AlignTop);
        layout->addWidget(nameLabel, 2, 0, Qt::AlignTop);
        layout->addWidget(m_nameEdit, 2, 1, Qt::AlignTop);
        layout->addWidget(formatLabel, 3, 0, Qt::AlignTop);
        layout->addWidget(m_formatEdit, 3, 1, Qt::AlignTop);
        layout->addWidget(dateLabel, 4, 0, Qt::AlignTop);
        layout->addWidget(m_dateEdit, 4, 1, Qt::AlignTop);
        layout->addWidget(authorLabel, 5, 0, Qt::AlignTop);
        layout->addWidget(m_authorEdit, 5, 1, Qt::AlignTop);
        layout->addWidget(tagsLabel, 6, 0, 1, 2, Qt::AlignTop);
        layout->addWidget(outlabelLabel, 7, 0, Qt::AlignTop);
        layout->addWidget(m_outlabelEdit, 7, 1, Qt::AlignTop);
        layout->addWidget(tagsWidget, 8, 0, 1, 2, Qt::AlignTop);
        layout->addWidget(originTitleLabel, 9, 0, 1, 2, Qt::AlignTop);
        layout->addWidget(originLabel, 10, 0, Qt::AlignTop);
        layout->addWidget(m_originEdit, 10, 1, Qt::AlignTop);
        layout->addWidget(runLabel, 11, 0, Qt::AlignTop);
        layout->addWidget(runButton, 11, 1, Qt::AlignTop);
        layout->addWidget(new QWidget(), 12, 0, 1, 2, Qt::AlignTop);
        layout->setAlignment(Qt::AlignTop);
}

void SxProcessedDataComponent::emitRun()
{
    m_container->send(SxProcessedDataStates::RunOpenClicked);
}

void SxProcessedDataComponent::update(SxfAction* action)
{
    if (action->state() == SxProcessedDataStates::Loaded)
    {
        SxProcessedData* metadata = m_container->get_processeddata();

        m_uriEdit->setText(metadata->get_uri());
        m_nameEdit->setText(metadata->get_name());
        m_authorEdit->setText(metadata->get_author()->get_username());
        m_dateEdit->setText(metadata->get_date()->get_to_string("YYYY-MM-DD"));
        m_formatEdit->setText(metadata->get_format()->get_name());
        m_outlabelEdit->setText(metadata->get_run_output()->get_label());

        // tags
        SxRawData* origin = SxServices::request()->get_origin(metadata->get_md_uri());
        if (origin)
        {
            for(int i = m_tagsLayout->count()-1 ; i >= 0 ; --i)
            {
                m_tagsLayout->itemAt(i)->widget()->deleteLater();
            }
            m_tagWidgets.clear();
            int row_idx = -1;

            SxTags* tags = origin->get_tags();   
            QStringList keys = tags->get_keys();
            for (int i = 0 ; i < tags->get_count() ; ++i)
            {
                QLabel* label = new QLabel(keys[i]);
                QLineEdit* edit = new QLineEdit(tags->get_tag(keys[i]));
                edit->setReadOnly(true);
                row_idx += 1;
                m_tagsLayout->addWidget(label, row_idx, 0);
                m_tagsLayout->addWidget(edit, row_idx, 1); 
                m_tagWidgets[keys[i]] = edit;
            }
        }

        SxData* parent = SxServices::request()->get_parent(metadata->get_md_uri());
        if (parent){
            m_originEdit->setText(parent->get_name());
        }
        else{
            m_originEdit->setText("");  
        }  
    }

}

QWidget* SxProcessedDataComponent::getWidget()
{
    return m_widget;
}  