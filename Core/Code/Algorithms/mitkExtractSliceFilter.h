/*=========================================================================
 
Program:   Medical Imaging & Interaction Toolkit
Language:  C++
Date:      $Date$
Version:   $Revision: $
 
Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.
 
This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.
 
=========================================================================*/

#ifndef mitkExtractSliceFilter_h_Included
#define mitkExtractSliceFilter_h_Included


#include "MitkExports.h"
#include "mitkImageToImageFilter.h"
#include <vtkSmartPointer.h>

#include <vtkImageReslice.h>
#include <vtkMatrix4x4.h>

namespace mitk
{
	/**
	*	\brief ExtractSliceFilter extracts a 2D abitrary oriented slice from a 3D volume.
	*	
	*/
	class MITK_CORE_EXPORT ExtractSliceFilter : public ImageToImageFilter
	{
	public:

		mitkClassMacro(ExtractSliceFilter, ImageToImageFilter);
		itkNewMacro(ExtractSliceFilter);

		void SetWorldGeometry(const Geometry2D* geometry ){ this->m_WorldGeometry = geometry; this->Modified(); }

		void SetTimeStep( unsigned int timestep){ this->m_TimeStep = timestep; }
		unsigned int GetTimeStep(){ return this->m_TimeStep; }

		vtkMatrix4x4* GetResliceAxes(){
			return this->m_Reslicer->GetResliceAxes();
		}

		enum ResliceInterpolation { RESLICE_NEAREST, RESLICE_LINEAR, RESLICE_CUBIC };
		
		void SetInterPolationMode( ExtractSliceFilter::ResliceInterpolation interpolation){ this->interpolationMode = interpolation; }

	protected:
		ExtractSliceFilter();
		virtual ~ExtractSliceFilter();

		virtual void GenerateData();

		const Geometry2D* m_WorldGeometry;
		vtkSmartPointer<vtkImageReslice> m_Reslicer;

		unsigned int m_TimeStep;

		ResliceInterpolation interpolationMode;
	};
}

#endif // mitkExtractSliceFilter_h_Included