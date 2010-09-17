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
* Description: Profiles widget plugin.
*
*/

// System includes
#include <e32base.h>
#include <MProfileEngineExtended.h>
#include <xqconversions.h>
#include <mprofilename.h>
#include <mprofile.h>

// User includes
#include "profilesmodel_p.h"
#include "profileswidgetconsts.h"

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
	ProfilesModelPrivate *self = new (ELeave)ProfilesModelPrivate();
    CleanupStack::PushL(self);
    self->ConstructL();
    CleanupStack::Pop(); //self
    return self;
}

/*!
   Constructor
*/
ProfilesModelPrivate::ProfilesModelPrivate()
{
    mEngine = NULL;
}

/*!
   ConstructL
*/
void ProfilesModelPrivate::ConstructL()
{
    mEngine = CreateProfileEngineExtendedL();
}

/*!
   Destroyer
*/
ProfilesModelPrivate::~ProfilesModelPrivate()
{
    mEngine->Release();
}

/*!
   Get the actived profile ID
*/
int ProfilesModelPrivate::activeProfileId()
{
    return mEngine->ActiveProfileId();
}

/*!
   Set active profile to specified ID
*/
int ProfilesModelPrivate::activateProfile(int profileId)
{
    TRAPD(err, mEngine->SetActiveProfileL(profileId));
    return err;
}

/*!
   Get actived profile name
*/
QString ProfilesModelPrivate::activeProfileName()
{
    MProfile *lProfile = mEngine->ActiveProfileL();
    CleanupReleasePushL(*lProfile);
     
    const MProfileName &lMProfileName = lProfile->ProfileName();
    TBuf<10> lProfileName = lMProfileName.Name();
    CleanupStack::PopAndDestroy();
    QString profileName = XQConversions::s60DescToQString(lProfileName);
    return profileName;
}
