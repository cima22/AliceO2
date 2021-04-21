// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

/// \file GPUO2InterfaceDisplay.cxx
/// \author David Rohr

#include "GPUParam.h"
#include "GPUDisplay.h"
#include "GPUO2InterfaceConfiguration.h"
#include "GPUO2InterfaceDisplay.h"
#include "GPUDisplayBackend.h"
#include "GPUDisplayBackendGlfw.h"

using namespace o2::gpu;
using namespace o2::tpc;

GPUO2InterfaceDisplay::GPUO2InterfaceDisplay(const GPUO2InterfaceConfiguration* config)
{
  mBackend.reset(new GPUDisplayBackendGlfw);
  //config.configProcessing.eventDisplay = processAttributes->displayBackend.get();
  mParam.reset(new GPUParam);
  mParam->SetDefaults(&config->configGRP, &config->configReconstruction, &config->configProcessing, nullptr);

  //mDisplay.reset(new GPUDisplay(nullptr, &config->configDisplay, mParam.get()));
  mDisplay.reset(new GPUDisplay(mBackend.get(), nullptr, nullptr));
}

GPUO2InterfaceDisplay::~GPUO2InterfaceDisplay() = default;

int GPUO2InterfaceDisplay::startDisplay()
{
  return mDisplay->StartDisplay();
}

int GPUO2InterfaceDisplay::show()
{
  mDisplay->ShowNextEvent();
  do {
    usleep(10000);
  } while (mBackend->mDisplayControl == 0);
  mDisplay->WaitForNextEvent();
  return 0;
}

int GPUO2InterfaceDisplay::endDisplay()
{
  mBackend->DisplayExit();
  return 0;
}
