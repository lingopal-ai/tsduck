//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2023, Thierry Lelegard
// BSD-2-Clause license, see LICENSE.txt file or https://tsduck.io/license
//
//----------------------------------------------------------------------------
//!
//!  @file
//!  HTTP input plugin for tsp.
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsAbstractHTTPInputPlugin.h"

namespace ts {
    //!
    //! HTTP input plugin for tsp.
    //! @ingroup plugin
    //!
    //!
    class TSDUCKDLL HTTPInputPlugin: public AbstractHTTPInputPlugin
    {
        TS_NOBUILD_NOCOPY(HTTPInputPlugin);
    public:
        //!
        //! Constructor.
        //! @param [in] tsp Associated callback to @c tsp executable.
        //!
        HTTPInputPlugin(TSP* tsp);

        // Implementation of plugin API
        virtual bool getOptions() override;
        virtual bool start() override;

    protected:
        // Implementation of AbstractHTTPInputPlugin
        virtual bool openURL(WebRequest&) override;

    private:
        // Command line options:
        size_t      _repeat_count;
        bool        _ignore_errors;
        MilliSecond _reconnect_delay;
        UString     _url;

        // Working data:
        size_t _transfer_count;
    };
}
