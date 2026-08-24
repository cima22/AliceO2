// Copyright 2019-2026 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

/// \file LineProjection.h
/// \brief small types shared by the host and device seeding vertexers, describing lines
///        projected onto the beam line: their time interval and their z-window bounds.

#ifndef O2_ITS_TRACKING_LINE_PROJECTION_H_
#define O2_ITS_TRACKING_LINE_PROJECTION_H_

namespace o2::its
{

// Symmetrised time interval of a line: centre +/- half-width.
struct LineTime {
  float tc{0.f}; // time centre
  float th{0.f}; // time half-width
};

// Half-open [lo, hi) range of sorted-line slots falling inside one z-window.
struct LineWindow {
  int lo{0};
  int hi{0};
};

} // namespace o2::its

#endif
