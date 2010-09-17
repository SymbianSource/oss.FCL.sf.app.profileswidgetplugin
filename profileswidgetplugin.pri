#
# Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
# All rights reserved.
# This component and the accompanying materials are made available
# under the terms of "Eclipse Public License v1.0"
# which accompanies this distribution, and is available
# at the URL "http://www.eclipse.org/legal/epl-v10.html".
#
# Initial Contributors:
# Nokia Corporation - initial contribution.
#
# Contributors:
#
# Description: Profiles widget
#

HEADERS += ./inc/*.h
SOURCES += src/profileswidgetplugin.cpp \
           src/profileswidget.cpp \
           src/profilesmodel.cpp \
           src/profilesobserver.cpp \
           
symbian : {
    SOURCES += src/profilesmodel_p_symbian.cpp \
            src/profilesobserver_p_symbian.cpp
}

win32 : {
    SOURCES += src/profilesmodel_p_win.cpp \
            src/profilesobserver_p_win.cpp
}