/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "optix/PathTracerScene.h"
#include <QApplication>
#include <QDesktopWidget>

#include "window.h"

int main(int argc, char **argv)
{
	
	//////////////////////////////////////////////////////////////////////////
	//  Display debug information in console window.
	AllocConsole();
	FILE* pFile;
	freopen_s(&pFile,"CONOUT$","w+t",stdout);
	printf("demo starting...\n");
	//////////////////////////////////////////////////////////////////////////
	//Optix Init
	QTGLUTDisplay::init( argc, argv );
	// Process command line options
	unsigned int sqrt_num_samples = 1u;
	unsigned int width = 512u, height = 512u;
	unsigned int rr_begin_depth = 2u;
	unsigned int max_depth = 100u;
	float timeout = 10000.0f;
	PathTracerScene scene;
	scene.setNumSamples( sqrt_num_samples );
	scene.setDimensions( width, height );
	scene.setMaxDepth( max_depth);
	QTGLUTDisplay::setProgressiveDrawingTimeout(timeout);
	QTGLUTDisplay::setUseSRGB(true);
	QTGLUTDisplay::run( "Cornell Box Scene", &scene, QTGLUTDisplay::CDProgressive );
	//////////////////////////////////////////////////////////////////////////

    QApplication app(argc, argv);
    Window window(argc, argv);
    //window.resize(window.sizeHint());
	window.resize(800, 534);
    int desktopArea = QApplication::desktop()->width() *
                     QApplication::desktop()->height();
    int widgetArea = window.width() * window.height();
    if (((float)widgetArea / (float)desktopArea) < 0.75f)
        window.show();
    else
        window.showMaximized();
    return app.exec();
}
