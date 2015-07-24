#ifndef LABELLIST_H
#define LABELLIST_H

#include <PolyMat.h>

#include <QFormLayout>
#include <QLineEdit>
#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QList>


class LabelList : public QObject
{
	Q_OBJECT
	public:
		LabelList(QWidget*,QFormLayout *,QString );
		void changeSize(int);
		QStringList returnStrings(void);
		void setValues( complexVector &poles);
		
	private:
		QList<QLabel*> 	  label;
		QList<QLineEdit*> line;
		
		QWidget 	*parent;
		QFormLayout *layout;
		QString elementName;
		
		QString VEname(int i){
			return QString("<html><head/><body><p align=\"right\"><span style=\" font-size:12pt;\">%1</span><span style=\" font-size:12pt; vertical-align:sub;\">%2 = </span></p></body></html>").arg(elementName).arg(i);
		}
		QLabel* 	newQLabel(int i);
		QLineEdit* 	newQLineEdit(int i);
		
		
		
};

#endif /* LABELLIST_H */ 
