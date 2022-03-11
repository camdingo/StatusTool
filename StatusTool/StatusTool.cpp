﻿#include <QDebug>
#include <QStyleFactory>
#include <QApplication>
#include <QPalette>
#include <QFont>

#include "MainWindow.h"

//Dark Theme
void setStyle(QApplication* application)
{
	// set style
	application->setStyle(QStyleFactory::create("Fusion"));

	// increase font size for better reading
	QFont defaultFont = QApplication::font();
	defaultFont.setPointSize(defaultFont.pointSize() + 2);
	application->setFont(defaultFont);

	// modify palette to dark
	QPalette darkPalette;
	darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
	darkPalette.setColor(QPalette::WindowText, Qt::white);
	darkPalette.setColor(QPalette::Disabled, QPalette::WindowText, QColor(127, 127, 127));
	darkPalette.setColor(QPalette::Base, QColor(42, 42, 42));
	darkPalette.setColor(QPalette::AlternateBase, QColor(66, 66, 66));
	darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
	darkPalette.setColor(QPalette::ToolTipText, Qt::white);
	darkPalette.setColor(QPalette::Text, Qt::white);
	darkPalette.setColor(QPalette::Disabled, QPalette::Text, QColor(127, 127, 127));
	darkPalette.setColor(QPalette::Dark, QColor(35, 35, 35));
	darkPalette.setColor(QPalette::Shadow, QColor(20, 20, 20));
	darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
	darkPalette.setColor(QPalette::ButtonText, Qt::white);
	darkPalette.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(127, 127, 127));
	darkPalette.setColor(QPalette::BrightText, Qt::red);
	darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
	darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
	darkPalette.setColor(QPalette::Disabled, QPalette::Highlight, QColor(80, 80, 80));
	darkPalette.setColor(QPalette::HighlightedText, Qt::white);
	darkPalette.setColor(QPalette::Disabled, QPalette::HighlightedText, QColor(127, 127, 127));

	application->setPalette(darkPalette);

}

int main(int argc, char** argv)
{
	qDebug() << "Monitor Tool Starting.";

	QApplication app(argc, argv);

	QCoreApplication::setOrganizationName("Monitor Tool");
	QCoreApplication::setApplicationName("Monitor Tool");
	QCoreApplication::setApplicationVersion(QT_VERSION_STR);

	//TODO things to look up/ implement
	//find sam jacobs tool
	//right click open terminal on that machine
	// 
	// ini file 
	//	- hostnames to check (servers/workstations)
	//  - mount locations
	//  - thresholds (percentages in which to warn)
	//  - location of data server (to check for vcids/opgas)
	//  - 
	// 
	//
	MainWindow *mainWindow = new MainWindow();
	mainWindow->show();

	setStyle(&app);

	app.exec();

	return 0;
}
