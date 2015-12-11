//
// Copyright (c) 2015 Singular Inversions Inc. (facegen.com)
// Use, modification and distribution is subject to the MIT License,
// see accompanying file LICENSE.txt or facegen.com/base_library_license.txt
//
// Authors:     Andrew Beatty
// Created:     Sept. 20, 2011
//

#ifndef FGGUIAPIDIALOGS_HPP
#define FGGUIAPIDIALOGS_HPP

#include "FgGuiApiBase.hpp"
#include "FgGuiApiButton.hpp"

void
fgGuiDialogMessage(
    const FgString & caption,
    const FgString & message);

FgOpt<FgString>
fgGuiDialogFileLoad(
    const FgString &            description,
    const vector<std::string> & extensions);

// The extension should be chosen in the GUI before calling this function:
FgOpt<FgString>
fgGuiDialogFileSave(
    const FgString &        description,
    const std::string &     extension);

FgOpt<FgString>
fgGuiDialogDirSelect();

// Arguments: true - advance progress bar, false - do not
// Return: true - user cancel, false - continue
typedef boost::function<bool(bool)>             FgGuiProgress;

typedef boost::function<void(FgGuiProgress)>    FgGuiActionProgress;

void
fgGuiDialogProgress(
    const FgString &        title,
    uint                    progressSteps,
    FgGuiActionProgress     actionProgress);

// Uses the embedded icon for the splash screen.
// Call the returned function to terminate the splash screen:
boost::function<void(void)>
fgGuiDialogSplashScreen();

#endif