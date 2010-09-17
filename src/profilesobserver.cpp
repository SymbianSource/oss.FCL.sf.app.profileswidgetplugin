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

// User includes
#include "profilesobserver.h"
#include "profilesobserver_p.h"

/*!
    \class ProfilesObserver
    \profiles widget observer

    This class is used to create profiles widget observer
*/

// ======== MEMBER FUNCTIONS ========

/*!
    Constructor
*/
ProfilesObserver::ProfilesObserver(QObject *parent/*= 0*/)
	: QObject(parent)
{
    QT_TRAP_THROWING(dptr = ProfilesObserverPrivate::NewL(parent));
}

/*!
    Destroyer
*/
ProfilesObserver::~ProfilesObserver()
{
    delete dptr;
}
