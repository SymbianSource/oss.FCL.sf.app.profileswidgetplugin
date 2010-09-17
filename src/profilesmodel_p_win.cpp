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
* Description: Profiles widget model
*
*/

// User includes
#include "profilesmodel_p.h"

/*!
    \class ProfilesModelPrivate
    \profiles widget model class

    This class is used to create profiles widget model
*/

// ======== MEMBER FUNCTIONS ========

/*!
   NewL
*/
ProfilesModelPrivate* ProfilesModelPrivate::NewL()
{
}

/*!
   Constructor
*/
ProfilesModelPrivate::ProfilesModelPrivate()
{
}

/*!
   ConstructL
*/
void ProfilesModelPrivate::ConstructL()
{
}

/*!
   Destroyer
*/
ProfilesModelPrivate::~ProfilesModelPrivate()
{

}

/*!
   Get the actived profile ID
*/
int ProfilesModelPrivate::activeProfileId()
{
    return 0;
}

/*!
   Set active profile to specified ID
*/
int ProfilesModelPrivate::activateProfile(int)
{
    return 0;
}

/*!
   Get actived profile name
*/
QString ProfilesModelPrivate::activeProfileName()
{
    return NULL;
}
