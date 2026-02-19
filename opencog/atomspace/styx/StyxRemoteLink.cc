/*
 * StyxRemoteLink.cc
 *
 * Styx Remote Link implementation
 * Part of the ATenStyx neuro-symbolic cognitive fabric
 *
 * Copyright (C) 2026 OpenCog Foundation
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */

#include <opencog/atoms/atom_types/atom_types.h>
#include <opencog/atoms/base/Node.h>
#include <opencog/atoms/value/LinkValue.h>
#include "StyxRemoteLink.h"

using namespace opencog;

void StyxRemoteLink::init(void)
{
	Type t = get_type();
	if (not nameserver().isA(t, STYX_REMOTE_LINK))
		throw InvalidParamException(TRACE_INFO,
			"Expecting a StyxRemoteLink");

	FunctionLink::init();
}

StyxRemoteLink::StyxRemoteLink(const HandleSeq& oset, Type t)
	: FunctionLink(oset, t)
{
	init();
}

StyxRemoteLink::StyxRemoteLink(const Handle& endpoint, const Handle& query)
	: FunctionLink({endpoint, query}, STYX_REMOTE_LINK)
{
	init();
}

StyxRemoteLink::StyxRemoteLink(const Link& l)
	: FunctionLink(l)
{
	init();
}

Handle StyxRemoteLink::factory(const Handle& h)
{
	return createStyxRemoteLink(h->getOutgoingSet(), h->get_type());
}

/**
 * Execute a remote operation via Styx protocol.
 *
 * This is a placeholder implementation that demonstrates the
 * distributed space integration concept. In a full implementation,
 * this would:
 * 1. Parse the endpoint from the first atom
 * 2. Establish a Styx/9P connection
 * 3. Marshal the query/operation to the remote atomspace
 * 4. Execute the operation remotely
 * 5. Unmarshal and return the results
 *
 * For now, it returns a LinkValue containing the operation,
 * demonstrating the symbolic structure for distributed access.
 */
ValuePtr StyxRemoteLink::execute(AtomSpace* as, bool silent)
{
	const HandleSeq& oset = getOutgoingSet();
	if (oset.size() < 2)
		throw InvalidParamException(TRACE_INFO,
			"StyxRemoteLink requires endpoint and operation");

	// In a full implementation, we would:
	// 1. Extract endpoint URI from oset[0]
	// 2. Connect via Styx/9P protocol
	// 3. Marshal query/operation
	// 4. Execute remotely
	// 5. Return results
	//
	// For now, return the symbolic structure as a LinkValue
	// to demonstrate the distributed access concept
	return createLinkValue(oset);
}

DEFINE_LINK_FACTORY(StyxRemoteLink, STYX_REMOTE_LINK)
