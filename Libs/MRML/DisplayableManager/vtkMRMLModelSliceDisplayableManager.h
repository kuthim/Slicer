/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Julien Finet, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

#ifndef __vtkMRMLModelSliceDisplayableManager_h
#define __vtkMRMLModelSliceDisplayableManager_h

// MRMLDisplayableManager includes
#include "vtkMRMLAbstractSliceViewDisplayableManager.h"
#include "vtkMRMLDisplayableManagerWin32Header.h"

class vtkMRMLDisplayableNode;
class vtkCutter;
class vtkProp;

/// \brief Displayable manager for slice (2D) views.
///
/// Responsible for any display on Slice views that is not the slice themselves
/// nor the annotations.
/// Currently support only glyph display for Diffusion Tensor volumes.
class VTK_MRML_DISPLAYABLEMANAGER_EXPORT vtkMRMLModelSliceDisplayableManager
  : public vtkMRMLAbstractSliceViewDisplayableManager
{

public:
  static vtkMRMLModelSliceDisplayableManager* New();
  vtkTypeMacro(vtkMRMLModelSliceDisplayableManager,
                       vtkMRMLAbstractSliceViewDisplayableManager);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  // DisplayableNode handling customizations
  void AddDisplayableNode(vtkMRMLDisplayableNode* displayableNode);
  void RemoveDisplayableNode(vtkMRMLDisplayableNode* displayableNode);

protected:

  vtkMRMLModelSliceDisplayableManager();
  virtual ~vtkMRMLModelSliceDisplayableManager();

  virtual void UnobserveMRMLScene() VTK_OVERRIDE;
  virtual void OnMRMLSceneNodeAdded(vtkMRMLNode* node) VTK_OVERRIDE;
  virtual void OnMRMLSceneNodeRemoved(vtkMRMLNode* node) VTK_OVERRIDE;
  virtual void ProcessMRMLNodesEvents(vtkObject* caller, unsigned long event, void* callData) VTK_OVERRIDE;

  virtual void UpdateFromMRML() VTK_OVERRIDE;
  virtual void OnMRMLSceneStartClose() VTK_OVERRIDE;
  virtual void OnMRMLSceneEndClose() VTK_OVERRIDE;
  virtual void OnMRMLSceneEndBatchProcess() VTK_OVERRIDE;

  /// Initialize the displayable manager based on its associated
  /// vtkMRMLSliceNode
  virtual void Create() VTK_OVERRIDE;
  int AddingDisplayableNode;

private:

  vtkMRMLModelSliceDisplayableManager(const vtkMRMLModelSliceDisplayableManager&);// Not implemented
  void operator=(const vtkMRMLModelSliceDisplayableManager&);                     // Not Implemented

  class vtkInternal;
  vtkInternal * Internal;
  friend class vtkInternal;

};

#endif
