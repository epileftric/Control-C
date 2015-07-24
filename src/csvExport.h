#ifndef TEXPLOTER_H
#define TEXPLOTER_H

#include <typedef.h>

#include <QTextStream>
#include <QObject>
#include <QTime>
#include <QFile>

class csvExport 
{
	public:
		csvExport(doubleVector *tb, doubleVector *R, uint p, doubleVector *X, uint n);
	private:
		QFile  File;
		QTextStream  stream;
		
};

#endif /* TEXPLOTER_H */ 
