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

#ifndef PROFILESWIDGET_H
#define PROFILESWIDGET_H

// System includes
#include <HbWidget>

// Forward declarations
class HbPushButton;
class ProfilesModel;
class ProfilesObserver;

// Class declaration
class ProfilesWidget : public HbWidget
{
    Q_OBJECT

public:
    ProfilesWidget(QGraphicsItem *parent = 0, Qt::WindowFlags flags = 0);
    ~ProfilesWidget();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void changeIcon();
    void adjustButtonWidth(const QString &text);

public slots:
    void onShow();
    void onHide();
    
private slots:
    void onButtonPressed();
    
private:
    Q_DISABLE_COPY(ProfilesWidget)
    HbPushButton *mButton;
    ProfilesModel *mModel;
    ProfilesObserver *mObserver;
};

#endif  //PROFILESWIDGET_H
