/***************************************************************************
 *   Copyright (C) 2003-2004 by David Saxton                               *
 *   david@bluehaze.org                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef CCCS_H
#define CCCS_H

#include "element.h"

/**
CNodes n0 and n1 are used for the current control.
CNodes n2 and n3 are used for the current output.
Branches b0 and b1 are for control and output
@short Current Controlled Current Source
@author David Saxton
*/
class CCCS : public Element
{
public:
	CCCS( const double gain );
	virtual ~CCCS();

	virtual Type type() const override { return Element_CCCS; }
	void setGain( const double g );

protected:
	virtual void updateCurrents() override;
	virtual void add_initial_dc() override;

private:
	double m_g; // Conductance
};

#endif
