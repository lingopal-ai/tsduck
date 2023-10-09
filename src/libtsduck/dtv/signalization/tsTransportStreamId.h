//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2023, Thierry Lelegard
// BSD-2-Clause license, see LICENSE.txt file or https://tsduck.io/license
//
//----------------------------------------------------------------------------
//!
//!  @file
//!  Full identification of a DVB transport stream.
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsStringifyInterface.h"

namespace ts {
    //!
    //! Full identification of a DVB transport stream.
    //! @ingroup mpeg
    //!
    class TSDUCKDLL TransportStreamId: public StringifyInterface
    {
    public:
        // Public members:
        uint16_t transport_stream_id;  //!< Transport stream id.
        uint16_t original_network_id;  //!< Original network id.

        //!
        //! Constructor.
        //! @param [in] tsid Transport stream id.
        //! @param [in] onid Original network id.
        //!
        TransportStreamId(uint16_t tsid = 0, uint16_t onid = 0);

        //!
        //! Clear the content of this object.
        //!
        virtual void clear();

        //!
        //! Get a "normalized" 32-bit identifier.
        //! The upper 16-bit contain the original network id.
        //! The lower 16-bit contain the TS id.
        //! @return The "normalized" 32-bit identifier of the TS.
        //!
        uint32_t normalized() const
        {
            return uint32_t(transport_stream_id) | (uint32_t(original_network_id) << 16);
        }

        //!
        //! Comparison operator.
        //! @param [in] tsid Another instance to compare.
        //! @return True if this object == @a tsid.
        //!
        bool operator==(const TransportStreamId& tsid) const
        {
            return transport_stream_id == tsid.transport_stream_id && original_network_id == tsid.original_network_id;
        }

#if defined(TS_NEED_UNEQUAL_OPERATOR)
        //!
        //! Comparison operator.
        //! @param [in] tsid Another instance to compare.
        //! @return True if this object != @a tsid.
        //!
        bool operator!=(const TransportStreamId& tsid) const
        {
            return transport_stream_id != tsid.transport_stream_id || original_network_id != tsid.original_network_id;
        }
#endif

        //!
        //! Comparison operator.
        //! @param [in] tsid Another instance to compare.
        //! @return True if this object < @a tsid.
        //!
        bool operator<(const TransportStreamId& tsid) const
        {
            return normalized() < tsid.normalized();
        }

        //!
        //! Comparison operator.
        //! @param [in] tsid Another instance to compare.
        //! @return True if this object <= @a tsid.
        //!
        bool operator<=(const TransportStreamId& tsid) const
        {
            return normalized() <= tsid.normalized();
        }

        //!
        //! Comparison operator.
        //! @param [in] tsid Another instance to compare.
        //! @return True if this object > @a tsid.
        //!
        bool operator>(const TransportStreamId& tsid) const
        {
            return normalized() > tsid.normalized();
        }

        //!
        //! Comparison operator.
        //! @param [in] tsid Another instance to compare.
        //! @return True if this object >= @a tsid.
        //!
        bool operator>=(const TransportStreamId& tsid) const
        {
            return normalized() >= tsid.normalized();
        }

        // Implementation of StringifyInterface.
        virtual UString toString() const override;
    };

    // Containers:
    typedef std::set<TransportStreamId> TransportStreamIdSet;        //!< Set of TransportStreamId.
    typedef std::vector<TransportStreamId> TransportStreamIdVector;  //!< Vector of TransportStreamId.
}
