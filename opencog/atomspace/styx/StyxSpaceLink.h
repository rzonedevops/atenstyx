/*
 * StyxSpaceLink.h
 *
 * Styx Space Link - represents distributed AtomSpace connections
 * Part of the ATenStyx neuro-symbolic cognitive fabric
 *
 * Copyright (C) 2026 OpenCog Foundation
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */

#ifndef _OPENCOG_STYX_SPACE_LINK_H
#define _OPENCOG_STYX_SPACE_LINK_H

#include <opencog/atoms/base/Link.h>

namespace opencog
{
/** \addtogroup grp_atomspace
 *  @{
 */

/**
 * The StyxSpaceLink represents a connection to a distributed AtomSpace
 * via the Styx/9P protocol. It links a StyxNode endpoint to atoms that
 * should be accessed remotely.
 *
 * Example:
 *   (StyxSpaceLink
 *     (StyxNode "tcp://remote:564")
 *     (Concept "distributed_knowledge"))
 */
class StyxSpaceLink : public Link
{
public:
	StyxSpaceLink(const HandleSeq& oset, Type t = STYX_SPACE_LINK)
		: Link(oset, t)
	{
		if (not nameserver().isA(t, STYX_SPACE_LINK))
			throw InvalidParamException(TRACE_INFO,
				"Expecting a StyxSpaceLink");
	}

	StyxSpaceLink(const Handle& endpoint, const Handle& atom)
		: Link({endpoint, atom}, STYX_SPACE_LINK)
	{}

	static Handle factory(const Handle& h)
	{
		return createStyxSpaceLink(h->getOutgoingSet(), h->get_type());
	}
};

typedef std::shared_ptr<StyxSpaceLink> StyxSpaceLinkPtr;
static inline StyxSpaceLinkPtr StyxSpaceLinkCast(const Handle& h)
	{ return std::dynamic_pointer_cast<StyxSpaceLink>(h); }
static inline StyxSpaceLinkPtr StyxSpaceLinkCast(AtomPtr a)
	{ return std::dynamic_pointer_cast<StyxSpaceLink>(a); }

#define createStyxSpaceLink std::make_shared<StyxSpaceLink>

/** @}*/
}

#endif // _OPENCOG_STYX_SPACE_LINK_H
