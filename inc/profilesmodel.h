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
* Description: Profiles model for profiles widget
*
*/

#ifndef PROFILESMODEL_H
#define PROFILESMODEL_H

// System includes
#include <QObject>

// Forward declarations
class ProfilesModelPrivate;

// Class declaration
class ProfilesModel : public QObject
{
public:
	ProfilesModel(QObject *parent = 0);
    ~ProfilesModel();
    int activeProfileId();
    int activateProfile(int profileId);
    QString activeProfileName();
    
private:
    Q_DISABLE_COPY(ProfilesModel)
    
private:
	ProfilesModelPrivate *dptr;
};

#endif  //PROFILESMODEL_H
