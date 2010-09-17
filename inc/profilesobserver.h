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

#ifndef PROFILESOBSERVER_H
#define PROFILESOBSERVER_H

// System includes
#include <QObject>

// Forward declarations
class ProfilesObserverPrivate;

// Class declaration
class ProfilesObserver : public QObject
{
public:
	ProfilesObserver(QObject *parent = 0);
    ~ProfilesObserver();
    
private:
    Q_DISABLE_COPY(ProfilesObserver)
    
private:
	ProfilesObserverPrivate *dptr;
};

#endif  //PROFILESOBSERVER_H
