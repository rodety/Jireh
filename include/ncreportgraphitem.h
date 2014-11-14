/****************************************************************************
* 
*  Copyright (C) 2002-2008 Helta Kft. / NociSoft Software Solutions
*  All rights reserved.
*  Author: Norbert Szabo
*  E-mail: nszabo@helta.hu, info@nocisoft.com
*  Web: www.nocisoft.com
* 
*  This file is part of the NCReport reporting software
* 
*  Licensees holding a valid NCReport License Agreement may use this
*  file in accordance with the rights, responsibilities, and obligations
*  contained therein. Please consult your licensing agreement or contact
*  nszabo@helta.hu if any conditions of this licensing are not clear
*  to you.
* 
*  This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
*  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
****************************************************************************/
#ifndef NCREPORTGRAPHITEM_H
#define NCREPORTGRAPHITEM_H

#include "ncreportitem.h"

class NCReportDef;
class NCReportEvaluator;
class NCReportDataSource;

/*!
Graph or custom item's data class
 */
class NCReportGraphData : public NCReportItemData
{
public:
	NCReportGraphData()
	{}
	
	QString graphDefinition;
	QString classID;
    //NCReportDataSource* dataSource;
};

/*!
Graph or custom item class
 */
class NCReportGraphItem : public NCReportItem
{
public:
	NCReportGraphItem( NCReportDef* rdef, QGraphicsItem* parent =0);
 	~NCReportGraphItem();
	//QRectF boundingRect() const;
	int type() const;
	void adjustSize();
	void adjustSize( NCReportOutput* );
	bool read( NCReportXMLReader* );
	bool write( NCReportXMLWriter* );
	void setDefaultForEditor();
	void paint( NCReportOutput*, const QPointF& );
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	inline QString graphDefinition() const
	{ return ((NCReportGraphData*)d)->graphDefinition; }

	inline void setGraphDefinition( const QString& gd )
	{ ((NCReportGraphData*)d)->graphDefinition = gd; }

	inline QString classID() const
	{ return ((NCReportGraphData*)d)->classID; }

	inline void setClassID( const QString& id )
	{ ((NCReportGraphData*)d)->classID = id; }

//    inline void setDataSource(NCReportDataSource *ds)
//    { ((NCReportGraphData*)d)->dataSource = ds; }

//    NCReportDataSource *dataSource() const
//    { return ((NCReportGraphData*)d)->dataSource; }

	void updateValue(NCReportEvaluator *);
};


#endif
