/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

#ifndef __qSlicerTerminologySelectorButton_h
#define __qSlicerTerminologySelectorButton_h

// Qt includes
#include <QPushButton>

// Terminologies includes
#include "qSlicerTerminologiesModuleWidgetsExport.h"

#include "qSlicerTerminologyNavigatorWidget.h"
#include "vtkSlicerTerminologyEntry.h"

class qSlicerTerminologySelectorButtonPrivate;

/// \brief Button that opens terminology selector dialog
/// \ingroup SlicerRt_QtModules_Terminologies_Widgets
class Q_SLICER_MODULE_TERMINOLOGIES_WIDGETS_EXPORT qSlicerTerminologySelectorButton : public QPushButton
{
  Q_OBJECT

public:
  explicit qSlicerTerminologySelectorButton(QWidget* parent=NULL);
  virtual ~qSlicerTerminologySelectorButton();

  /// Get selected terminology and other metadata (name, color, auto-generated flags) into given info bundle object
  void terminologyInfo(qSlicerTerminologyNavigatorWidget::TerminologyInfoBundle &terminologyInfo);

public slots:
  /// Set terminology and other metadata (name, color, auto-generated flags)
  void setTerminologyInfo(qSlicerTerminologyNavigatorWidget::TerminologyInfoBundle &terminologyInfo);

  /// Opens a terminology dialog to select a new terminology.
  void changeTerminology();

signals:
  void terminologyChanged();
  void canceled();

protected slots:
  void onToggled(bool toggled=true);

protected:
  virtual void paintEvent(QPaintEvent* event);

  QScopedPointer<qSlicerTerminologySelectorButtonPrivate> d_ptr;
private :
  Q_DECLARE_PRIVATE(qSlicerTerminologySelectorButton);
  Q_DISABLE_COPY(qSlicerTerminologySelectorButton);
};

#endif
