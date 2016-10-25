/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/
#ifndef QMITK_COLORPROPERTYVIEW_H_INCLUDED
#define QMITK_COLORPROPERTYVIEW_H_INCLUDED

#include "MitkQtWidgetsExtExports.h"
#include <QLabel>
#include <mitkColorProperty.h>
#include <mitkPropertyObserver.h>

/// @ingroup Widgets
class MITKQTWIDGETSEXT_EXPORT QmitkColorPropertyView : public QLabel, public mitk::PropertyView
{
  Q_OBJECT

public:
  QmitkColorPropertyView(const mitk::ColorProperty *, QWidget *parent);
  virtual ~QmitkColorPropertyView();

protected:
  virtual void PropertyChanged() override;
  virtual void PropertyRemoved() override;

  void DisplayColor();

  const mitk::ColorProperty *m_ColorProperty;

  QPalette m_WidgetPalette;
};

#endif
