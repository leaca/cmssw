#ifndef Framework_InputSourceFactory_h
#define Framework_InputSourceFactory_h

#include "FWCore/PluginManager/interface/PluginFactory.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/InputSourceDescription.h"
#include "FWCore/Framework/interface/InputSource.h"

#include <string>
#include <memory>

namespace edm {

  typedef InputSource* (ISFunc)(ParameterSet const&, InputSourceDescription const&);

  typedef edmplugin::PluginFactory<ISFunc> InputSourcePluginFactory;

    class InputSourceFactory 
  {
  public:
    ~InputSourceFactory();

    static InputSourceFactory* get();

    std::auto_ptr<InputSource>
      makeInputSource(ParameterSet const&,
		       InputSourceDescription const&) const;
    

  private:
    InputSourceFactory();
    static InputSourceFactory singleInstance_;
  };

}
#endif
