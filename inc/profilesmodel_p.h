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
* Description: Profiles model private
*
*/

#ifndef PROFILESMODEL_P_H
#define PROFILESMODEL_P_H

// Forward declarations    
class MProfileEngineExtended;
class QString;

// Class declaration
class ProfilesModelPrivate
{
public:
    static ProfilesModelPrivate *NewL();
    ~ProfilesModelPrivate();
    int activeProfileId();
    int activateProfile(int profileId);
    QString activeProfileName();

private:
    ProfilesModelPrivate();
    void ConstructL();
    
private:
    MProfileEngineExtended *mEngine;
};

#endif  //PROFILESMODEL_P_H
