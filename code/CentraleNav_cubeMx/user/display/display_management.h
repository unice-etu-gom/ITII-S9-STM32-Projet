/*
 * display_management.h
 *
 *  Created on: 30 nov. 2019
 *      Author: gom
 */

#ifndef DISPLAY_DISPLAY_MANAGEMENT_H_
#define DISPLAY_DISPLAY_MANAGEMENT_H_

#include "TsDisplayView.h"

void    display_setView(const TsDisplayView*    pViewPtr);

void    display_repaint(void);

void    display_periodicUiUpdate(void);
void    display_touchscreen_poll(void);


#endif /* DISPLAY_DISPLAY_MANAGEMENT_H_ */
