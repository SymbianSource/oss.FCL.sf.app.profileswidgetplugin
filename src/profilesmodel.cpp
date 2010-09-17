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
* Description: Profiles model
*
*/

// User includes
#include "profilesmodel.h"
#include "profilesmodel_p.h"
#include "profileswidgetconsts.h"

/*!
    \class ProfilesModelPrivate
    \profiles widget model class

    This class is used to create profiles widget model
*/

// ======== MEMBER FUNCTIONS ========

/*!
    Constructor
*/
ProfilesModel::ProfilesModel(QObject *parent/*= 0*/)
	: QObject(parent)
{
    QT_TRAP_THROWING(dptr = ProfilesModelPrivate::NewL());
}

/*!
    Destroyer
*/
ProfilesModel::~ProfilesModel()
{
    delete dptr;
}

/*!
   Get the actived profile ID
*/
int ProfilesModel::activeProfileId()
{
    return dptr->activeProfileId();
}

/*!
   Set active profile to specified ID
*/
int ProfilesModel::activateProfile(int profileId)
{
    return dptr->activateProfile(profileId);
}

/*!
   Get actived profile name
*/
QString ProfilesModel::activeProfileName()
{
    return dptr->activeProfileName();
}
