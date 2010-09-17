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
#include <CProfileChangeNotifyHandler.h>

// User includes
#include "profilesobserver_p.h"
#include "profileswidget.h"

/*!
    \class ProfilesObserverPrivate
    \profiles observer class

    This class is used to create profiles observer
*/

// ======== MEMBER FUNCTIONS ========

/*!
   NewL
*/
ProfilesObserverPrivate* ProfilesObserverPrivate::NewL(QObject *parent)
{
	ProfilesObserverPrivate* self = new (ELeave) ProfilesObserverPrivate();
    CleanupStack::PushL(self);
    self->ConstructL(parent);
    CleanupStack::Pop(); //self
    return self;
}

/*!
   Constructor
*/
ProfilesObserverPrivate::ProfilesObserverPrivate()
{
}

/*!
   ConstructL
*/
void ProfilesObserverPrivate::ConstructL(QObject *parent)
{
    iHandler = CProfileChangeNotifyHandler::NewL(this);
    iParent = parent;
}

/*!
   Destroyer
*/
ProfilesObserverPrivate::~ProfilesObserverPrivate()
{
    if(iHandler) {
        delete iHandler;
        iHandler = NULL;
    }
}

/*!
   Handle the active profile events
*/
void ProfilesObserverPrivate::HandleActiveProfileEventL(
        TProfileEvent /*aProfileEvent*/,
        TInt /*aProfileId*/ )
{
    // handle event
    (reinterpret_cast<ProfilesWidget*>(iParent))->changeIcon();    
}
