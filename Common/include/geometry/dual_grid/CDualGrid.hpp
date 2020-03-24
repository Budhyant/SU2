/*!
 * \file CDualGrid.hpp
 * \brief Headers of the main subroutines for doing the complete dual grid structure.
 *        The subroutines and functions are in the <i>CDualGrid.cpp</i> file.
 * \author F. Palacios, T. Economon
 * \version 7.0.1 "Blackbird"
 *
 * SU2 Project Website: https://su2code.github.io
 *
 * The SU2 Project is maintained by the SU2 Foundation
 * (http://su2foundation.org)
 *
 * Copyright 2012-2019, SU2 Contributors (cf. AUTHORS.md)
 *
 * SU2 is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * SU2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with SU2. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <vector>

#include "../../CConfig.hpp"

/*!
 * \class CDualGrid
 * \brief Class for controlling the dual volume definition. The dual volume is compose by
 *        three main elements: points, edges, and vertices.
 * \author F. Palacios
 */
class CDualGrid{
protected:
  static unsigned short nDim; /*!< \brief Number of dimensions of the problem. */

public:

  /*!
   * \brief Constructor of the class.
   * \param[in] val_nDim - Number of dimensions of the problem.
   */
  CDualGrid(unsigned short val_nDim);

  /*!
   * \brief Destructor of the class.
   */
  virtual ~CDualGrid(void);

  /*!
   * \brief A pure virtual member.
   */
  virtual su2double *GetCoord(void) = 0;

  /*!
   * \brief A pure virtual member.
   * \param[in] val_coord - Coordinate of the point.
   */
  virtual void SetCoord(const su2double *val_coord) = 0;

  /*!
   * \brief A pure virtual member.
   * \param[in] val_coord_Edge_CG - Coordinates of the centre of gravity of the edge.
   * \param[in] val_coord_FaceElem_CG - Coordinates of the centre of gravity of the face of an element.
   * \param[in] val_coord_Elem_CG - Coordinates of the centre of gravity of the element.
   * \param[in] config - Definition of the particular problem.
   */
  virtual void SetNodes_Coord(su2double *val_coord_Edge_CG, su2double *val_coord_FaceElem_CG, su2double *val_coord_Elem_CG) = 0;

  /*!
   * \overload
   * \param[in] val_coord_Edge_CG - Coordinates of the centre of gravity of the edge.
   * \param[in] val_coord_Elem_CG - Coordinates of the centre of gravity of the element.
   * \param[in] config - Definition of the particular problem.
   */
  virtual void SetNodes_Coord(su2double *val_coord_Edge_CG, su2double *val_coord_Elem_CG) = 0;

  /*!
   * \brief A pure virtual member.
   * \param[out] val_normal - Coordinates of the normal.
   */
  virtual void GetNormal(su2double *val_normal) const = 0;

  /*!
   * \brief A pure virtual member.
   */
  virtual su2double *GetNormal(void) = 0;

  /*!
   * \brief A pure virtual member.
   * \param[in] val_face_normal - Coordinates of the normal.
   */
  virtual void SetNormal(const su2double *val_face_normal) = 0;

  /*!
   * \brief A pure virtual member.
   */
  virtual unsigned short GetnNodes(void) const = 0;

  /*!
   * \brief A pure virtual member.
   */
  virtual void SetZeroValues(void) = 0;

  /*!
   * \brief A pure virtual member.
   * \param[in] val_face_normal - Normal vector to be added.
   */
  virtual void AddNormal(const su2double *val_face_normal) = 0;

  /*!
   * \brief A pure virtual member.
   */
  virtual su2double GetPartialVolume(unsigned short val_Point) const = 0;

  /*!
   * \brief A pure virtual member.
   */
  virtual void AddPartialVolume(su2double val_Volume, unsigned short val_Point) = 0;

  /*!
   * \brief A pure virtual member.
   */
  virtual void SetPartialVolume(su2double val_Volume, unsigned short val_Point) = 0;
};
