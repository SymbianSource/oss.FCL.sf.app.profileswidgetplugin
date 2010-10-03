/*
* Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: Profiles widget
*
*/

// System includes
#include <HbPushButton>
#include <QGraphicsLinearLayout>
#include <HbStyle>
#include <HbDocumentLoader>
#include <HbFrameDrawer>
#include <QFontMetrics>

// User includes
#include "profileswidget.h"
#include "profileswidgetconsts.h"
#include "profilesmodel.h"
#include "profilesobserver.h"

/*!
    \class ProfilesWidget
    \implementation for home screen profiles widget
*/

/*!
    Constructor
*/
ProfilesWidget::ProfilesWidget(QGraphicsItem* parent, Qt::WindowFlags flags)
    : HbWidget(parent, flags),
      mButton(0),
      mModel(new ProfilesModel),
      mObserver(new ProfilesObserver(this))
{
    //QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget(this);
    QGraphicsLinearLayout *mainLayout = new QGraphicsLinearLayout(
        Qt::Vertical, this);
    
    // load the widget from .docml
    HbDocumentLoader loader; 
    bool ok = false; 
    loader.load(":/profileswidgetplugin", &ok); 
    if (!ok) {
        // fail to load .docml file
        return;
    }
    mButton = (HbPushButton *) loader.findWidget("pushButton");
    if (!mButton) {
        // fail to find push button
        return;
    }
    
    QString text = mModel->activeProfileName();
    mButton->setText(text);   
    adjustButtonWidth(text);
    HbFrameDrawer *background = new HbFrameDrawer("qtg_fr_hsshortcut_normal", 
            HbFrameDrawer::NinePieces);
    mButton->setFrameBackground(background);
    mainLayout->addItem(mButton);
    connect(mButton, SIGNAL(pressed()), this, SLOT(onButtonPressed()));    
    
    setLayout(mainLayout);
}

/*!
    Adjust button width according to text length
*/
void ProfilesWidget::adjustButtonWidth(const QString &text)
{ 
    HbFontSpec *sysFontSpec = new HbFontSpec(HbFontSpec::Secondary);
    QFont sysFont = sysFontSpec->font();
    QFontMetrics metrics( sysFont );

    int textWidth = 0;
    for (int i = 0; i < text.length(); i++) {
        textWidth += metrics.width(text.at(i));
    }
    mButton->setMaximumWidth((textWidth > ProfielsWidgetMinimumWidthInPx 
        ? textWidth : ProfielsWidgetMinimumWidthInPx) + 
                ProfilesWidgetWidthSpaceInPx);
    mButton->setMinimumWidth((textWidth > ProfielsWidgetMinimumWidthInPx 
        ? textWidth : ProfielsWidgetMinimumWidthInPx) + 
                ProfilesWidgetWidthSpaceInPx);
        
    delete sysFontSpec;
}

/*!
    Handle toggled event of button
*/
void ProfilesWidget::onButtonPressed()
{
    int profileId = mModel->activeProfileId();
    if (profileId != ProfilesWidgetGeneralProfileId) {
        mModel->activateProfile(ProfilesWidgetGeneralProfileId);
    } else {
        mModel->activateProfile(ProfilesWidgetMeetingProfileId);
    }

    QString text = mModel->activeProfileName();
    mButton->setText(text);
    adjustButtonWidth(text);
}

/*!
    Change icon of widget
*/
void ProfilesWidget::changeIcon()
{
    QString text = mModel->activeProfileName();
    mButton->setText(text);
    adjustButtonWidth(text);
}

/*!
    Destroyer
*/
ProfilesWidget::~ProfilesWidget()
{
    if (mModel) {
        delete mModel;
        mModel = NULL;
    }
}

/*!
    Return bounding rect
*/
QRectF ProfilesWidget::boundingRect() const
{
    return childrenBoundingRect();
}

/*!
    Return shape
*/
QPainterPath ProfilesWidget::shape() const
{   
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

/*!
    Called when widget is shown in the home screen
*/
void ProfilesWidget::onShow()
{
}

/*!
    Called when widget is hidden from the home screen
*/
void ProfilesWidget::onHide()
{
}
