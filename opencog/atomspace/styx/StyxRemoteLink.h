/*
 * StyxRemoteLink.h
 *
 * Styx Remote Link - remote atom access via Styx protocol
 * Part of the ATenStyx neuro-symbolic cognitive fabric
 *
 * Copyright (C) 2026 OpenCog Foundation
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */

#ifndef _OPENCOG_STYX_REMOTE_LINK_H
#define _OPENCOG_STYX_REMOTE_LINK_H

#include <opencog/atoms/core/FunctionLink.h>

namespace opencog
{
/** \addtogroup grp_atomspace
 *  @{
 */

/**
 * The StyxRemoteLink represents a remote atom access operation
 * via the Styx/9P protocol. It enables transparent querying and
 * execution of atoms on remote AtomSpaces.
 *
 * Example:
 *   (StyxRemoteLink
 *     (StyxNode "tcp://remote:564")
 *     (Get (Variable "$x")
 *          (Evaluation (Predicate "query") (Variable "$x"))))
 */
class StyxRemoteLink : public FunctionLink
{
protected:
	void init(void);

public:
	StyxRemoteLink(const HandleSeq&, Type = STYX_REMOTE_LINK);
	StyxRemoteLink(const Handle& endpoint, const Handle& query);
	StyxRemoteLink(const Link&);

	static Handle factory(const Handle&);

	// Execute the remote operation
	virtual ValuePtr execute(AtomSpace*, bool silent=false);
};

typedef std::shared_ptr<StyxRemoteLink> StyxRemoteLinkPtr;
static inline StyxRemoteLinkPtr StyxRemoteLinkCast(const Handle& h)
	{ return std::dynamic_pointer_cast<StyxRemoteLink>(h); }
static inline StyxRemoteLinkPtr StyxRemoteLinkCast(AtomPtr a)
	{ return std::dynamic_pointer_cast<StyxRemoteLink>(a); }

#define createStyxRemoteLink std::make_shared<StyxRemoteLink>

/** @}*/
}

#endif // _OPENCOG_STYX_REMOTE_LINK_H
