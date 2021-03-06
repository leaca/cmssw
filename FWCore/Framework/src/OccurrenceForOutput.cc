#include "FWCore/Framework/interface/OccurrenceForOutput.h"

#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/Provenance/interface/ProcessHistoryRegistry.h"
#include "FWCore/Common/interface/Provenance.h"
#include "FWCore/Common/interface/TriggerResultsByName.h"
#include "FWCore/Framework/interface/Principal.h"
#include "FWCore/ParameterSet/interface/Registry.h"
#include "FWCore/Utilities/interface/Algorithms.h"
#include "FWCore/Utilities/interface/InputTag.h"

namespace edm {

  OccurrenceForOutput::OccurrenceForOutput(Principal const& p, ModuleDescription const& md, ModuleCallingContext const* moduleCallingContext) :
      provRecorder_(p, md),
      moduleCallingContext_(moduleCallingContext)
  {
  }

  OccurrenceForOutput::~OccurrenceForOutput() {
  }

  void
  OccurrenceForOutput::setConsumer(EDConsumerBase const* iConsumer) {
    provRecorder_.setConsumer(iConsumer);
  }

  Principal const&
  OccurrenceForOutput::principal() const {
    return provRecorder_.principal();
  }

  ProcessHistoryID const&
  OccurrenceForOutput::processHistoryID() const {
    return principal().processHistoryID();
  }

  Provenance
  OccurrenceForOutput::getProvenance(BranchID const& bid) const {
    return provRecorder_.principal().getProvenance(bid, moduleCallingContext_);
  }

  void
  OccurrenceForOutput::getAllProvenance(std::vector<Provenance const*>& provenances) const {
    provRecorder_.principal().getAllProvenance(provenances);
  }

  ProcessHistory const&
  OccurrenceForOutput::processHistory() const {
    return provRecorder_.processHistory();
  }

  size_t
  OccurrenceForOutput::size() const {
    return provRecorder_.principal().size();
  }

  bool
  OccurrenceForOutput::getByToken(EDGetToken token, TypeID const& typeID, BasicHandle& result) const {
    result.clear();
    result = provRecorder_.getByToken_(typeID, PRODUCT_TYPE, token, moduleCallingContext_);
    if (result.failedToGet()) {
      return false;
    }
    if(!provRecorder_.isComplete() && result.wrapper()->isMergeable()) {
      principal_get_adapter_detail::throwOnPrematureRead("RunOrLumi", typeID, token);
    }
    return true;
  }
}

